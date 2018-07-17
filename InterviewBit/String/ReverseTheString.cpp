/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 17.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = (int)A.size();

    if (len <= 1)
        return;

    // get space index
    std::vector<int> spaceIdx;
    spaceIdx.push_back(-1); // initial setting
    for (int i = 0; i < len; i++) {
        if (A[i] == ' ')
            spaceIdx.push_back(i);
    }
    spaceIdx.push_back(len);

    // inverse string by word
    char tmp[len];
    int writeIdx = 0;
    for (int i = (int)spaceIdx.size() - 1; i > 0; i--) {
        if (spaceIdx[i] - spaceIdx[i - 1] == 1)
            continue;

        for (int j = spaceIdx[i - 1] + 1; j < spaceIdx[i]; j++) {
            tmp[writeIdx++] = A[j];
        }
        tmp[writeIdx++] = ' ';
    }

    // copy tmp to A
    for (int i = 0; i < writeIdx; i++) {
        A[i] = tmp[i];
    }
    A[writeIdx-1] = '\0';

    printf("%s\n", A.c_str());
}

int main() {
    string A;
    A = "rachel    minii   kakao corp     ";

    reverseWords(*(&A));

    return 0;
}