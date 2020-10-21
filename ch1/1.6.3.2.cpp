#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 50;

int n, m, k[MAX_N];

// 保存兩個數的和的數列
int kk[MAX_N * MAX_N];

bool binary_search(int x)
{
    int l = 0, r = n * n;

    while (r - 1 >= 1)
    {
        int i = (l + r) / 2;
        if (kk[i] == x)
        {
            return true;
        }
        else if (kk[i] < x)
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
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }

    for (int c = 0; c < n; c++)
    {
        for (int d = 0; d < n; d++)
        {
            kk[c * n + d] = k[c] + k[d];
        }
    }

    sort(kk, kk + n * n);

    bool f = false;

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {

            // 最內側的改成二分查找
            if (binary_search(m - k[a] - k[b]))
            {
                f = true;
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
