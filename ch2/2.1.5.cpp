#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int INF = 100000000;

// 使用 pair 表示狀態時，使用 typedef 會更加方便一些
typedef pair<int, int> P;

// 輸入
const int MAX_N = 100;
const int MAX_M = 100;
char maze[MAX_N][MAX_M + 1]; // 表示迷宮的字符串數組
int N, M;
int sx, sy; // 起點座標
int gx, gy; // 終點座標

int d[MAX_N][MAX_M]; // 到各個位置的最短距離的數組

// 4 個方向的移動向量 右上左下
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0 ,-1};

// 求從 (sx, sy) 到 (gx, gy) 的最短距離
// 如果無法到達，則是 INF
int bfs()
{
    queue<P> que;
    // 把所有位置初始化為 INF
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; i < M; j++)
        {
            d[i][j] = INF;
        }
    }
    // 將起點加入隊列，並把這一地點的距離設為 0
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    // 不斷循環直到隊列的長度為 0
    while (que.size())
    {
        // 從隊列的最前端取出元素
        P p = que.front();
        que.pop();
        // 如果取出的狀態已是終點，則結束搜索
        if(p.first == gx && p.second == gy)
        {
            break;
        }

        // 朝四個方向循環
        for (int i = 0; i < 4; i++)
        {
            // 移動後的位置標記為 (nx, ny)
            int nx = p.first + dx[i], ny = p.second + dy[i];

            // 判斷是否可以移動以及是否已經訪問過 (d[nx][ny] != INF 即已經訪問過)
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
            {
                // 可以移動的話，則加入隊列，並且到該位置的距離確定為到 p 的距離 +1
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}
int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%c", &maze[i][j]);
            if(maze[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (maze[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
        }
    }
    
    int res = bfs();

    printf("%d\n", res);

    return 0;
}
