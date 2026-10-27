#include <bits/stdc++.h>
#define int long long
using namespace std;
long long res=9999999999,k;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("CANBANG.inp","r",stdin);
	freopen("CANBANG.out","w",stdout);
	int a,b;
	cin >> a >> b;
	
	int stt=b-a+1;
	
	long long tong=(a+b)*stt/2;
	
	long long t1=0;
	for(int i=a;i<=b;i++){
		t1+=i;
		tong-=i;
		if(abs(tong-t1)<res) {
			res=abs(tong-t1);
			k=i;
		}
		//cout << tong <<  " " << t1 << endl;
	}
	cout << k;
	return 0;
}
