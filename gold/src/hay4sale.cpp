#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int capacity;
int numBales;
int results[50001];
int temp_results[50001];
int bales[5001];

void input(){
    cin >> capacity >> numBales;
    int temp;
    for(int i = 0; i < numBales; i++){
        cin >> temp;
        bales[i] = temp;
    }
}

int main(){
    input();
    results[0] = 0;
    //iterative knapsack dp
    for(int i = 0; i < numBales; i++){
        for(int j = bales[i]; j <=capacity; j++){
            temp_results[j] = max(results[j], results[j-bales[i]]+bales[i]);
        }
        for(int j = bales[i]; j <=capacity; j++){
            results[j] = temp_results[j];
        }
    }
    cout << results[capacity] << endl;
}
