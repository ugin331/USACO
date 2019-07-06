#include <iostream>
#include <string>

using namespace std;

string parentheses;

void input(){
    cin >> parentheses;
    string dummy;
    getline(cin, dummy); //next line
}

int main(){
    input();
    int length = parentheses.length();
    int sum = 0;
    int numchanges = 0;
    //algorithm: convert all the parentheses to 1 and -1
    //take the prefix sum of every element
    //if the prefix sum is ever negative then toggle it
    //if the ending parentheses is ( then flip it
    for(int i = 0; i < length; i++){
        if(i == length-1 && parentheses[i] == '('){
            parentheses[i] = ')';
            numchanges++;
            break;
        }
        //adjust the value of the pref sum
        if(parentheses[i] = '('){
            sum++;
        }
        else{
            sum--;
        }
        //adjust if the sum is either too big or too small
        if(sum > 0){
            //sum greater than 0, adjust down
            if(sum >= 2){
                parentheses[i] = ')';
                numchanges++;
                sum -= 2;
            }
        }
        else if(sum < 0){
            //sum less than 0, adjust up
            if(sum <= -2){
                parentheses[i] = '(';
                numchanges++;
                sum += 2;
            }
        }
        else{
            continue;
            //literally do nothing lol
        }
    }
    cout << numchanges << endl;
}
