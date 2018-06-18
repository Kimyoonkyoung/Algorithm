//
// Created by yoonkyoung on 2018. 6. 11..
//
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool _matchMatrix[10][10];
int _numStudent;

int matchPairs(bool matched[]) {

    int p1 = -1;
    for (int i = 0; i < _numStudent; i++) {
        if (!matched[i]) {
            p1 = i;
            break;
        }
    }

    // final case : 매칭 안된 친구가 없어!
    if (p1 == -1)
        return 1;

    int numPairs = 0;
    for (int p2 = p1+1; p2 < _numStudent; p2++) {

        // 매칭 성공
        if (!matched[p2] && _matchMatrix[p1][p2]) {
            matched[p1] = true;
            matched[p2] = true;

            numPairs += matchPairs(matched); // 현재 매치로 시작해서 쭉 가기

            matched[p1] = false;
            matched[p2] = false;
        }
    }

    return numPairs;
}

void picnic() {

    // read test case
    int testCase;
    scanf("%d\n", &testCase);

    for (int i = 0; i < testCase; i++) {
        int numPair;
        scanf("%d %d", &_numStudent, &numPair);

        // initialize
        memset(_matchMatrix, 0, sizeof(_matchMatrix));
        bool* matched = new bool[_numStudent];
        memset(matched, false, sizeof(matched));

        // pair 받는 동시에 matrix setting
        int p1, p2;
        for (int j = 0; j < numPair; j++) {
            scanf("%d %d", &p1, &p2);
            _matchMatrix[p1][p2] = true;
            _matchMatrix[p2][p1] = true;
        }

#if 1
        // max pair 를 만족시키는 경우 (더 해볼 필요도 없음)
        if ((_numStudent * (_numStudent-1)) >> 1 == numPair) {
            //printf("%d\n", _numStudent-1);
            continue;
        }
#endif

        if (numPair <= 0) {
            printf("0\n");
            continue;
        }


        printf("%d\n", matchPairs(matched));

        delete matched;
    }
}


int main() {
    picnic();
}
