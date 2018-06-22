/**
 * Created by Rachel.minii 
 * Date : 2018. 6. 21.
 * Project : Algorithm
 */

 /**
  * merge sort 로 접근하는데, merge 하는 방법을 XY 일때와 YX 일때를 비교해서 함
  */

#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void merge(vector<int>& A, int startIdx, int midIdx, int endIdx) {
    vector<int> tmp;

    int l = startIdx;
    int r = midIdx + 1;

    while (l <= midIdx && r <= endIdx) {
        int lDigit = int(floor(log10(A[l])) + 1);
        int rDigit = int(floor(log10(A[r])) + 1);

        // compare lr
        // XY 와 YX 를 비교하기 위해서, 각각 몇자리 수인지 확인해야함
        // 몇자리 수 인지 확인하기 : log 사용하면 딱!
        long lr = (A[l] * (long)pow(10, rDigit)) + A[r];
        long rl = (A[r] * (long)pow(10, lDigit)) + A[l];

        if (lr >= rl) {
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
            tmp.push_back(A[r]);
        }
    }

    for (int i = startIdx; i <= endIdx; i++) {
        A[i] = tmp[i - startIdx];
    }
}


void mergesort(vector<int>& A, int startIdx, int endIdx) {
    int mid;

    // 종료조건
    if (A.size() == 1)
        return;

    if (startIdx < endIdx) {
        mid = (startIdx + endIdx) / 2;
        mergesort(A, startIdx, mid);
        mergesort(A, mid + 1, endIdx);
        merge(A, startIdx, mid, endIdx);
    }
}



string largestNumber(const vector<int>& A) {
    vector<int> inputA;
    inputA.assign(A.begin(), A.end());
    inputA = A;

    mergesort(inputA, 0, A.size()-1);

    string ret;
    for (int i = 0; i < A.size(); i++) {
        ret.append(to_string(A[i]));
    }

    return ret;
}


int main() {
    vector<int> A;

    A.push_back(8);
    A.push_back(89);
    //A.push_back(34);
    //A.push_back(5);
    //A.push_back(9);

    string ret = largestNumber(A);
    printf("%s\n", ret.c_str());
}