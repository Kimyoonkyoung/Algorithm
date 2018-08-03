/**
 * Created by Rachel.minii 
 * Date : 2018. 8. 3.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int maxArea(vector<int> &A) {
    int max = 0;

#ifdef BRUTE_FORCE
    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = i + 1; j < A.size(); j++) {
            int area = (j - i) * min(A[j], A[i]);
            if (area > max) {
                max = area;
            }
        }
    }
#endif //BRUTE_FORCE

#ifndef OPTIMIZE
    int left = 0, right = (int)A.size() - 1;

    while (left < right) {
        int minHeight = min(A[left], A[right]);
        int subMax = minHeight * (right - left);

        // max 갱신
        if (subMax > max)
            max = subMax;

        if (min(A[left], A[right]) == A[left])
            left++;
        else
            right--;
    }
#endif // OPTIMIZE

    return max;
}

int main() {
    vector<int> A;
    /*
    A.push_back(-1);
    A.push_back(2);
    A.push_back(1);
    A.push_back(-4);
    */

    A.push_back(1);
    A.push_back(5);
    A.push_back(4);
    A.push_back(3);

    printf("%d\n", maxArea(A));
}