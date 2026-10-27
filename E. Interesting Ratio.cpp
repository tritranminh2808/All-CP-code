#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],check[10000005],r[1000005];
void txl(){
	for(int i=2;i*i<=10000005;i++)
	{
		if(check[i]!=0) continue;
		else
		{
			for(int k=i;i*k<=10000005;k++)
			{
				check[i*k]=1;
			}
		}		
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	txl();
	vector <int> snt;
	for(int i=2;i<=10000005;i++) if(check[i]==0) snt.push_back(i);
	int t; cin>> t;
	while(t--){
		int n; cin >> n;
		int sol=0;
		for(auto i : snt){
			if(i>n) break;
			sol+=n/i;
		}
		cout << sol << "\n";
	}
	return 0;
}
