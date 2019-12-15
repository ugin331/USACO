#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int numPastures;
int claimedGroups;
//unordered_map<pair<int, int>, char> groupMap;
vector<pair<int, int>> pairlist(10001, pair<int,int>(0, 0));

void input(){
    #if 0
	fstream input;
	input.open("revegetate.in");
	input >> numPastures;
  	input >> claimedGroups;
    #endif
 	cin >> numPastures >> claimedGroups;
 	for(int i = 0; i < claimedGroups; i++){
	    char type;
	    int num1;
	    int num2;
	    cin >> type >> num1 >> num2;
	    //groupMap[make_pair<num1, num2>] = type;
	    pairlist[i] = make_pair(min(num1, num2), max(num1, num2));
	}
	sort(pairlist.begin(), pairlist.end());
}

int main(){
    input();
    //current grass part we're looking at
    pair<int, int> currentGroup = pairlist[0];
    int numMissed = 0;
    int totalGroups = 0;
    int size = pairlist.size();
    for(int i = 1; i < pairlist.size(); i++){
	if(pairlist[i].first != currentGoup.second){
	    currentGroup.second = max(currentGroup.second, pairlist[i].second);
	}
  	else{
	    if(pairlist[i].first - currentGroup.second >= 2){
		numMissed += (pairlist[i].first-currentGroup.second);
	    }
	    totalGroups++;
	    currentGroup = pairlist[i];
	}
    }
    cout << 1;
    int j = totalGroups + numMissed;
    for(int i = 0; i < j; i++){
	cout << 0;
    }
    cout << endl;
}
