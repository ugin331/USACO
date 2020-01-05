#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>

using namespace std;

int numCows;
struct Cow{
    int Seniority; //lower senority the better
    int arrivalTime;
    int timeSpent;
};

struct Event{
    int eventType; //0 = arrival, 1 = start, 2 = end
    int time;
    int associatedCow;
};

struct EventComp{
    bool operator() (const Event &a, const Event &b){
        if(a.time > b.time){
            return true;
        }
        if(a.time < b.time){
            return false;
        }
        return (a.eventType > b.eventType);
    }
};

struct TimeComp{
    bool operator() (const Cow &a, const Cow &b){
	return (a.arrivalTime < b.arrivalTime);
    }
};

struct SeniorityComp{
    bool operator() (const Cow &a, const Cow &b){
	return (a.Seniority > b.Seniority);
    }
};

Cow cowList[100001];

void input(){
    cin >> numCows;
    for(int i = 0; i < numCows; i++){
	int startTime;
	int timeSpent;
	cin >> startTime >> timeSpent;
	Cow tempCow;
	tempCow.Seniority = i;
	tempCow.arrivalTime = startTime;
	tempCow.timeSpent = timeSpent;
	cowList[i] = tempCow;
    }
    sort(cowList, cowList+numCows, TimeComp());
}

int main(){
    input();
    typedef priority_queue<Event, vector<Event>, EventComp> eventQueue;
    typedef priority_queue<Cow, vector<Cow>, SeniorityComp> cowQueue;
    eventQueue events;
    cowQueue waitingList;
    //populate events
    for(int i = 0; i < numCows; i++){
	Event tempEvent;
	tempEvent.eventType = 0;
	tempEvent.time = cowList[i].arrivalTime;
	tempEvent.associatedCow = i;
 	events.push(tempEvent);
    }
    //bool to tell if cow is currently grazing
    bool cowGrazing = false;
    int waitingTime = 0;
    while(!events.empty()){
	Event currentEvent = events.top();
	events.pop();
	Cow currentCow = cowList[currentEvent.associatedCow];
	if(currentEvent.eventType == 0){
	    //cout << "cow arriving" << endl;
 	    //cout << "cow number: " << currentCow.Seniority+1 << endl;
	    //cout << endl;
	    if(!cowGrazing){
		cowGrazing = true;
		Event cowLeaving;
		cowLeaving.eventType = 2;
		cowLeaving.associatedCow = currentEvent.associatedCow;
		cowLeaving.time = currentCow.timeSpent + currentEvent.time;
		//cout << "cow " << currentCow.Seniority+1 << " is now grazing" << endl;
		//cout << endl;
		events.push(cowLeaving);
	    }
	    else{
		waitingList.push(currentCow);
	    }
	}
	else{
	    //cout << "cow Leaving" << endl;
	    //cout << "cow number: " << currentCow.Seniority+1 << endl;
	    //cout << endl;
	    if(!waitingList.empty()){
		Cow firstCow = waitingList.top();
		waitingList.pop();
		waitingTime = max(waitingTime, (currentEvent.time - firstCow.arrivalTime));
		Event cowLeaving;
		cowLeaving.eventType = 2;
		cowLeaving.associatedCow = firstCow.Seniority;
		cowLeaving.time = firstCow.timeSpent + currentEvent.time;
		//cout << "from waiting list" << endl;
		//cout << "cow " << firstCow.Seniority+1 << " is now grazing" << endl;
		//cout << "cow will leave at: " << cowLeaving.time << endl;
		//cout << endl;
		events.push(cowLeaving);
	    }
	    else{
		cowGrazing = false;
	    }
	}
    }
    cout << waitingTime << endl;
}
