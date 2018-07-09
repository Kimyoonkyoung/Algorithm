/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 9.
 * Project : Algorithm
 */

#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int row = (int)A.size();
    int col = (int)A[0].size();

    if (row == 1 && col == 1) {
        if (A[0][0] == B)
            return 1;
        else
            return 0;
    }

    if (B < A[0][0])
        return 0;
    if (B > A[A.size()-1][A[0].size()-1])
        return 0;

    int targetRow;
    for (targetRow = -1; targetRow < row - 1; targetRow++) {
        if (A[targetRow + 1][0] > B)
            break;
    }

    int start = 0, end = col - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[targetRow][mid] < B) {
            start = mid + 1;
        }
        else if (A[targetRow][mid] > B) {
            end = mid - 1;
        }
        else if (A[targetRow][mid] == B) {
            return 1;
        }
    }

    return 0;

}

int main() {
    vector<vector<int>> A;
    vector<int> sub;

    sub.push_back(1);
    sub.push_back(2);
    sub.push_back(3);
    sub.push_back(4);
    sub.push_back(5);
    A.push_back(sub);

    sub.clear();
    sub.push_back(6);
    sub.push_back(7);
    sub.push_back(8);
    sub.push_back(9);
    sub.push_back(10);
    A.push_back(sub);

    sub.clear();
    sub.push_back(11);
    sub.push_back(12);
    sub.push_back(13);
    sub.push_back(14);
    sub.push_back(15);
    A.push_back(sub);

    sub.clear();
    sub.push_back(16);
    sub.push_back(17);
    sub.push_back(18);
    sub.push_back(19);
    sub.push_back(20);
    A.push_back(sub);

    sub.clear();
    sub.push_back(21);
    sub.push_back(22);
    sub.push_back(23);
    sub.push_back(24);
    sub.push_back(25);
    A.push_back(sub);

    int ret = searchMatrix(A, 30);
    printf("%d\n", ret);

    return 0;
}