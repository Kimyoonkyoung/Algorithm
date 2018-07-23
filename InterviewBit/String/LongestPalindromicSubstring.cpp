/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 20.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>

using namespace std;


string searchPalindrome(string A, int left, int right) {
    string ret;

    while (left >= 0 && right < A.size() && A[left] == A[right]) {
        left--;
        right++;
    }
    ret = A.substr(left + 1, (right - left - 1));

    return ret;
}

string longestPalindrome(string A) {
    string ret="";

    if (A.size() == 1) {
        return A;
    }

    if (A.size() == 2) {
        return A[0] == A[1] ? A : ret = A[0];
    }

    for (int i = 1; i < A.size(); i++) {

        string tmp;
        tmp = A[i];

        // odd palindromic check
        tmp = searchPalindrome(A, i, i);
        if (tmp.size() > ret.size())
            ret = tmp;

        // even palindromic check
        tmp = searchPalindrome(A, i-1, i);
        if (tmp.size() > ret.size())
            ret = tmp;
    }

    return ret;
}


int main() {
    string A;
    //A = "cacaccbabcabbbaacbbbbcaaaccaacbabcaccbccaacccaacbbaaabbbabcaaabc"; // aacbbbbcaa
    //A = "abacdfgdcaba"; // aba
    A = "aa";

    printf("%s\n", longestPalindrome(A).c_str());

    return 0;
}