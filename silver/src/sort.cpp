#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Entry {
    int index;
    int value;
};


int numNums;
Entry nums[100001];

void input(){
    cin >> numNums;
    for(int i = 0; i < numNums; i++){
	int temp;
	cin >> temp;
	nums[i].value = temp;
	nums[i].index = i;
    }
}

int main(){
    input();
    cout << "before sort: " << endl;
    for(int i = 0; i < numNums; i++){
	cout << nums[i].value << endl;
    }
    sort(nums, nums + numNums, [](Entry a, Entry b) {
    	// since when ties occur we can just take the smallest value and it'll work we can:
	// break ties by simply making the smaller one being the first in the array to begin with
        return a.value < b.value || (a.value == b.value && a.index < b.index);
    });
    
    int answer = 0;
    cout << endl;
    cout << "after sort: " << endl;
    //
    for(int i = 0; i < numNums; i++){
	cout << nums[i].value << endl;
	//pre sort minus post sort (we're not changing what index is so this is perfectly acceptable)
	answer = max(answer, nums[i].index-i);
    }
    cout << endl;
    cout << "answer: " << answer << endl;
}
