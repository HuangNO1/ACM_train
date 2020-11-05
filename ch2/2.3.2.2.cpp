#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100;
const int MAX_V = 1000000000;

int n, w;
int W[MAX_N], V[MAX_N];

int dp[MAX_N + 1][MAX_N * MAX_V + 1];

void solve()
{
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, MAX_V);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= MAX_N * MAX_V ; j++)
        {
            if (j < V[i])
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - V[i]] + W[i]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= MAX_N * MAX_V; i++)
    {
        if (dp[n][i] <= w)
        {
            res = i;
        }
    }
    printf("%d\n", res);
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}
