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

    // negative check
    if (A[idx] == '-' || A[idx] == '+') {
        mul = A[idx] == '-' ? -1 : 1;
        idx++;
    }

    string str;
    while (A[idx] != ' ' && A[idx] >= '0' && A[idx] <= '9') {
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