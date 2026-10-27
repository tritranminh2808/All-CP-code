#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[100005],a[100005],check[100005];
signed main()
{
	freopen("balance.INP","r",stdin);
	freopen("balance.OUT","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<int, vector <int> > mp;
	int n;cin >> n;for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
		mp[a[i]].push_back(i);
	}
	for(auto i :mp){
		int count = 0;
        for (auto j = i.second.size()-1; j >= 1; j--)
        {
            check[i.second[j-1]+1] += (i.second.size()-count-1)*(count+1);
            check[i.second[j]+1] -= (i.second.size()-count-1)*(count+1);
            count++;
        }
	}
	for(int i=1;i<=n;i++)
	{
		check[i]=check[i-1]+check[i];
		cout << check[i] << " ";
	}
	return 0;
}
