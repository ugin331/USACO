nclude <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long results[40][39*19+1];

long dp(int thing, long sum){
    if(results[thing][sum] != -1){
        return results[thing][sum];
    }
    if(sum < 0){
        return 0;
    }
    if(sum <= 1 || sum == thing*(thing+1)/2){
        results[thing][sum] = 1;
        return 1;
    }
    if(thing == 0){
        results[0][sum] = 0;
        return 0;
    }
    if(thing*(thing+1)/2 < sum){
        results[thing][sum] = 0;
        return 0;
    }
    long r1 = dp(thing-1, sum);
    long r2 = dp(thing-1, sum-x);
    long r = r1 + r2;
    results[thing][sum] = r;
    return r;
}

int main(){
    cin >> N;
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 39*19+1; j++){
            results[i][j] = -1;
        }
    }
    long sum = N*(N+1)/2;
    long r = dp(N, sum/2)/2;
    cout << N << endl;
    cout << sum << endl;
    cout << r << endl;
}
