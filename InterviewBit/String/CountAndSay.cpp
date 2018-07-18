/**
 * Created by Rachel.minii 
 * Date : 2018. 7. 19.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>

using namespace std;

string countAndSay(int A) {

    if (A == 1)
        return "1";

    if (A == 2)
        return "11";

    string ret = "11";

    for (int i = 2; i < A; i++) {
        string startStr = ret;
        ret = "";

        for (int j = 0; j < startStr.size(); j++) {
            int cnt = 1;
            char curChar = startStr[j];

            // while same char
            while (startStr[j] == startStr[j+1]) {
                cnt++;
                j++;
            }

            ret += std::to_string(cnt);
            ret += curChar;
        }
    }

    return ret;
}


int main() {

    printf("%s", countAndSay(5).c_str());

    return 0;
}