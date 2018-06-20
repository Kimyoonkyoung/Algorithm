//
// Created by yoonkyoung on 2018. 6. 20..
//
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

vector<int> rotateArray(vector<int> &A, int B) {
    vector<int> ret;
    if (A.size() == 1)
        return ret;

    for (int i = 0; i < B; i++) {
        A.push_back(A[0]);
        A.erase(A.begin());
    }
    return A;
}


int main() {
    vector<int> A;

    A.push_back(14);
    A.push_back(65);
    A.push_back(34);
    A.push_back(7);
    A.push_back(56);
    A.push_back(4);

    vector<int> ret = rotateArray(A, 10);

    for (int i = 0; i < ret.size(); i++)
        printf("%d, ", ret[i]);

}