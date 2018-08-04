/**
 * Created by Rachel.minii 
 * Date : 2018. 8. 4.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int numRange(vector<int> &A, int B, int C) {
    int count = 0;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] > C)
            continue;

        if (A[i] >= B && A[i] <= C) {
            count++;
        }

        long long sum = 0;

        int min = B - A[i];
        int max = C - A[i];

        int j = i + 1;
        while (sum < max && j < A.size()) {
            sum += A[j++];

            if (sum >= min && sum <= max)
                count++;
        }
    }

    return count;
}

int main() {
    vector<int> A;

    A.push_back(2);
    A.push_back(1);
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);

    int B = 6;
    int C = 8;
    printf("%d\n", numRange(A, B, C));

    return 0;
}