#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numPlots;
int neighbors[100001];

void input(){
    cin >> numPlots;
    int temp1;
    int temp2;
    for(int i = 0; i < numPlots; i++){
	neighbors[i]=0;
    }
    //determine number of neighbors for each
    for(int i = 0; i < numPlots-1; i++){
	cin >> temp1 >> temp2;
	neighbors[temp1-1]++;
	neighbors[temp2-1]++;
    }
}

//for node with n neighbors, n+1 grasses will be needed overall to ensure they are distinct (???)
//so therefore we just find max neighbors??
//ok then

int main(){
    input();
    //maximum num
    int max = 0;
    for(int i = 0; i < numPlots; i++){
	if(neighbors[i] > max){
	    max = neighbors[i];
	}
    }
    cout << max+1 << endl;
}
