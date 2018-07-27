/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 27.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size() <= 1) {
        return (int)A.size();
    }

    int l = 0, r = 1;
    while (r < A.size() && l < A.size()) {
        while (A[l] == A[r] && r < A.size()) {
            r++;
        }
        A[l + 1] = A[r];
        l++;
    }

    A.erase(A.begin() + l, A.begin() + A.size());

    return (int)A.size();
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(3);
    A.push_back(6);
    A.push_back(7);
    A.push_back(7);
    A.push_back(7);

    printf("%d\n", removeDuplicates(A));
    for (int i = 0; i < A.size(); i++)
        printf("%d, ", A[i]);

}