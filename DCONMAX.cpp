#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
const long long INF = 1e7 + 5;
long long n, a[MAXN];

int main()
{
    freopen("DCONMAX.INP","r",stdin);
    freopen("DCONMAX.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long res = -INF, sum = 0, mins = 0;
    int start=0,end=0,cs=0;
    /*for (int i = 0; i < n; i++)
    {
    	sum=max(a[i], sum+a[i]);
    	res=max(sum,res);
    }
    cout << res << "\n";*/
    sum=0;
    res=-INF;
    for(int i=0;i<n;i++){
    	if(sum+a[i]<a[i]){
    		cs=i;
    		sum=a[i];
		}
		else sum+=a[i];
		if(res<sum){
			res=sum;
			start=cs;
			end=i;
		}
	}
    cout << res << "\n" << start << " " << end;
    return 0;
}
