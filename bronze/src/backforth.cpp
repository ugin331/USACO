#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> buckets1(10, 0);
vector<int> buckets2(10, 0);
unordered_map<int, int> tankvals;

int input(){
    fstream input;
    input.open("backforth.in");
    int bucket;
    for(int i = 0; i < 10; i++){
	input >> bucket;
  	buckets1[i]=bucket;
    }
    for(int i = 0; i < 10; i++){
	input >> bucket;
	buckets2[i]=bucket;	
    }
}

int main(){
    input();
    #if 0
    for(int i = 0; i < 10; i++){
	cout << buckets1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++){
	cout << buckets2[i] << " ";
    }
    cout << endl;
    #endif
    //trip 1
    for(int i = 0; i < 10; i++){
	//trip 2
	for(int j = 0; j < 11; j++){
	    //trip 3
	    for(int k = 0; k < 10; k++){
		//trip 4
		for(int l = 0; l < 11; l++){
    		    int total = 0;
		    vector<int> copy1 = buckets1;
		    vector<int> copy2 = buckets2;
		    total-=copy1[i];
		    copy2.push_back(copy1[i]);
		    total+= copy2[j];
		    copy1[i] = copy2[j];
		    total-= copy1[k];
		    copy2[j] = copy1[k];
		    total+= copy2[l];
		    if(tankvals.find(total)==tankvals.end()){
			tankvals[total]=1;
		    }
		}
  	    }
	}
    }
    int numPoss = 0;
    for(auto &E: tankvals){
	//cout << E.first << endl;
	numPoss++;
    }
    ofstream myfile;
    myfile.open("backforth.out");
    myfile << numPoss;
    myfile.close();
}
