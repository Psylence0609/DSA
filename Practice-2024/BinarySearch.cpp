// #include <vector>
// #include <iostream>
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> input, int element) {
    int low = 0, high = input.size(), mid;
    while (low<=high) {
        mid = low + (high-low)/2;
        if (input[mid]>element)
        high = mid-1;
        else if (input[mid]<element)
        low = mid+1;
        else
        return input[mid];
    }
    return -1;
}

int main() {
    vector<int> input = {3,2,45,32,9,5};
    int element = 9;
    sort(input.begin(), input.end());
    cout<<binarySearch(input, element)<<endl;
}