#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int N, M;
char field[MAX_N][MAX_M + 1]; // 因子

// 現在位置 (x, y)
void dfs(int x, int y)
{
    // 將現在所在位置替換為 .
    field[x][y] = '.';

    // 循環遍歷移動的 8 個方向
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            // 向 x 方向移動 dx, 向 y 方向移動 dy，移動結果為 (nx, ny)
            int nx = x + dx, ny = y + dy;

            // 判斷 (nx, ny) 是不是在園子內，以及是否有積水
            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'w')
            {
                dfs(nx, ny);
            }
        }
    }
    return;
}

void solve()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%c", &field[i][j]);
        }
        
    }
    
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (field[i][j] == 'w')
            {
                // 從有 w 的地方開始 dfs
                dfs(i, j);
                res ++;
            }
        }
    }
    printf("%d\n", res);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
