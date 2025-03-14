#include<bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> input){
    int length = input.size(), key, iterator2;
    for(int iterator1 = 1; iterator1 < length; iterator1++) {
        key = input[iterator1];
        iterator2 = iterator1-1;
        while(input[iterator2]>key && iterator2 >= 0) {
            input[iterator2+1] = input[iterator2];
            iterator2--;
        }
        input[iterator2+1] = key;
    }
    return input;
}

int main() {
    vector<int> input = {3,2,45,32,9,5};
    input = insertionSort(input);
    for (int i:input)
    cout << i<<endl;
}