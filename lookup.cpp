#include <bits/stdc++.h>
using namespace std;
long long a[1000005],pre[1000005];
string s;
int n,m;
void find(long long x){
//	cout << x << "\n";
	if(x<=s.size()) {
		cout << s[x-1] << "\n";
		return;
	}
	auto cur=lower_bound(pre+1,pre+n+1,x)-pre-1;
	find(1+pre[cur+1]-x);
//	cout << pre[cur] << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cin >> n >> m;
	cin >> s;
	pre[0]=s.size();
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pre[i]=pre[i-1]+a[i];
	}
	while(m--) 
	{
		long long l;cin>>l;
		find(l);
	}
	return 0;
}
