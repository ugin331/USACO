#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int numIslands, startLoc;

int input(vector<vector<int>> &islands){
    cin >> numIslands >> startLoc;
    for(int i = 0; i < numIslands; i++){
        //get island connection here
        vector<int> temprow;
        islands.push_back(temprow);
        for(int j = 0; j < numIslands; j++){
            int Islandconnection;
            cin >> Islandconnection;
            islands[i].push_back(Islandconnection);
        }
    }
}

void getConnection(int island, vector<int> &islandsConnectedTo, vector<vector<int>> &islands){
    islandsConnectedTo.clear();
    for(int i = 0; i < numIslands; i++){
        if(islands[island-1][i] == 1){
            islandsConnectedTo.push_back(i+1);
        }
    }
}

int main(){
    vector<vector<int>> islands;
    input(islands);
    list<int> queue;
    queue.push_back(startLoc);
    vector<int> islandsConnectedTo;
    vector<int> levels(numIslands, -1);
    //get length 2 Islands
    levels[startLoc-1] = 1;
    //cout << startLoc << endl;
    while(!queue.empty()){
        //bool layerelement = false;
        int island = queue.front();
        queue.pop_front();
        getConnection(island, islandsConnectedTo, islands);
        int connected = islandsConnectedTo.size();
        for(int i = 0; i < connected; i++){
            if(levels[islandsConnectedTo[i]-1] != -1){
                continue;
            }
            levels[islandsConnectedTo[i]-1] = levels[island-1] + 1;
            queue.push_back(islandsConnectedTo[i]);
            //layerelement = true;
            //cout << islandsConnectedTo[i] << " ";
        }
        //if(layerelement)
            //cout << endl;
    }
    vector<int> temp(numIslands, 0);
    vector<vector<int>> reverseLevels(numIslands, temp);
    for(int i = 0; i < numIslands; i++){
        if(levels[i] != -1)
            reverseLevels[levels[i]-1].push_back(i);
    }
    for(auto &E: reverseLevels){
        if(E.size() == 0){
            continue;
        }
        for (int i = 0; i < E.size() - 1; i++)
            cout << E[i] << " ";
       cout << E[E.size()-1] << endl;
    }

}
