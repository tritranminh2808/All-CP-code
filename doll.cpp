#include <bits/stdc++.h>
using namespace std;
long long a[100000], b[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0 ; i < n; i ++)
    {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    sort (a, a +n);
    sort (b, b + n);
    for (int i = n - 1; i >= 0; i --)
    {
        for (int j = i - 1; j >= 0 ; j --)
        {
            if (b[j] <= a[i] - k) 
            {
                sum -= b[j];
                b[j] = 1000000001;
                break;
            }
        }
    }        
    cout << sum;

}
