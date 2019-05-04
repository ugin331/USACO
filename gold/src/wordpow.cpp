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

int getLowestPossIndex(char key, int currIndex, unordered_map<char, vector<int>> charmap){
    auto itr = charmap.find(key);
    if(itr == charmap.end()){
	return -1;
    }
    vector<int> &indexVec = itr->second;
    int veclen = indexVec.size();
    for(int i = 0; i < veclen; i++){
	if(indexVec[i] > currIndex){
	    return indexVec[i];
	}
    }
    return -1;
}

bool ContainsGoodStr(unordered_map<char, vector<int>> charmap, string goodStr){
    int len = goodStr.length();
    //bool cont = false;
    int posinstring = 0;
    for(int i = 0; i < len; i++){
	char character = tolower(goodStr[i]);
	posinstring = getLowestPossIndex(character, posinstring, charmap);
	//if returned -1 by lowest index finder then false
	if(posinstring == -1){
	    return false;
	}
    }
    //return cont;
    return true;
}

int main(){
    input();
    for(int i = 0; i < numCows; i++){
        int points = 0;
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
        cout << points << endl;
    }
}
