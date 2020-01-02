#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gridSize;
int grid[1000][1000];

void input(){
    cin >> gridSize;
    char tempChar;
    for(int i = 0; i < gridSize; i++){
	for(int j = 0; j < gridSize; j++){
	    cin >> tempChar;
 	    //R is 0, L is 1?
	    if(tempChar == 'R'){
		grid[i][j] = 1;
	    }
	    else{
		grid[i][j] = 0;
	    }
 	}
    }
}

int main(){
    input();
    //flip
    for(int i = 0; i < gridSize; i++){
	if(grid[0][i] == 1){
	    for(int j = 0; j < gridSize; j++){
		if(grid[j][i] == 1){
		    grid[j][i] = 0;
		}
		else if(grid[j][i] == 0){
		    grid[j][i] = 1;
		}
	    }
	}
    }
    for(int i = 0; i < gridSize; i++){
	if(grid[i][0] == 1){
	    for(int j = 0; j < gridSize; j++){
		if(grid[i][j] == 1){
		    grid[i][j] = 0;
		}
	  	else if(grid[i][j] == 0){
		    grid[i][j] = 1;
		}
 	    }
	}
    }
    
    //print thingy
    for(int i = 0; i < gridSize; i++){
	for(int j = 0; j < gridSize; j++){
	    cout << grid[i][j] << " ";
  	}
	cout << endl;
    }

    //identify outlier
    pair<int, int> first_one = {-1, -1};
    pair<int, int> second_one = {-1, -1};
    int totalOnes = 0;
    for(int i = 0; i < gridSize; i++){
	for(int j = 0; j < gridSize; j++){
	    if(grid[i][j] == 1){
		totalOnes++;
		if(first_one.first == -1){
		    first_one.first = i;
		    first_one.second = j;
		}
		else if(second_one.first == -1){
		    second_one.first = i;
		    second_one.second = j;
		}
	    }
	}
    }
    if(totalOnes == 0){
	cout << -1 << endl;
    }
    else if(totalOnes == 1){
	cout << first_one.first+1 << " " << first_one.second+1 << endl;
    }
    else if(totalOnes == (gridSize-1)*(gridSize-1)){
	cout << 1 << " " << 1 << endl;
    }
    else{
	if(first_one.first == second_one.first){
	    cout << first_one.first+1 << " " << 1 << endl;
 	}
	else{
	    cout << 1 << " " << first_one.second+1 << endl;
	}
    }
}
