#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>
#include <string>

using namespace std;

int numCows;
int goodStrings;
string cowArray[1001];
string goodArray[101];

void input(){
    string temp;
    string dummy;
    cin >> numCows >> goodStrings;
    for(int i = 0; i < numCows; i++){
	cin >> temp;
	//cout << temp << endl;
	cowArray[i] = temp;
	getline(cin, dummy); //skip a line
    }
    for(int i = 0; i < goodStrings; i++){
	cin >> temp;
	//cout << temp << endl;
	goodArray[i] = temp;
	getline(cin, dummy); //skip a line
    }
}

bool ContainsGoodStr(unordered_map<char, vector<int>> charmap, string goodStr){
    int len = goodStr.length();
    bool cont = false;
    int posinstring = 0;
    for(int i = 0; i < len; i++){
	cont = false;
	char character = tolower(goodStr[i]);
	auto itr = charmap.find(character);
	if(itr == charmap.end()){
	    return false;
	}
	vector<int> tempvec = itr->second;
	int veclen = tempvec.size();
	for(int j = 0; j < veclen; j++){
	    if(tempvec[j] > posinstring){
		posinstring = tempvec[j];
		cont = true;
		break;
	    }
  	}
	if(!cont){
	    return false;
	}
    }
    return cont;
}

int main(){
    input();
    int points = 0;
    for(int i = 0; i < numCows; i++){
        //cout << " processing " << i << "th word" << endl;
	unordered_map <char, vector<int>> charMap;
	int len = cowArray[i].length();
	//generate map
	//cout << "string: " << cowArray[i] << endl;
	for(int l = 0; l < len; l++){
	    char character = tolower(cowArray[i][l]);
	    vector<int> temp;
            auto p = charMap.insert(make_pair(character, temp)); 
            p.first->second.push_back(l); 
	    //cout << "adding character: " << character << " in position: " << l << endl;
     	}

	for(auto& itr : charMap){
	    vector<int> &tempvec = itr.second;
	    //cout << "letter: " << itr.first << endl;
	    //cout << "in positions: ";
	    //for(int j = 0; j < tempvec.size(); j++){
		//cout << tempvec[j] << " ";
	    //}
	    //cout << endl;
	}

	//go through all the good strings

	for(int j = 0; j < goodStrings; j++){
            string goods = goodArray[j];

            bool result = ContainsGoodStr(charMap, goods);
	    //cout << "result: " << result << " using good string: " << goods << " and target string: " << cowArray[i] << endl;
	    if(result){
		points++;
	    }
	}
    }
    cout << points << endl;
}
