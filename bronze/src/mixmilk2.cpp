#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//first element is the total bucket capacity
//second element is the amount in it
vector<pair<int, int> > bucketInfo;

int input(){
    fstream input;
    input.open("mixmilk.in");
    
    int cap, startamount;
    for(int i = 0; i < 3; i++){
        input >> cap >> startamount;
        bucketInfo.push_back(make_pair(cap, startamount));
    }
}

int main(){
    input();
    #if 0
    for(int i = 0; i < 3; i++){
        cout << "bucket capacity: " << bucketInfo[i].first << " bucket amount: " << bucketInfo[i].second << endl;
    }
    #endif
    for(int i = 0; i < 100; i++){
        //bucket we're pouring into is index (i % 3)
        int currentBucket = i%3; //either 0, 1, or 2 (index numbers)
        int targetBucket = (currentBucket+1)%3;
        /*
            if current bucket is 0 (1), then target should be 1 (2)
            if current bucket is 1 (2), then target should be 2 (3)
            if current bucket is 2 (3), then target should be 0 (1)
        */
        //cout << "pouring from: " << currentBucket << " to: " << targetBucket << endl;
        if(bucketInfo[currentBucket].second + bucketInfo[targetBucket].second > bucketInfo[targetBucket].first){
            int leftover = (bucketInfo[currentBucket].second + bucketInfo[targetBucket].second) - bucketInfo[targetBucket].first;
            bucketInfo[currentBucket].second = leftover;
            bucketInfo[targetBucket].second = bucketInfo[targetBucket].first;
        }
        else{
            bucketInfo[targetBucket].second += bucketInfo[currentBucket].second;
            bucketInfo[currentBucket].second = 0;
        }
    }

    ofstream myfile;
    myfile.open ("mixmilk.out");
    for(int i = 0; i < 3; i++){
        myfile << bucketInfo[i].second << '\n';
    }
    myfile.close();
}
