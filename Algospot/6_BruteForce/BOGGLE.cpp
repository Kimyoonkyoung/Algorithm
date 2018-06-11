//
// Created by yoonkyoung on 2018. 6. 7..
//

/**
 * 있는지 없는지만 확인하면 됨!!
 * 어디에 있는지?! 중요하지 않음
 * 끝까지 갔다가 1 로 돌아오는지만 체크
 * @return
 */

#include <iostream>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

string _word;
char _board[5][5];
int _visited[5][5][10];

int findWord(int y, int x, int idx) {
    // 영역 예외처리
    if (y >= 5 || x >= 5 || y < 0 || x < 0)
        return 0;

    // 이미 방문한 index 는 recursive 안돌고 패스
    if (_visited[y][x][idx])
        return _visited[y][x][idx];

    // 현재위치 현재단어 검사
    if (_word.at(idx) != _board[y][x])
        return _visited[y][x][idx] = 0;

    // final case : 끝까지 왔다! 성공!
    idx++;
    if (idx >= _word.size())
        return 1;

    return _visited[y][x][idx] = (findWord(y-1, x-1, idx) || findWord(y-1, x, idx) || findWord(y-1, x+1, idx)
                                  || findWord(y, x-1, idx) || findWord(y, x+1, idx)
                                  || findWord(y+1, x-1, idx) || findWord(y+1, x, idx) || findWord(y+1, x+1, idx));
}


void boggle() {

    // read test case
    int testCase;
    scanf("%d\n", &testCase);

    for (int i = 0; i < testCase; i++) {

        // set _board
        for (int i = 0; i < 5; i++)
            scanf("%c%c%c%c%c\n", &_board[i][0], &_board[i][1], &_board[i][2], &_board[i][3], &_board[i][4]);

        // read num word
        int numWord;
        scanf("%d\n", &numWord);

        for (int i = 0; i < numWord; i++) {

            // initialize
            memset(_visited, 0, sizeof(_visited));
            _word.clear();

            getline(cin, _word);

            // 모든 board 에 대해 탐색
            bool find = false;
            for (int y = 0; y < 5; y++) {

                for (int x = 0; x < 5; x++) {

                    if (findWord(y, x, 0)) {
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
            }

            if (find) {
                printf("%s %s\n", _word.c_str(), "YES");
            }
            else {
                printf("%s %s\n", _word.c_str(), "NO");
            }

        }
    }
}

int main() {
    boggle();
}