/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 2.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <math.h>

// 최대 공약수 구하는 문제

int gcd(int A, int B) {

    if (A == 0)
        return B;
    if (B == 0)
        return A;

    int smallVal = std::min(A, B);
    for (int i = smallVal; i > 1; i--) {
        if (A % i == 0 && B % i == 0)
            return i;
    }

    return 1;
}


int main() {
    printf("%d", gcd(2, 2));

    return 0;
}