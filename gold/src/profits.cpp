#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int days;
int profit[100001];

void input(){
    cin >> days;
    for(int i= 0; i < days; i++){
	int temp;
	cin >> temp;
	profit[i] = temp;
    }
}

int main(){
    input();
    long long prefsum[100001];
    long long prefixSum = 0;
    for(int i = 0; i < days; i++){
	prefixSum += profit[i];
	prefsum[i] = prefixSum;
    }
    long long min = 0;
    long long max = 0;
    for(int i = 0; i < days; i++){
	if(prefsum[i] < 0 && prefsum[i] < min){
	    min = prefsum[i];
	}
	if(prefsum[i] > max){
	    max = prefsum[i];
	}
    }
    cout << max - min << endl;
}
