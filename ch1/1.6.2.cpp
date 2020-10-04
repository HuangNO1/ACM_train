#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    int L = 0, n = 0;
    int minT = 0, maxT = 0;

    cout << "L -> ";
    cin >> L;

    cout << "n -> ";
    cin >> n;

    int x[n] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    
    for (int  i = 0; i < n; i++)
    {
        minT = max(minT, min(x[i], L - x[i]));
    }

    for (int i = 0; i < n; i++)
    {
        maxT = max(maxT, max(x[i], L - x[i]));
    }

    cout << "minT : " << minT << ", maxT : " << maxT << endl;
    
    return 0;
}