#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_N = 20;

int a[MAX_N];
int n, k;

bool dfs(int i, int sum)
{
    // 如果前 n 項都計算過了，則返回 sum 是否與 k 相等
    if (i == n)
    {
        return sum == k;
    }
    // 不加上 a[i] 的情況
    if(dfs(i + 1, sum))
    {
        return true;
    }
    // 加上 a[i] 的情況
    if (dfs(i + 1, sum + a[i]))
    {
        return true;
    }
    // 無論是否加上 a[i] 都不能湊成 k 就返回 false
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);

    if (dfs(0 ,0))
    {
        printf("Yes\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
