#include<bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> input) {
    int length = input.size(),temp;
    bool swapped;
    for(int iterator1 = 0; iterator1 < length-1; iterator1++) {
        swapped = false;
        for(int iterator2 = 0; iterator2 < length-iterator1-1; iterator2++) {
            if (input[iterator2]>input[iterator2+1]) {
                swap(input[iterator2], input[iterator2+1]);
                swapped = true;
            }
        }
        if(swapped == false)
        break;
    }
    return input;
}

int main() {
    vector<int> input = {3,2,45,32,9,5};
    input = bubbleSort(input);
    for (int i:input)
    cout << i<<endl;
}