#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;

// input
int n, w;
int W[MAX_N], V[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

// 從第 i 個商品物品開始挑選總中小於 j 的部份
int rec(int i, int j)
{
    if (dp[i][j] >= 0)
    {
        /* 如果已經計算過就直接用之前的結果 */
        return dp[i][j];
    }
    int res;
    if (i == n)
    {
        // 已經沒有剩下任何東西
        res = 0;
    }
    else if (j < W[i])
    {
        // 無法挑選這個物品
        res = rec(i + 1, j);
    }
    else
    {
        // 挑選和不挑選的兩種情況都嘗試一下
        res = max(rec(i + 1, j), rec(i + 1, j - W[i]) + V[i]);
    }
    
    // 將結果紀錄到數組中
    return dp[i][j] = res;
}

// 用 for 循環實現同樣的遞歸動態規劃
void solve()
{
    int dp[MAX_N + 1][MAX_W + 1];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j < W[i])
            {
                dp[i][j] = dp[i + 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - W[i]] + V[i]);
            }
        }
    }
    printf("%d\n", dp[0][w]);
}

int main(int argc, char const *argv[])
{
    // 用 -1 表示尚未計算過，初始化整個數組
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, w));
    return 0;
}
