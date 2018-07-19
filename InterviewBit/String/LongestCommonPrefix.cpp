/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 19.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &A) {
    string ret;

    if (A.size() == 1) {
        return A[0];
    }

    int idx = 0;
    while (idx < A[0].size()) {
        char baseChar = A[0][idx];
        bool check = true;

        for (int i = 1; i < A.size(); i++) {
            if (idx > A[i].size()) {
                check = false;
                break;
            }

            if (A[i][idx] != baseChar) {
                check = false;
                break;
            }
        }

        if (check) {
            idx++;
            ret += baseChar;
        }
        else {
            break;
        }
    }

    return ret;
}


int main() {
    vector<string> A;
    string tmp;

    tmp = "adaab";
    A.push_back(tmp);

    tmp = "aaaccjwi";
    A.push_back(tmp);

    tmp = "aaaddfdfdcccjwi";
    A.push_back(tmp);

    printf("%s\n", longestCommonPrefix(A).c_str());

    return 0;
}