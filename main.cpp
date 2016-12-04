#include <iostream>
#include <map>

using namespace std;

//pro: O(n)
//con: only works with array with one odd occuring element
//multiple odd occurances will be summed
int findOddNumberOccurance2(int* arr, int n) {
    //xor will cancel our (result 0 if occuring in even amounts)
    //element in odd amount will persist and not be cancelled
    int result = 0;
    for (int i=0; i<n; i++) {
        result = result ^ arr[i];
    }
    return result;
}

//using hashmap, finding where occurances = an odd number
//pro: can catch multiple odd occurances
//con: hasmap space complexity, O(kn)
int findOddNumberOccurance1(int* arr, int n) {
    map<int,int> values;
    map<int,int>::iterator it;
    for (int i=0; i<n; i++) {
        values[arr[i]]++;
    }
    for (it = values.begin(); it!=values.end(); it++) {
        if (it->second%2 != 0) {
            return it->first;
        }

    }
    return -1;
}

int main() {
    int arr[] = {1,1,1,2,2,2,5,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = findOddNumberOccurance2(arr, size);
    cout << result << endl;

    return 0;
}