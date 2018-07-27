/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 27.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size() <= 0 || B.size() <= 0)
        return;

    vector<int> tmp;
    int a = 0, b = 0;

    while (a < A.size() && b < B.size()) {
        if (A[a] < B[b]) {
            tmp.push_back(A[a]);
            a++;
        }
        else {
            tmp.push_back(B[b]);
            b++;
        }
    }

    if (a < A.size()) {
        for (int i = a; i < A.size(); i++) {
            tmp.push_back(A[i]);
        }
    }

    if (b < B.size()) {
        for (int i = b; i < B.size(); i++) {
            tmp.push_back(B[i]);
        }
    }

   A = tmp;
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(6);

    vector<int> B;
    B.push_back(6);
    B.push_back(9);

    merge(A, B);

    for (int i = 0; i < A.size(); i++)
        printf("%d, ", A[i]);

}