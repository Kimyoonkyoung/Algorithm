/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 20.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>

using namespace std;

string longestPalindrome(string A) {
    string ret="";

    if (A.size() == 1) {
        return A;
    }

    if (A.size() == 2) {
        return A[0] == A[1] ? A : ret = A[0];
    }

    for (int i = 1; i < A.size(); i++) {

        int offset = 1;
        string tmp;
        tmp = A[i];

        // odd palindromic check
        while ((i - offset) >= 0 && (i + offset) < A.size()) {

            if (A[i - offset] == A[i + offset]) {

                if (((offset * 2) + 1) > tmp.size()) {
                    tmp = A.substr(i - offset, (offset * 2) + 1);
                }

                offset++;
            }
            else {
                break;
            }
        }

        // even palindromic check
        int left = i - 1, right = i;
        while (left >= 0 && right < A.size() && A[left] == A[right]) {

            if ((right - left) + 1> tmp.size()) {
                tmp = A.substr(left, (right - left) + 1);
            }
            left--;
            right++;
        }

        if (tmp.size() > ret.size())
            ret = tmp;

    }

    return ret;
}


int main() {
    string A;
    //A = "cacaccbabcabbbaacbbbbcaaaccaacbabcaccbccaacccaacbbaaabbbabcaaabc"; // aacbbbbcaa
    A = "abacdfgdcaba"; // aba

    printf("%s\n", longestPalindrome(A).c_str());

    return 0;
}