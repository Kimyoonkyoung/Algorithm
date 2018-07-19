/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 19.
 * Project : Algorithm
 */

#include <climits>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > prettyPrint(int A) {
    vector<vector<int>> ret;

    int size = A * 2 - 1;
    ret.resize(size);
    for (int i = 0; i < ret.size(); i++) {
        ret[i].resize(size);
    }

    int gap = 0;
    while (gap <= size / 2) {
        for (int i = gap; i < size - gap; i++) {
            // top
            ret[gap][i] = A;
            // bottom
            ret[size - 1 - gap][i] = A;
            // left
            ret[i][gap] = A;
            // right
            ret[i][size - 1 - gap] = A;
        }
        gap++;
        A--;
    }

    return ret;
}

int main() {

    int A = 5;
    vector<vector<int>> ret = prettyPrint(A);
    for (int i = 0; i < A * 2 - 1; i++) {
        for (int j = 0; j < A * 2 - 1; j++) {
            printf("%d\t", ret[i][j]);
        }
        printf("\n");
    }


}