/**
 * Created by Rachel.minii 
 * Date : 2018. 6. 27.
 * Project : Algorithm
 */

#include <climits>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;


int repeatedNumber(const vector<int> &A) {
    int ret = -1;
    int n3 = int(ceil(A.size() / 3.0));

    int iter = 0;
    int tmp = A[A[iter]];
    while (iter < A.size()) {
        A[A[iter]]


        iter++;
    }


    return ret;
}


int main() {
    vector<int> A;

    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(1);
    A.push_back(1);

    int val = repeatedNumber(A);

    printf("%d\n", val);
}