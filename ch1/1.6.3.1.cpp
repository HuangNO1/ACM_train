#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 50;

int n, m, k[MAX_N];

// 二分搜索
bool binary_search(int x)
{
    int l = 0, r = n;

    while (r - 1 >= 1)
    {
        int i = (l + r) / 2;
        if (k[i] == x)
        {
            return true;
        }
        else if(k[i] < x)
        {
            l = i + 1;
        }
        else
        {
            r = i;
        }
    }
    return false;
}

void solve()
{
    scanf("%d %d", &n , &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }

    sort(k, k + n);

    bool f = false;

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            for (int c = 0; c < n; c++)
            {
                // 最內側的改成二分查找
                if (binary_search(m - k[a] - k[b] - k[c]))
                {
                    f = true;
                }
            }
        }
    }
    if (f)
    {
        puts("Yes");
    }
    else
    {
        puts("NO");
    }
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
