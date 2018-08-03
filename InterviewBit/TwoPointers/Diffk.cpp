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

int diffPossible(vector<int> &A, int B) {

#ifdef BRUTE_FORCE
    int ret = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] - A[i] > B)
                break;

            if (A[j] - A[i] == B)
                return 1;
        }
    }
#endif //BRUTE_FORCE

#ifndef OPTIMIZE
    if (A.size() <= 1)
        return 0;

    int j = 0;
    for (int i = 0; i < A.size(); i++) {
        j = max(i + 1, j);
        while (j < A.size() && A[j] - A[i] < B) {
            j++;
        }

        if (A[j] - A[i] == B)
            return 1;
    }
#endif //OPTIMIZE

    return 0;
}


int main() {
    vector<int> A;

    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    A.push_back(7);

    int B = 4;

    printf("%d\n", diffPossible(A, B));
}