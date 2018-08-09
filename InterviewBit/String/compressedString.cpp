/**
 * Created by Rachel.minii 
 * Date : 2018. 8. 7.
 * Project : Algorithm
 */
#include <climits>
#include <iostream>

using namespace std;


string compressedString(string message)
{
    string out;
    int i = 0;
    int count = 1;

    while(message[i] != '\0')
    {
        char prev = message[i];
        char curr = message[i+1];

        if(prev != curr)
        {
            out += prev;

            if(count>1)
            {
                out += to_string(count);
                count=1;
            }
        }
        else {
            count++;
        }

        i++;
    }

    return out;
}

int main() {

    printf("%s", compressedString("a").c_str());

    return 0;
}