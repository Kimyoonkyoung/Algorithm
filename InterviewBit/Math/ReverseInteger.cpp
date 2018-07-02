/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 2.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <math.h>
#include <cmath>

int reverse(int A) {
    if (A >= INT_MAX || A <= INT_MIN) {
        return 0;
    }

    int mul = 1;
    if (A < 0) {
        A *= -1;
        mul = -1;
    }

    long ret = 0;
    int numDigit = int(floor(log10(A)) + 1);

    for (int i = 1; i < numDigit; i++) {
        // target digit
        int val = A % (int)pow(10, i);
        val /= (int)pow(10, i - 1);

        // int max check
        if (ret +  val * (long)pow(10, numDigit - i) >= INT_MAX)
            return 0;

        // set inverse integer
        ret += val * (long)pow(10, numDigit - i);
    }

    if (ret +  A / (long)pow(10, numDigit - 1) >= INT_MAX)
        return 0;

    ret += A / (long)pow(10, numDigit - 1);
    return (int)ret * mul;
}


int main() {
    printf("%d", reverse(-1146467285));

    return 0;
}