/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 19.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>
#include <cmath>

using namespace std;

int atoi(const string A) {
    int ret = 0;
    int idx = 0;
    int mul = 1;

    // remove blank
    while (A[idx] == ' ')
        idx++;

    // check first char? or int?
    if (!isdigit(A[idx]) && A[idx] != '-' && A[idx] != '+') {
        return ret;
    }

    // is negative?
    if (A[idx] == '-') {
        mul = -1;
        idx++;
    }

    // is positive?
    if (A[idx] == '+') {
        idx++;
    }

    string str;
    while (A[idx] != ' ' && isdigit(A[idx])) {
        str += A[idx];
        idx++;
    }

    for (int i = 0; i < str.size(); i++) {
        int curDigit = int(str[i]) - '0';
        long long tmp = (long long)(ret + (curDigit * pow(10, str.size() - i - 1)));
        if (mul == 1 && tmp > INT_MAX)
            return INT_MAX;
        else if (mul == -1 && tmp * mul < INT_MIN)
            return INT_MIN;
        else {
            ret = (int)tmp;
        }
    }

    return ret * mul;
}


int main() {
    const string in = "  99784545512354879123146 4578";
    printf("%d", atoi(in));

    return 0;
}