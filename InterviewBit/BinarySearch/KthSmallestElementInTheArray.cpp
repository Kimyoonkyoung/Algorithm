/**
 * Created by Rachel.minii 
 * Date : 2018. 8. 3.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>
#include <math.h>
#include <vector>

/**
 * extra space X
 * constant input -> sort 같은거 안됨
 * "binary search the answer" 알고리즘 적용
 * array 대상으로 BS 가 아니고, value 대상으로 BS 하는 방법
 */

using namespace std;

int searchRange(const vector<int> &A, int B) {
    if (B > A.size())
        return -1;

    if (A.size() == 1 && B == A.size())
        return A[0];

    int low = *min_element(A.begin(), A.end());
    int high = *max_element(A.begin(), A.end());

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int countLess = 0;
        int countEqual = 0;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] < mid)
                countLess++;
            else if (A[i] == mid)
                countEqual++;

            if (countLess >= B)
                break;
        }

        if (countLess < B && countLess + countEqual >= B) {
            return mid;
        }
        else if (countLess >= B) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}



int main() {
    vector<int> A;

    /*
    A.push_back(2);
    A.push_back(1);
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
       */

    A.push_back(94);
    A.push_back(87);
    A.push_back(100);
    A.push_back(11);
    A.push_back(23);
    A.push_back(98);
    A.push_back(17);
    A.push_back(35);
    A.push_back(43);
    A.push_back(66);
    A.push_back(34);
    A.push_back(53);
    A.push_back(72);
    A.push_back(80);
    A.push_back(5);
    A.push_back(34);
    A.push_back(64);
    A.push_back(71);
    A.push_back(9);
    A.push_back(16);
    A.push_back(41);
    A.push_back(66);
    A.push_back(96);

    int B = 19;
    printf("%d\n", searchRange(A, B));

    return 0;
}