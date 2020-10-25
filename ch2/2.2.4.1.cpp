#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;

int N, R;
int X[MAX_N];

void solve()
{
    sort(X, X + N);

    int i = 0, ans = 0;
    while (i < N)
    {
        // s 是沒有被覆蓋的最左的點的位置
        int s = X[i++];

        // 一直向右前進直到 s 的距離大於 R 的點
        while (i < N && X[i] <= s + R)
        {
            i++;
        }
        // p 是新加上標記的點的位置
        int p = X[i - 1];
        while (i < N && X[i] <= p + R)
        {
            i++;
        }
        ans++;
    }
    printf("%d\n", ans);
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
