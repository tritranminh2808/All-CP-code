#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1001];
const int r=2000;
int b[r+1];
int xuli()
{
    vector<int> s, d;
    s = {0};
    while (!s.empty())
    {
        for (int k :s)
            for (int i=1;i<=n;++i)
            {
                int t = k+a[i];
                if (t >= 0&& t<=r&& b[t]==0)
                {
                    d.push_back(t);
                    b[t] = b[k] + 1;
                }
            }
        if (b[0] != 0) break;
        s.clear();
        swap(s, d);
    }
    return b[0];
}

int main() {
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++) {
    	cin >> a[i];a[i]-=m;
	}
    cout << xuli();
    return 0;
}

