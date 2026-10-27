#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int a[1000000];
    long long v, i1,i3;
    int x = 0,y = 0, x1 = 0, y1= 0;
    bool check = 0, check1 = 0;
    for( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> v;
    for( i1 = 0; i1 < n; i1++)
    {
        if (check == 0 && a[i1]==v)
        {
            x = i1;
            x1 = x1 + 1;
            check = 1;
        }
        if (check1 == 0 && a[n-i1-1] > v)
        {
            y = n-i1-1;
            y1 = y1 + 1 ;
            check1 = 1;
        }
        if (check == 1 && check1 == 1)
        {
            break;
        }
    }
    if ( x1 != 0)
    {
        cout << x+1 << endl;
    }
    if (x1 == 0)
    {
        cout << 0 << endl;
    }
    if (y1 != 0)
    {
        cout << y + 1 << endl;
    }
    if (y1==0)
    {
        cout << 0 << endl;
    }
    for( int i3 = 1; i3 < n+1; i3++)
    {
        if (a[i3] < v)
        {
            cout << i3 << " ";
        }
    }

}
