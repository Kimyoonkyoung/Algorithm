/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 9.
 * Project : Algorithm
 */

#include <climits>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ret;
    ret.push_back(-1);
    ret.push_back(-1);

    if (A.size() == 1 && A[0] == B){
        ret[0] = 0;
        ret[1] = 0;
        return ret;
    }

    int start = 0, end = (int)A.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] < B) {
            start = mid + 1;
        }
        else if (A[mid] > B) {
            end = mid - 1;
        }
        else if (A[mid] == B) {
            ret[0] = mid;
            ret[1] = mid;

            // find start
            for (int startIdx = start; startIdx < mid; startIdx++) {
                if (A[startIdx] == B) {
                    ret[0] = startIdx;
                    break;
                }
            }
            for (int endIdx = end; endIdx > mid; endIdx--) {
                if (A[endIdx] == B) {
                    ret[1] = endIdx;
                    break;
                }
            }

            break;
            // 여기서, 찾았으면 종료해줘야되는데 break 를 빼먹었다가 Time out 생겼었음!
        }
    }

    return ret;
}

int main() {
    vector<int> A;

    A.push_back(5);
    A.push_back(7);
    A.push_back(7);
    A.push_back(8);
    A.push_back(8);
    A.push_back(10);

    vector<int> ret = searchRange(A, 8);

    for (int i = 0; i < ret.size(); i++)
        printf("%d, ", ret[i]);


    return 0;
}