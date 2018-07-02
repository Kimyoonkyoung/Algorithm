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

#ifdef EDITORIAL
    int smallVal = std::min(A, B);
    for (int i = smallVal; i > 1; i--) {
        if (A % i == 0 && B % i == 0)
            return i;
    }
    return 1;
#endif // EDITORIAL

#ifndef LIGHTWEIGHT
    /**
     * 나눈 나머지를 계속 나눠가는 방법으로 접근
     */
    if(A < B) {
        int temp = A;
        A = B;
        B = temp;
    }
    while(B != 0) {
        int temp = B;
        B = A % B;
        A = temp;
    }
    return A;

#endif // LIGHTWEIGHT

}


int main() {
    printf("%d", gcd(18, 8));

    return 0;
}