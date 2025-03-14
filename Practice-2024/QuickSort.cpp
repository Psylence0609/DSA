#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& input , int start, int pivot) {
    int pivotElement = input[pivot];
    int i = start - 1;

    for(int j = 0; j < pivot; j++) {
        if(input[j] <= pivotElement) {
            i++;
            swap(input[i],input[j]);
        }
    }
    swap(input[i+1],input[pivot]);
    return i+1;
}

void quickSort(vector<int>& input , int start, int pivot) {
    if (start < pivot) {
        int mid = partition(input, start, pivot);
        quickSort(input, start, mid - 1);
        quickSort(input, mid + 1, pivot);
    }
}

int main() {
    vector<int> input = {3,2,45,32,9,5};
    quickSort(input,0, input.size()-1);
    for (int i:input)
    cout << i<<endl;
    return 0;
}