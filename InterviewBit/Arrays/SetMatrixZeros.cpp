/**
 * Created by Rachel.minii 
 * Date : 2018. 6. 22.
 * Project : Algorithm
 */

#include <climits>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Point {
    int x;
    int y;
};

void setZeroes(vector<vector<int> > &A)
{
    size_t height = A.size();
    size_t width  = A[0].size();

    vector<Point> zero;
    Point p;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (A[i][j] == 0) {
                p.x = j; p.y = i;
                zero.push_back(p);
            }
        }
    }

    for (int i = 0; i < (int)zero.size(); i++) {
        // set row
        for (int j = 0; j < height; j++) {
            A[j][zero[i].x] = 0;
        }
        // set column
        for (int j = 0; j < width; j++){
            A[zero[i].y][j]  = 0;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            printf("%d, ", A[i][j]);
        }
        printf("\n");
    }
}


int main() {
    vector<vector<int>> A;
    vector<int> sub;

    sub.push_back(1);
    sub.push_back(0);
    sub.push_back(1);
    A.push_back(sub);

    sub.clear();
    sub.push_back(1);
    sub.push_back(1);
    sub.push_back(1);
    A.push_back(sub);

    sub.clear();
    sub.push_back(1);
    sub.push_back(1);
    sub.push_back(1);
    A.push_back(sub);

    setZeroes(A);
}