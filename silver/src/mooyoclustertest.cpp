#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int gridHeight;
int minDeleteAmount;
int grid[11][101];

int groupNum[11][101];
set<int> toBeDeleted;

void setGrid(int i, int j, int val){
    grid[j][i] = val;
}

void input(){
    cin >> gridHeight >> minDeleteAmount;
    for(int i = 0; i < gridHeight; i++){
	for(int j = 0; j < 10; j++){
	    char temp;
	    cin >> temp;
	    setGrid(i, j, (int)temp-'0');
  	}
    }
}

int getGrid(int i, int j){
    return grid[j][i];
}

int getGroup(int i, int j){
    return groupNum[j][i];
}
  
void setGroup(int i, int j, int val){
    groupNum[j][i] = val;
}

vector<pair<int, int>> getChildren(int row, int col){
    vector<pair<int, int>> children;
    if(row > 0){
	if(getGrid(row, col) == getGrid(row-1, col)){
	    children.push_back(make_pair(row-1, col));
	}
    }
    if(row < gridHeight-1){
	if(getGrid(row, col) == getGrid(row+1, col)){
	    children.push_back(make_pair(row+1, col));
	}
    }
    if(col > 0){
	if(getGrid(row, col) == getGrid(row, col-1)){
	    children.push_back(make_pair(row, col-1));
	}
    }
    if(col < 9){
	if(getGrid(row, col) == getGrid(row, col+1)){
	    children.push_back(make_pair(row, col+1));
	}
    }
    return children;
}

void cluster(){
    int groupID = 1;
    for(int i = 0; i < gridHeight; i++){
	for(int j = 0; j < 10; j++){
	    if(getGrid(i, j) == 0 || getGroup(i, j) != -1){
		continue;
	    }
 	    int groupSize = 0;
	    queue<pair<int, int>> workList;
	    workList.push(make_pair(i, j));
	    while(!workList.empty()){
		pair<int, int> a = workList.front();
		int row = a.first;
		int col = a.second;
		workList.pop();
		setGroup(row, col, groupID);
		groupSize++;
                auto children = getChildren(row, col);
		for(auto c:children){
		    if(getGroup(c.first, c.second) != -1){
			continue;
		    }
		    workList.push(c);
		    //setGroup(c.first, c.second, groupID);
		}
	    }
	    if(groupSize >= minDeleteAmount){
		toBeDeleted.insert(groupID);
	    }
	    groupID++;
  	}
    }
}

bool deleteItems(){
    bool changed = false;
    for(int i = 0; i < gridHeight; i++){
	for(int j = 0; j < 10; j++){
	    if(toBeDeleted.find(getGroup(i, j)) != toBeDeleted.end()){
		setGrid(i, j, 0);
		changed = true;
	    }
  	}
    }
    toBeDeleted.clear();
    return changed;
}

void dropper(int column[], int length){
    int destinationIndex = length-1;
    for(int i = length-1; i >= 0; i--){
        if(column[i] == 0){
            continue;
        }
        if(i == destinationIndex){
            destinationIndex--;
            continue;
        }
        column[destinationIndex] = column[i];
        column[i] = 0;
        destinationIndex--;
    }
}

void printGrid(){
    for(int i = 0; i < gridHeight; i++){
	for(int j = 0; j < 10; j++){
	    cout << getGrid(i, j) << " ";
   	}
  	cout << endl;
    }
    cout << endl;
}

void printGroup(){
    for(int i = 0; i < gridHeight; i++){
	for(int j = 0; j < 10; j++){
	    printf("%4d ", getGroup(i, j));
   	}
	printf("\n");
    }
    printf("\n");
}

void resetGroup(){
    for(int j = 0; j < 10; j++){
	for(int i = 0; i < gridHeight; i++){
	    setGroup(i, j, -1);
 	}
    }
}

int main(){
    input();
    resetGroup();
    while(true){
    	cluster();
    	if(!deleteItems()){
	    break;
	}
    	for(int j = 0; j < 10; j++){
	    dropper(grid[j], gridHeight);
    	}
  	resetGroup();
    }
    printGrid();
}
