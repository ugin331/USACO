#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numCows;
int numQueries;

struct query{
    //true means find the line corresponding to line number, false otherwise
    bool querytype;
    vector <int> queryvals;
    int lineNum;
};

query queryArray[10001];
long long factorials[20];

void input(){
    cin >> numCows;
    cin >> numQueries;
    for(int i = 0; i < numQueries; i++){
	char querytype;
	int seqnum;
	query tempQuery;
	cin >> querytype;
	if(querytype == 'Q'){
	    tempQuery.querytype = false;
	    for(int i = 0; i < numCows; i++){
	    	cin >> seqnum;
	    	tempQuery.queryvals.push_back(seqnum);
	    }
	}
	else{
	    tempQuery.querytype = true;
	    cin >> seqnum;
	    tempQuery.lineNum = seqnum;
	}
	queryArray[i] = tempQuery;
    }
}

void genFactorials(){
    int temp = 1;
    factorials[0] = 1;
    for(int i = 1; i < numCows; i++){
	temp *= i;
	factorials[i] = temp;
    }
}

int findInArray(vector<int> &intVec, vector<bool> &inArray, int targetInt){
    int temp = 0;
    for(int i = 0; i < numCows; i++){
	if(inArray[i]){
	    continue;
 	}
	if(temp == targetInt){
	    inArray[i] = true;
	    return intVec[i];
	}
	temp++;
    }
}

int findNumInArray(vector<int> &intVec, vector<bool> &inArray, int targetInt){
    int temp = 0;
    for(int i = 0; i < numCows; i++){
	if(inArray[i]){
	    continue;
 	}
	if(targetInt == intVec[i]){
	    inArray[i] = true;
	    return temp;
	}
	temp++;
    }
}

//basically the idea here is to take the input (the sequence given in the query)
//and add up the number of rotations each number would have needed to do
//i.e. the 5th slot takes 4! movements to change, so if there were a 3 we would
//know that there were 2 previous full rotations meaning we could add (3-1)*4! to our total.
void findLineNum(vector<int> &queryvals){
    int total = 0;
    vector<int> temp;
    vector<bool> inArray;
    for(int i = 0; i < numCows; i++){
	temp.push_back(i+1);
	inArray.push_back(false);
    }
    for(int i = 0; i < numCows; i++){
 	int num = findNumInArray(temp, inArray, queryvals[i]);
	total += num*factorials[numCows-i-1];
    }
    total++;
    cout << total << endl;
}

//to find the sequence given a number, we mod the sequence with first 4!, to find
//which number goes there. Then, we take the quotient and then repeat with 3!,
//2!, then 1!, so on so forth. The number we get from each mod represents the position within 
void findSequence(int num){
    num--;
    vector<int> numSeq;
    //storing the bools and the int array
    vector<int> temp;
    vector<bool> inArray;
    //generating bool and int array
    for(int i = 0; i < numCows; i++){
	temp.push_back(i+1);
	inArray.push_back(false);
    }
    for(int i = numCows-1; i >= 0; i--){
	int tgt = num/factorials[i];
  	int found = findInArray(temp, inArray, tgt);
	numSeq.push_back(found);
  	num %= factorials[i];
    }
    //print numseq
    for(int i = 0; i < numCows; i++){
	cout << numSeq[i] << " ";
    }
    cout << endl;
}

int main(){
    input();
    genFactorials();
    for(int i = 0; i < numQueries; i++){
	if(!queryArray[i].querytype){
	    findLineNum(queryArray[i].queryvals); 
	}
	else{
	    findSequence(queryArray[i].lineNum); 
	}
    }
}
