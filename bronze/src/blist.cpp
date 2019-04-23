#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int numCows;
struct cow{
    int cownum;
    int startTime;
    int endTime;
    int bucketsNeeded;
    cow(int c, int s, int e, int b) : cownum(c), startTime(s), endTime(e), bucketsNeeded(b) {}
};

struct CowTimeComp{
    bool operator() (const cow &a, const cow &b){
        return((a.startTime < b.startTime) || (a.startTime == b.startTime) && (a.endTime < b.endTime));
    }
};

vector<cow> cowList{};

int input(){
    fstream input;
    input.open("blist.in");
    input >> numCows;
    for(int i = 0; i < numCows; i++){
	int start, end, bucketsNeeded;
   	input >> start >> end >> bucketsNeeded;
	cow tempCow(i, start, end, bucketsNeeded);
	cowList.push_back(tempCow);
    }
    sort(cowList.begin(), cowList.end(), CowTimeComp());
}

int main(){
    input();
    #if 0
    for(int i = 0; i < numCows; i++){
	cout << "cow number: " << cowList[i].cownum << endl;
	cout << "Start Time: " << cowList[i].startTime << endl;
 	cout << "End Time: " << cowList[i].endTime << endl;
	cout << "buckets Needed: " << cowList[i].bucketsNeeded << endl;
    }
    #endif
    int cowsProc = 0;
    int bucketsUsedCurrently = 0;
    int maxBuckets = 0;
    int totalEnd = cowList[numCows-1].endTime;
    vector<int> numBuckets(totalEnd, 0);
    for(int i = 0; i <= numCows; i++){
  	bucketsUsedCurrently = cowList[i].bucketsNeeded;
	int thisStart = cowList[i].startTime-1;
	int thisEnd = cowList[i].endTime-1;
	for(int j = thisStart; j < thisEnd; j++){
	    numBuckets[j]+= bucketsUsedCurrently;
	}
    }
    for(auto &E: numBuckets){
	if(E > maxBuckets){
	    maxBuckets = E;
	}
    }
    ofstream myfile;
    myfile.open ("blist.out");
    myfile << maxBuckets;
    myfile.close();
}
