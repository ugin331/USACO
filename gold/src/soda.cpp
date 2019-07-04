#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numIntervals;

struct Point{
    int value;
    bool startend;
};

struct PointComp{
    bool operator()(const Point &a, const Point &b){
	if(a.value < b.value){
	    return true;
	}
	return false;
    }
};

vector <Point> points;

void input(){
    cin >> numIntervals;
    int start, end;
    for(int i = 0; i < numIntervals; i++){
	cin >> start >> end;
	//create point objects
	Point point1;
	point1.value = start;
	point1.startend = true;
	Point point2;
	point2.value = end+1;
	point2.startend = false;
	//push back
	points.push_back(point1);
	points.push_back(point2);
    }
}

int main(){
    input();
    sort(points.begin(), points.end(), [](const Point &a, const Point &b){ return a.value < b.value; });
    int overlaps = 0;
    int max = 0;
    int len = points.size();
    for(int i = 0; i < len; i++){
	if(points[i].startend){
	    overlaps++;
	}
	else{
	    overlaps--;
	}
	cout << "overlaps: " << overlaps << endl;
	if(overlaps > max){
	    max = overlaps;
	}
    }
    cout << max << endl;
}
