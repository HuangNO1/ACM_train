#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;

int n, w;
int W[MAX_N], V[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j < W[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - W[i]] + V[i]);
            }
        }
    }
    printf("%d\n", dp[n][w]);
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
