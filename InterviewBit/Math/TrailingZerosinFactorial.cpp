/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 3.
 * Project : Algorithm
 */

 // factorial 구해서, 뒤에 0의 갯수 출력하는 문제 (log N) 시간안에!

#include <climits>
#include <iostream>
#include <math.h>

int trailingZeroes(int A) {
    int ret = 0;

    ret += A / 5;

    int i = 25;
    while (i < A) {
        ret += A / i;
        i *= 5;
    }

    return ret;

}


int main() {
    printf("%d", trailingZeroes(5));

    return 0;
}