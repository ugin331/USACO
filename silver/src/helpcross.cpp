#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int pos;
    int startEnd; //0 = start, 1 = end, -1 = chicken
    int seqNum;
};

int numCows;
int numChickens;
Point Line[60001];
pair<int, int> pairs[10001];
bool used[10001];
vector<Point> points;

void input(){
    cin >> numChickens >> numCows;
    //input chickens
    for(int i = 0; i < numChickens; i++){
	Point newPoint;
 	int temp;
	cin >> temp;
	newPoint.pos = temp;
	newPoint.startEnd = -1;
	newPoint.seqNum = -1;
	points.push_back(newPoint);
    }
    //input cows
    for(int i = 0; i < numCows; i++){
	int temp1, temp2;
	cin >> temp1 >> temp2;
	Point startPoint;
	Point endPoint;
	startPoint.pos = temp1;
	endPoint.pos = temp2;
	startPoint.startEnd = 0;
	endPoint.startEnd = 1;
	startPoint.seqNum = i;
	endPoint.seqNum = i;

	pairs[i] = make_pair(temp1, temp2);
	points.push_back(startPoint);
	points.push_back(endPoint);
    }
}

int locateVectorPos(vector <int> &active, int target){
    int size = active.size();
    for(int i = 0; i < size; i++){
	if(active[i] == target){
	    return i;
	}
    }
    return 0;
}

int main(){
    int totalCounter = 0;

    input();
    //sort the array, so that it's by pos value, and chickens go before endpoints.
    sort(points.begin(), points.end(), [](Point a, Point b) {
        return a.pos < b.pos || (a.pos == b.pos && a.seqNum < b.seqNum);
    });
   
    //start queue
    vector<int> active;
    int len = points.size();
    for(int i = 0; i < len; i++){
	//if used already then skip
	if(used[points[i].seqNum]){
	    continue;
	}

	//if start, add the point to the "active sequence queue"
	if(points[i].startEnd == 0){
	    active.push_back(points[i].seqNum);
	    used[points[i].seqNum] = true;
	    cout << "adding new active sequence: " << points[i].seqNum << endl;
	    cout << endl;
  	}
	//if chicken, pair it with the most recently ending sequence in the "active sequence queue"
	else if(points[i].startEnd == -1){
	    if(active.size() == 0){
		continue;
	    }
	    int qsize = active.size();
	    int minEnd = 909090;
	    int shortestSeq = 0;
	    //find the sequence that ends first
	    for(int j = 0; j < qsize; j++){
		int sequenceNum = active[j];
	 	if(pairs[sequenceNum].second < minEnd){
		    shortestSeq = sequenceNum;
		    minEnd = pairs[sequenceNum].second;
		}
	    }
  	    int toBeRemoved = locateVectorPos(active, shortestSeq);
	    cout << "erasing smallest sequence: " << shortestSeq << endl;
	    cout << "position in vector: " << toBeRemoved << endl;
	    cout << "currently active sequences: " << active.size() << endl;
	    cout << endl;
	    active.erase(active.begin()+toBeRemoved);
	    totalCounter++;
	}
	//if end point, just remove from active queue
	else if(points[i].startEnd == 1){
	    int sequenceNum = points[i].seqNum;	    
	    used[sequenceNum] = true;
	    int toBeRemoved = locateVectorPos(active, sequenceNum);
	    cout << "erasing ending sequence: " << sequenceNum << endl;
	    cout << "position in vector: " << toBeRemoved << endl;
	    cout << "currently active sequences: " << active.size() << endl;	
	    cout << endl;
	    active.erase(active.begin()+toBeRemoved);
	}
    }
    cout << totalCounter << endl;
}
