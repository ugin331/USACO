#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numElements;
int mtnheights[100001];

void input(){
    cin >> numElements;
    for(int i = 0; i < numElements; i++){
	int tempheight;
	cin >> tempheight;
	mtnheights[i] = tempheight;
    }
}

int main(){

}
