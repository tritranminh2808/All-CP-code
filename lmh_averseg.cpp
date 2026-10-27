#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        if (c <= a || c >= b) cout << 1 << "\n";
        else if (c * 2 == a + b) cout << 2 << "\n";
        else
        {
            if (c * 2 > a + b) swap(a, b);
            b -= a;
            c -= a;
            long long mk = abs(b - 2 * c);
            if (mk == 0)
            {
                cout << 2 << "\n";
                continue;
            }
            long long k = abs(c) / mk;
            long long p1 = abs(b * k - c * (2 * k + 1));
            long long q1 = 2 * k + 1;
            long long p2 = abs(b * (k + 1) - c * (2 * k + 3));
            long long q2 = 2 * (k + 1) + 1;
            if (p1 * q2 > p2 * q1) k++;
            cout << 2 * k + 1 << "\n";
        }
    }
}