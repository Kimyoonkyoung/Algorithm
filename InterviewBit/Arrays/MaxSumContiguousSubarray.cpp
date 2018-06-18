//
// Created by yoonkyoung on 2018. 6. 12..
// Dynamic programming

#include <climits>
#include <vector>

using namespace std;

int maxSubArray(const vector<int> &A) {

    // unsigned 가 아니기 때문에
    if (A.size() == 1)
        return A[0];

#define SOLUTION
#ifdef SOLUTION
/**
 * Kadanes algorithm
 * Midium : https://medium.com/@marcellamaki/finding-the-maximum-contiguous-sum-in-an-array-and-kadanes-algorithm-e303cd4eb98c
 * wiki : https://en.wikipedia.org/wiki/Maximum_subarray_problem
 * http://koosaga.com/15
 * O(n) 으로 해결
 */

    if (A.size() == 1)
        return A[0];

    int maxSum = A[0];
    int subSum = A[0];

    for (int i = 1; i < A.size(); i++) {
        subSum = max(A[i], subSum + A[i]);
        maxSum = max(subSum, maxSum);
    }

    return maxSum;


#endif //SOLUTION



#ifdef INVERSESEARCH
/**
 * 그냥 알고리즘이 틀림
 * 앞에서 부터 더하면서 찾고, 뒤에서 부터 빼면서 찾는 방법으로 접근하려고했었음
 */
 *
    int sum = 0;
    int lastIdx = -1;
    for (int i = 0; i < A.size(); i++) {

        sum += A[i];
        if (sum > maxSum) {
            maxSum = sum;
            lastIdx = i;
        }
    }

    sum = 0;
    for (int i = lastIdx; i >= 0; i--) {

        sum += A[i];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
#endif //INVERSESEARCH


#ifdef BRUTEFORCE
/**
 * Brute-force 로 해결한 문제
 * 답은 맞으나 시간초과
 * O(n^2)
 */
         *
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
#endif // BRUTEFORCE

    return maxSum;
}


int main() {
    vector<int> A(9);
    A[0] = -2;
    A[1] = 1;
    A[2] = -3;
    A[3] = 4;
    A[4] = -1;
    A[5] = 2;
    A[6] = 1;
    A[7] = -5;
    A[8] = 4;

    int ret = maxSubArray(A);
    printf("%d\n", ret);
}