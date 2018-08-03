/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 27.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <vector>
#include <math.h>

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


int threeSumClosest(vector<int> &A, int B) {
    mergesort(A, 0, (int)A.size()-1);

    int a, b, c ;
    int minDiff = INT_MAX;
    int result;

    for (a = 0; a < A.size(); a++) {
        int targetVal = B - A[a];

        b = a + 1;
        c = (int)A.size() - 1;

        while (b < c && b < A.size() && c >= 0) {
            int sum = A[a] + A[b] + A[c];

            if (sum == B)
                return B;

            if (abs(sum - B) < minDiff) {
                minDiff = abs(sum - B);
                result = sum;
            }

            if (A[b] + A[c] < targetVal) {
                b = (b + 1) == a ? b + 2 : b + 1;
            }
            else if (A[b] + A[c] > targetVal) {
                c = (c - 1) == a ? c - 2 : c - 1;
            }
        }
    }

    return result;
}


int main() {
    vector<int> A;
    /*
    A.push_back(-1);
    A.push_back(2);
    A.push_back(1);
    A.push_back(-4);
    */

    A.push_back(2);
    A.push_back(1);
    A.push_back(-9);
    A.push_back(-7);
    A.push_back(-8);
    A.push_back(2);
    A.push_back(-8);
    A.push_back(2);
    A.push_back(3);
    A.push_back(-8);

    int B = -1;

    printf("%d\n", threeSumClosest(A, B));
}