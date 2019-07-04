#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numMerlons;
//price per unit to make it larger or smaller
int makeLarger;
int makeSmaller;
vector <int> merlonInfo;
vector <int> changeHeight;

//custom sorter for the info part



void input(){
    cin >> numMerlons;
    //merlonInfo.reserve(numMerlons);
    //changeHeight.reserve(numMerlons);
    cin >> makeLarger >> makeSmaller;
    int merlonHeight;
    int changeNum;
    for(int i = 0; i < numMerlons; i++){
        cin >> merlonHeight;
        //merlonInfo[i] = merlonHeight;
        merlonInfo.push_back(merlonHeight);
        cin >> changeNum;
        //changeHeight[i] = changeNum;
        changeHeight.push_back(changeNum);
    }
    sort(changeHeight.begin(), changeHeight.end());
    sort(merlonInfo.begin(), merlonInfo.end());
}

int main(){
    int totalCost = 0;
    input();
    //tentative solution: basically just order them from smallest to largest, calc differences, then add??
    //should work, solution size possibly too large??
    for(int i = 0; i < numMerlons; i++){
        if(merlonInfo[i] == changeHeight[i]){
            continue;
        }
        else if(merlonInfo[i] < changeHeight[i]){
            //use the make it larger cost
            int heightDistance = changeHeight[i] - merlonInfo[i];
            totalCost += heightDistance*makeLarger;
        }
        else{
            //use the make it smaller cost
            int heightDistance = merlonInfo[i] - changeHeight[i];
            totalCost += heightDistance*makeSmaller;
        }
    }
    cout << totalCost << endl;
}
