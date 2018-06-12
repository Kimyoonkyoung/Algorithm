//
// Created by yoonkyoung on 2018. 6. 12..
//

#include <climits>
#include <vector>

using namespace std;

int maxSubArray(const vector<int> &A) {

    // unsigned 가 아니기 때문에
    int maxSum = -INT_MAX;
    if (A.size() == 1)
        return A[0];

    for (int i = 0; i < A.size()-1; i++) {

        int sum = A[i];
        if (sum > maxSum)
            maxSum = sum;

        for (int j = i+1; j < A.size(); j++) {

            sum += A[j];

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    // 마지막꺼 하나만 비교
    if (A[A.size()-1] > maxSum)
        maxSum = A[A.size()-1];

    return maxSum;
}



int main() {
    vector<int> A(5);
    A[0] = 1;
    A[1] = 3;
    A[2] = -10;
    A[3] = 3;
    A[4] = -1599;

    maxSubArray(A);
}