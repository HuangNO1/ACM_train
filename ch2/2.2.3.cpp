#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2000;

// 輸入
int N;
char S[MAX_N + 1];

void solve()
{
    // 剩餘的字符串為 S[a], S[a+1], ...,S[b]
    int a = 0, b = N - 1;

    while (a <= b)
    {
        // 從左起和右起的字符串
        bool left = false;

        for (int i = 0; a + i < b; i++)
        {
            if (S[a + i] < S[b - i])
            {
                left = true;
                break;
            }
            else if (S[a + i] > S[b  - i])
            {
                left = false;
                break;
            }
        }
        
        if (left)
        {
            putchar(S[a++]);
        }
        else
        {
            putchar(S[b--]);
        }
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
