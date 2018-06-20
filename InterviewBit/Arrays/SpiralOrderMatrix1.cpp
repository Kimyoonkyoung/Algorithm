//
// Created by yoonkyoung on 2018. 6. 18..
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

vector<int> spiralOrder(const vector<vector<int> > &A) {

#ifdef MORE_MEMORY
    std::vector<int> spiral;

    int width = (int)A[0].size();
    int height = (int)A.size();

    if (width == 1 && height == 1) {
        spiral.push_back(A[0][0]);
        return spiral;
    }

    if (width == 1 && height > 1) {
        for (int i = 0; i < height; i++)
            spiral.push_back(A[i][0]);
        return spiral;
    }

    if (height == 1 && width > 1) {
        for (int i = 0; i < width; i++)
            spiral.push_back(A[0][i]);
        return spiral;
    }

    bool visited[height][width];
    std::memset(visited, false, sizeof(visited));

    Point right, left, down, up;
    right.x = 0; right.y = 0;
    left.x = width-2; left.y = height-1;
    down.x = width-1; down.y = 1;
    up.x = 0; up.y = height-2;

    while (right.y <= (height>>1) && left.y >= (height>>1)
           && down.x >= (width>>1) && up.x <= (width>>1)) {

        // right 전진
        int initX = right.x;
        int initY = right.y;
        while (right.x < width && !visited[right.y][right.x]) {
            spiral.push_back(A[right.y][right.x]);
            visited[right.y][right.x] = true;
            right.x++;
        }
        right.x = initX + 1;
        right.y = initY + 1;

        // down 전진
        initX = down.x;
        initY = down.y;
        while (down.y < height && !visited[down.y][down.x]) {
            spiral.push_back(A[down.y][down.x]);
            visited[down.y][down.x] = true;
            down.y++;
        }
        down.x = initX - 1;
        down.y = initY + 1;

        // left 전진
        initX = left.x;
        initY = left.y;
        while (left.x >= 0 && !visited[left.y][left.x]) {
            spiral.push_back(A[left.y][left.x]);
            visited[left.y][left.x] = true;
            left.x--;
        }
        left.x = initX - 1;
        left.y = initY - 1;

        // up 전진
        initX = up.x;
        initY = up.y;
        while (up.y > 0 && !visited[up.y][up.x]) {
            spiral.push_back(A[up.y][up.x]);
            visited[up.y][up.x] = true;
            up.y--;
        }
        up.x = initX + 1;
        up.y = initY - 1;
    }
#endif // MORE_MEMORY

#define FASTEST
#ifdef FASTEST
    std::vector<int> spiral;

    int width = (int)A[0].size();
    int height = (int)A.size();

    if (width == 1 && height == 1) {
        spiral.push_back(A[0][0]);
        return spiral;
    }

    if (width == 1 && height > 1) {
        for (int i = 0; i < height; i++)
            spiral.push_back(A[i][0]);
        return spiral;
    }

    if (height == 1 && width > 1) {
        for (int i = 0; i < width; i++)
            spiral.push_back(A[0][i]);
        return spiral;
    }

    bool visited[height][width];
    std::memset(visited, false, sizeof(visited));

    int top = 0;
    int bottom = (int)A.size() - 1;
    int left = 0;
    int right = (int)A[0].size() - 1;

    int i;
    while (top <= bottom && left <= right) {

        // to right
        for (i = left; i <= right; i++) {
            spiral.push_back(A[top][i]);
        }
        top++;

        // to bottom
        for (i = top; i <= bottom; i++) {
            spiral.push_back(A[i][right]);
        }
        right--;

        // to left
        for (i = right; i >= left; i--) {
            spiral.push_back(A[bottom][i]);
        }
        bottom--;

        // to top
        for (i = bottom; i >= top; i--) {
            spiral.push_back(A[i][left]);
        }
        left++;

    }
#endif // FASTEST

    return spiral;

}


int main() {
    vector<vector<int>> A;
    vector<int> sub;

    sub.push_back(1);
    sub.push_back(2);
    sub.push_back(3);
    sub.push_back(4);
    A.push_back(sub);

    sub.clear();
    sub.push_back(3);
    sub.push_back(4);
    sub.push_back(5);
    sub.push_back(6);
    A.push_back(sub);

    sub.clear();
    sub.push_back(5);
    sub.push_back(6);
    sub.push_back(5);
    sub.push_back(6);
    A.push_back(sub);

    vector<int> ret = spiralOrder(A);
    for (int i = 0; i < ret.size(); i++)
        printf("%d, ", ret[i]);

}