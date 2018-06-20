//
// Created by yoonkyoung on 2018. 6. 20..
//

#include <climits>
#include <vector>
#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

vector<vector<int>> generateMatrix(int A) {
    vector<vector<int>> ret;
    ret.resize(A);
    for (int i = 0; i < A; i++) {
        ret[i].resize(A);
    }

    if (A == 1) {
        ret[0][0] = 1;
        return ret;
    }

    bool visited[A][A];
    std::memset(visited, false, sizeof(visited));

    Point right, left, down, up;
    right.x = 0; right.y = 0;
    left.x = A-2; left.y = A-1;
    down.x = A-1; down.y = 1;
    up.x = 0; up.y = A-2;

    int val = 1;

    while (right.y <= (A>>1) && left.y >= (A>>1)
           && down.x >= (A>>1) && up.x <= (A>>1)) {

        // right 전진
        int initX = right.x;
        int initY = right.y;
        while (right.x < A && !visited[right.y][right.x]) {
            ret[right.y][right.x] = val++;
            visited[right.y][right.x] = true;
            right.x++;
        }
        right.x = initX + 1;
        right.y = initY + 1;

        // down 전진
        initX = down.x;
        initY = down.y;
        while (down.y < A && !visited[down.y][down.x]) {
            ret[down.y][down.x] = val++;
            visited[down.y][down.x] = true;
            down.y++;
        }
        down.x = initX - 1;
        down.y = initY + 1;

        // left 전진
        initX = left.x;
        initY = left.y;
        while (left.x >= 0 && !visited[left.y][left.x]) {
            ret[left.y][left.x] = val++;
            visited[left.y][left.x] = true;
            left.x--;
        }
        left.x = initX - 1;
        left.y = initY - 1;

        // up 전진
        initX = up.x;
        initY = up.y;
        while (up.y > 0 && !visited[up.y][up.x]) {
            ret[up.y][up.x] = val++;
            visited[up.y][up.x] = true;
            up.y--;
        }
        up.x = initX + 1;
        up.y = initY - 1;
    }

    return ret;
}


int main() {

    int A = 1;
    vector<vector<int>> ret = generateMatrix(A);
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            printf("%d, ", ret[i][j]);
        }
        printf("\n");
    }
}