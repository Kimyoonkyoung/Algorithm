/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 2.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <math.h>
#include <cmath>

int isPower(int A) {
    if (A == 1)
        return 1;

    for (int i = 2; i * i <= A; i++) {
        int powCnt = 1;
        while(std::pow(i, powCnt) <= A) {
            if (std::pow(i, powCnt) == A)
                return 1;

            powCnt++;
        }
    }

    return 0;

}


int main() {
    printf("%d", isPower(216));

    return 0;
}