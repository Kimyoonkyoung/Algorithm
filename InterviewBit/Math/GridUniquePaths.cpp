/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 3.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int uniquePaths(int A, int B) {
    if (A == 0 || B == 0)
        return 0;

    if (A == 1 && B == 1)
        return 1;

    vector<vector<int>> matrix;
    matrix.resize(A);
    for (int i = 0; i < A; i++) {
        matrix[i].resize(B);
        memset(&matrix[i], sizeof(matrix[i]), 0);
    }

    // initial setting
    for (int i = 0; i < A; i++) {
        matrix[i][0] = 1;
    }
    for (int i = 0; i < B; i++) {
        matrix[0][i] = 1;
    }

    // sum diagonal
    for (int i = 1; i < A; i++) {
        for (int j = 1; j < B; j++) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
    }

    return matrix[A - 1][B - 1];
}


int main() {
    printf("%d", uniquePaths(0, 1));

    return 0;
}