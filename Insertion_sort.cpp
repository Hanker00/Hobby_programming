#include <iostream>
using namespace std;
#include <stdio.h>

int main() {
    int unsorted[] = {5,2,9,1,123};
    int i = 0;
    int sp = 0;
    int j = 0;
    while(5 > j) {
            i = j;
            sp = j;
    while(i < 5) {
        if(unsorted[sp] > unsorted[i]) {
            sp = i;
        }
        i += 1;
    }
    int temp = unsorted[j];
    unsorted[j] = unsorted[sp];
    unsorted[sp] = temp;
    j += 1;
    }
    i = 0;
    while(i < 5) {
        cout << " " << unsorted[i];
        i += 1;
    }
}
 
