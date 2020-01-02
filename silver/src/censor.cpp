#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string target, searchString;

int input(){
    getline(cin, searchString);
    getline(cin, target);
}

int main(){
    input();
    long locatsize = searchString.length();
    long tlen = target.length();
    for(long i = locatsize-tlen; i >= 0; i--){
        //cout << searchString.substr(i, tlen) << endl;
        //cout << "target: " << target << endl;
        if(searchString.substr(i, tlen) == target){
            //cout << "yes" << endl;
            searchString.erase(i, tlen);
        }
    }
    cout << searchString << endl;
}
