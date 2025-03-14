#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& input, int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && input[left] > input[largest])
    largest = left;

    if(right<n && input[right] > input[largest])
    largest = right;

    if(largest != i) {
        swap(input[i], input[largest]);
        heapify(input, n, largest);
    }
}


void heapSort(vector<int>& input, int n) {
    for(int i = n/2 -1; i >= 0; i--) {
        heapify(input, n, i);
    }

    for(int i = n-1; i > 0; i--) {
        swap(input[i], input[0]);

        heapify(input, i, 0);
    }
}

int main() {
    vector<int> input = {3,2,45,32,9,5};
    heapSort(input,input.size());
    for (int i:input)
    cout << i<<endl;
    return 0;
}