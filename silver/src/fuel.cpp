#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numStations;
int tankSize;
int fuelAmount;
int totalDistance;

int amountPaid = 0;

struct FuelStation{
    int distance;
    int price;
    int cheapestBeyond;
};

FuelStation stations[50001];

void input(){
    cin >> numStations >> tankSize >> fuelAmount >> totalDistance;
    for(int i = 0; i < numStations; i++){
	int distance, price;
	cin >> distance >> price;
	FuelStation newStation;
	newStation.distance = distance;
	newStation.price = price;
	stations[i] = newStation;
    }
}

void ClosestCheapestBeyond(){
    //there are none beyond that are cheaper, so the cheapest is itself
    stations[numStations-1].cheapestBeyond = numStations-1;
    for(int i = numStations-2; i >= 0; i--){
	int cheaperStation = i+1;
	while(cheaperStation < numStations && stations[i].price <= stations[cheaperStation].price){
	    cheaperStation = stations[cheaperStation].cheapestBeyond; //keep hopping
	}
	if(cheaperStation >= numStations){
	    stations[i].cheapestBeyond = i;
	}
	else{
	    stations[i].cheapestBeyond = cheaperStation;
	}
    }
}

int main(){
    input();
    ClosestCheapestBeyond();
    //basic logic:
    //if enough to reach destination, do it.
    //if not enough to reach next station, then the following:
    //if cheaper is unreachable and/or current station is the cheapest, then fill as much as possible
    //if not, then fill as much as is needed to get to the cheapest station
    //if can reach next station keep going
    for(int i = 0; i < numStations; i++){
	FuelStation tempStation = stations[i];
	//subtract Fuel necessary to reach station
	fuelAmount -= tempStation.distance;
	if(fuelAmount >= totalDistance-tempStation.distance){
	    //if enough fuel to reach end from current station;
	    return amountPaid;
	}
	//if last station and needs tank filling before end is reached
	if(tankSize >= totalDistance-tempStation.distance && fuelAmount < totalDistance-tempStation.distance && i == numStations-1){
	    int amountToFill = (totalDistance-tempStation.distance)-fuelAmount;
	    fuelAmount = totalDistance-tempStation.distance;
	    amountPaid += amountToFill*tempStation.price;
	    return amountPaid;
	}
	//if next station is unreachable
	if(tankSize < stations[i+1].distance-tempStation.distance){
	    return -1;
	}
	//current station is cheapest in area, fuel to max
	if(tempStation.cheapestBeyond = i){
	    int amountFilled = tankSize - fuelAmount;
	    fuelAmount = tankSize;
	    amountPaid += amountFilled*tempStation.price;
	}
	//current station is not the cheapest in the area
	else{
	    int distanceToCheapest = stations[tempStation.cheapestBeyond].distance;
	    //if the cheapest along the route is reachable:
	    if(distanceToCheapest <= tankSize){
		//if no fuel needs to be added
		if(distanceToCheapest < fuelAmount){
		    //set current station to that one (minus one because of the ++)
		    i = tempStation.cheapestBeyond-1;
		}
		//if fuel needs to be added
		else{
		    int amountToFill = distanceToCheapest - fuelAmount;
		    fuelAmount = distanceToCheapest;
		    amountPaid += amountToFill*tempStation.price;
		    //set current station to that one (minus one because of the ++)
		    i = tempStation.cheapestBeyond-1;
		}
	    }
	    //if next cheapest is not reachable
	    else{
		//max out tank
		int amountToFill = tankSize - fuelAmount;
		fuelAmount = tankSize;
		amountPaid += amountToFill*tempStation.price;
	    }
	}
    }
}
