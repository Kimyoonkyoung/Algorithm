/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 4.
 * Project : Algorithm
 */

 /**
  * int 형으로 들어오는 input 의 제곱근을 찾는문제
  * Time out 의 원인은!
  * MAX_INT * MAX_INT 에서 overflow 가 나면서 꼬이기 때문에 while 문이 끝없이 돌 수 있음
  * long long 으로 형변환 해야 가능해짐
  */
#include <climits>
#include <iostream>
#include <math.h>

int _TARGET;

#ifdef TIMEOUT
int findSqrt(int min, int mid, int max) {


    int ret = 0;
    // base case
    if (mid * mid == _TARGET)
        return mid;
    else if (((mid - 1) * (mid - 1) < _TARGET) && (mid * mid > _TARGET))
        return mid - 1;
    else if (((mid + 1) * (mid + 1) > _TARGET) && (mid * mid < _TARGET))
        return mid;

    // recursive
    if (mid * mid > _TARGET) {
        int tmp = max;
        max = mid;
        mid = min + (int)((tmp - mid) / 2.0);
        ret = findSqrt(min, mid, max);
    }
    else {
        //int tmp = min;
        min = mid;
        mid = mid + (int)((max - mid) / 2.0);
        ret = findSqrt(min, mid, max);
    }
    return ret;

}
#endif // TIMEOUT

int sqrt(int A) {

    if (A == 0 || A == 1) {
        return A;
    }

    int start = 1, end = A / 2;

    while (start <= end) {
        if (start == end && start * start == A) {
            return start;
        }

        long long mid = (start + (long long)end) / 2;
        long long midPow = mid * mid;

        if ((mid - 1) * (mid - 1) < A && midPow > A) {
            return (int)mid - 1;
        }
        if ((mid + 1) * (mid + 1) > A && midPow < A){
            return (int)mid;
        }

        if (midPow > A) {
            end = (int)mid - 1;
        }
        else if (midPow < A) {
            start = (int)mid + 1;
        }
        else if (midPow == A) {
            return (int)mid;
        }
    }

    //return findSqrt(0, A / 2, A);
}


int main() {
    int input = 1000001;
    _TARGET = input;
    printf("%d", sqrt(input));

    return 0;
}