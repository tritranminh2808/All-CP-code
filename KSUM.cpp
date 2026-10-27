#include <bits/stdc++.h>
using namespace std;
unsigned long long t,t2,t3;
int main(){
	freopen("KSUM.INP","r+",stdin);
	freopen("KSUM.OUT","w+",stdout);
	long long n,k;cin >> n >> k;int a[n];for(int i=0;i<n;i++){
		cin >> a[i];
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);for(int i=0;i<k;i++)
	{
		t+=a[i];
	}int j=0;t3=t;
	for(int i=k;i<n;i++)
	{
		t2= t+a[i]-a[j];
		if(t3<t2) t3=t2;
		t=t2;
		j++;
	}cout << t3;
	return 0;
}
