/**
 * Created by Rachel.minii 
 * Date : 2018. 8. 9.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l, r, mid;

    l = 0;
    r = (int)A.size() - 1;

    // search sort start point
    while (l < r) {
        mid = l + ((r - l) / 2);

        // return
        if (A[l] == B)
            return l;
        if (A[r] == B)
            return r;
        if (A[mid] == B)
            return mid;

        // binary search
        if (A[mid] > A[r]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            //break;
        }
    }

    if (B > A[A.size() - 1]) {
        r = l;
        l = 0;
    }
    else {
        l = r;
        r = (int)A.size();
    }

    // search target value
    while (l < r) {
        mid = l + ((r - l) / 2);

        // return
        if (A[l] == B)
            return l;
        if (A[r] == B)
            return r;
        if (A[mid] == B)
            return mid;

        // binary search
        if (A[mid] < B) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return -1;

}


int main() {
    vector<int> A;


    A.push_back(101);
    A.push_back(103);
    A.push_back(106);
    A.push_back(109);
    A.push_back(158);
    A.push_back(164);
    A.push_back(182);
    A.push_back(187);
    A.push_back(202);
    A.push_back(205);
    A.push_back(2);
    A.push_back(3);
    A.push_back(32);
    A.push_back(57);
    A.push_back(69);
    A.push_back(74);
    A.push_back(81);
    A.push_back(99);
    A.push_back(100);

    int B = 182;
    printf("%d, ", search(A, B));

    return 0;
}