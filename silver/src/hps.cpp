#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int numelements;

//pretty self explanatory input
void input(vector<char> &farmermoves){
    cin >> numelements;
    for(int i = 0; i < numelements; i++){
        char move;
        cin >> move;
        farmermoves.push_back(move);
    }
}

int comparison(char bmove, char fmove){
    //check if the two inputs are either "H", "P", or "S"
    if(bmove != 'H' && bmove != 'P' && bmove != 'S'){
        if(fmove != 'H' && fmove != 'P' && fmove != 'S'){
            //if not, then don't do anything
            //cout << "i think you have a broke input" << endl;
            return -45;
        }
    }
    else{
        //hoof
        if(bmove == 'H'){
            if(fmove == 'S'){
                return 1;
            }
            if(fmove == 'H'){
                return 0;
            }
            else{
                return 0;
            }
        }
        //paper
        else if(bmove == 'P'){
            if(fmove == 'H'){
                return 1;
            }
            if(fmove == 'P'){
                return 0;
            }
            else{
                return 0;
            }
        }
        //scissors
        else{
            if(fmove == 'P'){
                return 1;
            }
            if(fmove == 'S'){
		return 0;
            }
            else{
                return 0;
            }
        }
    }
}

int main(){
    vector<char> farmermoves;
    input(farmermoves);
    //sum holder array
    vector<int> finalsums;
    //should i keep all the possible elements in a vector? might make things easier
    //KEY: FIRST ELEMENT IS ***THE STARTING ELEMENT*** THE SECOND ELEMENT IS ***THE SWAPPED ELEMENT***
    vector<pair<char, char>> poss = {{'H', 'P'}, {'H','S'}, {'P','S'}, {'P','H'}, {'S','H'}, {'S','P'}};
    //outer loop to run through the different combinations of B's moves
    for(int i = 0; i < 6; i++){
        //getting the sum for each one
        int sum = 0;
        //cout << "change location: " << j << endl;
        //cout << "starting sign: " << poss[i].first << endl;
        //cout << "ending sign: " << poss[i].second << endl;
        //this loop runs through the first section of farmer john's moves and compares it to B's moves up until the switchpoint
        for(int k = 0; k < numelements; k++){
            sum += comparison(poss[i].first, farmermoves[k]);
        }
        finalsums.push_back(sum);
        //interior loop to run through and change element at which B changes moves
        for(int j = 1; j < numelements; j++){
            sum -= comparison(poss[i].first, farmermoves[j]);
            sum += comparison(poss[i].second, farmermoves[j]);
            finalsums.push_back(sum);
            //cout << sum << endl;
        }
    }
    int max = 0;
    int size = finalsums.size();
    int i = 0;
    for (int j = 0; j < 6; j++){
        cout << "group " << j << endl;
        for(int z = 0; z < 30; z++){
            cout << finalsums[i++] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < size; i++){
        if(finalsums[i] >= max){
            max = finalsums[i];
        }
    }
    cout << max << endl;
}
