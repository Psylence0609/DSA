#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& input, int start, int mid, int end){
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    vector<int> l,r;
    for (int i = 0; i < leftSize; i++) {
        l.push_back(input[start+i]);
    }
    for(int i = 0; i < rightSize; i++) {
        r.push_back(input[mid+ i+ 1]);
    }
    int i = 0, j = 0, k = start;
    while(i<leftSize && j < rightSize) {
        if(l[i]<=r[j]){
            input[k] = l[i];
            i++;
        }
        else {
            input[k] = r[j];
            j++;
        }
        k++;
    }
    while (i<leftSize) {
        input[k] = l[i];
        k++;
        i++;
    }
    while (j < rightSize) {
        input[k] = r[j];
        k++;
        j++;
    }

}

void mergeSort(vector<int>& input , int start, int end) {
    if(start < end) {
        int mid = start + (end-start)/2;
        mergeSort(input, start, mid);
        mergeSort(input, mid+1, end);
        merge(input, start, mid, end);
    }
}

int main() {
    vector<int> input = {3,2,45,32,9,5};
    mergeSort(input,0, input.size()-1);
    for (int i:input)
    cout << i<<endl;
    return 0;
}