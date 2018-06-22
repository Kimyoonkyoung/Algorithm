/**
 * Created by Rachel.minii 
 * Date : 2018. 6. 22.
 * Project : Algorithm
 */

 /**
  * 반드시 O(n), constant space 으로 풀어야하는 문제
  * constant space 를 배제하고 풀어본다.
  * O(2n) == O(n) 이라는걸 생각한다.
  * constant space 로 최적화 해본다.
  */

#include <climits>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int firstMissingPositive(vector<int> &A) {

    if (A.size() == 1) {
        if (A[0] <= 0)
            return 1;
        else
            return A[0] + 1;
    }

    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 0 && A[i] < A.size()) {
            int tmp = A[A[i]-1];
            A[A[i]-1] = A[i];
            A[i] = tmp;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        if (A[i] != i + 1)
            return i + 1;
    }

    return (int)A.size()+1;
}


int main() {
    vector<int> A;

    A.push_back(699);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(-5);
    A.push_back(1);

    int ret = firstMissingPositive(A);
    printf("%d\n", ret);
}