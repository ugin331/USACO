#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int numRectangles;
int optimalCoats;
int maxX = 0;
int maxY = 0;
vector<int> tempVec(1001, 0);
vector<vector<int>> barnsurface(1001, tempVec);

void input(){
    cin >> numRectangles >> optimalCoats;
    for(int i = 0; i < numRectangles; i++){
	int x1, y1;
   	int x2, y2;
	maxX = max(maxX, x2);
  	maxY = max(maxY, y2);
  	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = x1; i < x2; i++){
	    for(int j = y1; j < y2; j++){
	   	barnsurface[i][j]++;
	    }
    	}
    }
}

int main(){
    input();
    int counter = 0;
    for(int i = 0; i < maxX; i++){
	for(int j = 0; j < maxY; j++){
	    if(barnsurface[i][j] == optimalCoats){
		counter++;
	    }
 	}
    }
    cout << counter << endl;
}
