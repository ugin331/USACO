#include <iostream>
#include <queue>

using namespace std;

//code in here is the only thing that should be submitted
void solve(){
int numRC;
cin >> numRC;
vector<int> temp(numRC, 0);
vector<vector<int>> farmMap(numRC, temp);
for(int i = 0; i < numRC; i++){
    for(int j = 0; j < numRC; j++){
        char tempchar;
        cin >> tempchar;
        if(tempchar == '*'){
            farmMap[i][j] = 1;
        }
    }
}
#if 0
for(int i = 0; i < numRC; i++){
    for(int j = 0; j < numRC; j++){
        cout << farmMap[i][j];
    }
    cout << endl;
}
#endif
int lakeGroup = 2;
int maxS = 0;
for(int i = 0; i < numRC; i++){
    for(int j = 0; j < numRC; j++){
        if(farmMap[i][j] != 1)
            continue;
        queue<pair<int, int>> workList;
        int LakeSize = 0;
        workList.push(make_pair(i, j));
        while(!workList.empty()){
            pair<int, int> a = workList.front();
            int Row = a.first;
            int Col = a.second;
            workList.pop();
            if(farmMap[Row][Col] > 1){
                continue;
            }
            LakeSize++;
            farmMap[Row][Col] = lakeGroup;
            //check OoB up
            if(Row > 0){
                if(farmMap[Row-1][Col] == 1)
                    workList.push(make_pair(Row-1, Col));
            }
            if(Row < numRC-1){
                if(farmMap[Row+1][Col] == 1)
                    workList.push(make_pair(Row+1, Col));
            }
            if(Col > 0){
                if(farmMap[Row][Col-1] == 1)
                    workList.push(make_pair(Row, Col-1));
            }
	    if(Col < numRC-1){
                if(farmMap[Row][Col+1] == 1)
                    workList.push(make_pair(Row, Col+1));
            }
        }
        lakeGroup++;
    }
}
    cout << lakeGroup-2 << endl;
}

int main(){
    solve();
}
