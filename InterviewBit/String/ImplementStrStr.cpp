/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 17.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>


using namespace std;

int strStr(const string A, const string B) {
    int ret = -1;
    if (A[0] == '\0' || B[0] == '\0') {
        return ret;
    }

    int haystackIdx = 0;
    int needleIdx = 0;
    while (A[haystackIdx] != '\0') {

        // 첫번째 글자 같으면
        if (A[haystackIdx] == B[needleIdx]) {

            ret = haystackIdx;
            int tmp_haystackIdx = haystackIdx;

            while(B[needleIdx] != '\0') {
                needleIdx++;
                tmp_haystackIdx++;

                if (A[tmp_haystackIdx] != B[needleIdx])
                    break;
            }

            if (B[needleIdx] == '\0') { // success
                return ret;
            }
            else { // failed (reset)
                needleIdx = 0;
                ret = -1;
            }
        }

        haystackIdx++;

    }

    return ret;
}

int main() {

    printf("%d", strStr("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba", "babaaa"));

    return 0;
}