/**
 * Created by Rachel.minii 
 * Date : 2018. 6. 25.
 * Project : Algorithm
 */

 /**
  * 추가 메모리 없이 구현하기!
  */

#include <climits>
#include <vector>
#include <iostream>

using namespace std;

void rotateMatrix(vector<vector<int> > &A) {

    if (A.size() == 1)
        return;

    int minIdx = 0, maxIdx = A.size() - 1;
    while (minIdx < A.size() / 2.f) {

        for (int rot = 0; rot < maxIdx - minIdx; rot++) {
            int startVal = A[minIdx][minIdx + rot];
            A[minIdx][minIdx + rot] = A[maxIdx - rot][minIdx];
            A[maxIdx - rot][minIdx] = A[maxIdx][maxIdx - rot];
            A[maxIdx][maxIdx - rot] = A[minIdx + rot][maxIdx];
            A[minIdx + rot][maxIdx] = startVal;
        }

        minIdx++;
        maxIdx--;
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}


int main() {
    vector<vector<int>> A;
    vector<int> sub;

    sub.push_back(1);
    sub.push_back(2);
    sub.push_back(3);
    sub.push_back(4);
    sub.push_back(5);
    A.push_back(sub);

    sub.clear();
    sub.push_back(6);
    sub.push_back(7);
    sub.push_back(8);
    sub.push_back(9);
    sub.push_back(10);
    A.push_back(sub);

    sub.clear();
    sub.push_back(11);
    sub.push_back(12);
    sub.push_back(13);
    sub.push_back(14);
    sub.push_back(15);
    A.push_back(sub);

    sub.clear();
    sub.push_back(16);
    sub.push_back(17);
    sub.push_back(18);
    sub.push_back(19);
    sub.push_back(20);
    A.push_back(sub);

    sub.clear();
    sub.push_back(21);
    sub.push_back(22);
    sub.push_back(23);
    sub.push_back(24);
    sub.push_back(25);
    A.push_back(sub);

    rotateMatrix(A);

    return 0;
}