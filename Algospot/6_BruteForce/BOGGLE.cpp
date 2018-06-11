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


using namespace std;

string _word;
char _board[5][5];

int findWord(int y, int x, int idx) {
    if (_word.at(idx) != _board[y][x])
        return 0;

    idx++;

    // 끝까지 왔다! 성공!
    if (idx >= _word.size())
        return 1;


    return findWord(y-1, x-1, idx) || findWord(y-1, x, idx) || findWord(y-1, x+1, idx)
           || findWord(y, x-1, idx) || findWord(y, x+1, idx)
           || findWord(y+1, x-1, idx) || findWord(y+1, x, idx) || findWord(y+1, x+1, idx);
}

void boggle() {

    bool visited[5][5][10];

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
            //std::memset(visited, 0, sizeof(visited)); // 방문했을 당시에 T/F 저장

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
    int numCase = 1;
    //scanf("%d", &numCase);

    if (numCase <= 0 || numCase > 50)
        return false;

    while (numCase--) boggle();
}