#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

// 輸入
int N, S[MAX_N], T[MAX_N];

// 用於對工作排序的 pair 數組
pair<int, int> itv[MAX_N];

int main(int argc, char const *argv[])
{
    // 對 pair 進行的是字典序比較
    // 為了讓結束時間早的工作排在前面，把 T 存入 first，把 S 存入 second
    for (int i = 0; i < N; i++)
    {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }

    sort(itv, itv + N);

    // t 是最後所選工作的結束時間
    int ans = 0, t = 0;
    for (int i = 0; i < N; i++)
    {
        if (t < itv[i].second)
        {
            ans++;
            t = itv[i].first;
        }
    }

    printf("%d\n", ans);

    return 0;
}
