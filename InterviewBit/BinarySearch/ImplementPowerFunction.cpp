/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 11.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <math.h>

using namespace std;


// (x ^ n) % d
int pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long ret = 1;
    long long tmp = x;
    int origin_n = n;

    if (x == 0)
        return 0;

    if (n == 0)
        return 1;

    while (n > 0) {
        if (n % 2 == 1) {
            ret *= x;
        }
        ret = (ret * ret) % d;
        n /= 2;
        if (ret > d) {
            ret = ret % d;
        }
    }

    //printf("x : %d, remain : %d\n", x, n%2);
    if ((x < 0) && ((origin_n % 2) != 0)) {
        //ret = d - ret;
    }

    return int(ret);
}

int main() {

    printf("%d\n", pow(71045970, 41535484, 64735492));

    return 0;
}