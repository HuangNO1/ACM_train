#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    int n = 0, ans = 0;

    cin >> n;

    int a[n] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int len = a[i] + a[j] + a[k];
                int max_num = max(a[i], max(a[j], a[k]));

                if (max_num < len - max_num)
                {
                    ans = max(ans, len);
                }
            }
        }
    }

    cout << ans;

    return 0;
}