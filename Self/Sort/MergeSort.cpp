/**
 * Created by Rachel.minii 
 * Date : 2018. 6. 21.
 * Project : Algorithm
 */


#include <climits>
#include <vector>
#include <iostream>
#include <string>

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

int main() {
    vector<int> A;

    A.push_back(3);
    A.push_back(30);
    A.push_back(34);
    A.push_back(5);
    A.push_back(9);

    mergesort(A, 0, A.size()-1);

    // input 이 길어질때 string 으로 return 하는 방법
    string ret;
    for (int i = 0; i < A.size(); i++) {
        ret.append(to_string(A[i]));
    }
    printf("%s\n", ret.c_str());
}