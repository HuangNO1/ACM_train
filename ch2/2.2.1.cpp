#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// 硬幣面值
const int V[6] = {1, 5, 10, 50, 100, 500};

// 輸入
int C[6]; // C[0] = C_1, C[1] = C_5 ...
int A;

int main(int argc, char const *argv[])
{
    int ans = 0;
    scanf("%d", &A);

    for (int i = 5; i >= 0; i--)
    {
        int t = min(A / V[i], C[i]); // 使用硬幣 i 的枚數
        A -= t * V[i];
        ans += t;
    }

    printf("%d\n", ans);
    
    return 0;
}
