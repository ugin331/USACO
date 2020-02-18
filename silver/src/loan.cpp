#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gallonsOwed;
long long numDays;
long long minGallons;

void input(){
    cin >> gallonsOwed >> numDays >> minGallons;
}

bool predicate(long long gallonsOwed, long long numDays, long long minVal, long long x) {
    long long alreadyGiven = 0;
    while(numDays > 0 && alreadyGiven < gallonsOwed) {
        long long y = (gallonsOwed - alreadyGiven) / x;
    	if(y < minVal) {
            long long leftover = (gallonsOwed-alreadyGiven + minVal-1) / minVal;
            return leftover <= numDays;
    	}
    	long long maxmatch = gallonsOwed - x*y;
    	long long numdays2 = (maxmatch - alreadyGiven) / y + 1;
    	if(numdays2 > numDays) numdays2 = numDays;
    	alreadyGiven += y * numdays2;
    	numDays -= numdays2;
    }
    return alreadyGiven >= gallonsOwed;
}

int BFS(){
    long long lowerBound = 0;
    long long upperBound = gallonsOwed;
    while(lowerBound < upperBound){
	long long middleVal = (lowerBound + upperBound + 1)/2;
	if(predicate(gallonsOwed, numDays, minGallons, middleVal)){
	    lowerBound = middleVal;
	}
	else{
	    upperBound = middleVal-1;
	}
    }
    return lowerBound;
}

int main(){
    input();
    cout << BFS() << endl;
}
