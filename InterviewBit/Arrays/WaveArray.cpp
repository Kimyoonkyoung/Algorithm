/**
 * Created by Rachel.minii 
 * Date : 2018. 6. 27.
 * Project : Algorithm
 */

#include <climits>
#include <vector>
#include <iostream>

using namespace std;


void merge(vector<int>& A, int startIdx, int midIdx, int endIdx) {
    vector<int> tmp;

    int l = startIdx;
    int r = midIdx + 1;

    while (l <= midIdx && r <= endIdx) {
        if (A[l] <= A[r]) {
            tmp.push_back(A[l]);
            l++;
        } else {
            tmp.push_back(A[r]);
            r++;
        }
    }

    if (l <= midIdx) {
        for (int i = l; i <= midIdx; i++) {
            tmp.push_back(A[i]);
        }
    }
    if (r <= endIdx) {
        for (int i = r; i <= endIdx; i++) {
            tmp.push_back(A[i]);
        }
    }

    for (int i = startIdx; i <= endIdx; i++) {
        A[i] = tmp[i - startIdx];
    }
}


void mergesort(vector<int>& A, int startIdx, int endIdx) {
    int mid;
    if (startIdx < endIdx) {
        mid = (startIdx + endIdx) / 2;
        mergesort(A, startIdx, mid);
        mergesort(A, mid + 1, endIdx);
        merge(A, startIdx, mid, endIdx);
    }
}

void swap(int* val1, int* val2) {
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

vector<int> wave(vector<int> &A) {

    for (int i = 0; i < A.size(); i++)
        printf("%d, ", A[i]);
    printf("\n");

    mergesort(A, 0, (int)A.size()-1);

    for (int i = 0; i < A.size(); i++)
        printf("%d, ", A[i]);
    printf("\n");

    for (int i = 0; i < A.size() - 1; i += 2) {
        swap(&A[i], &A[i+1]);
    }

    return A;
}


int main() {
    vector<int> A;

    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);

    vector<int> ret = wave(A);

    for (int i = 0; i < ret.size(); i++)
        printf("%d, ", ret[i]);

}