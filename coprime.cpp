#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,l,r;
    cin >> n >> l >> r;
    int x=n;
    vector<int> a;
    for(int i=2;i*i<=n;++i){
    	if(n%i==0) a.push_back(i);
    	while(n%i==0) n/=i;
	}
	if(n!=1) a.push_back(n);
	n=x;
    int ans=0,k=a.size();
    for(int mask=1;mask<(1<<k);mask++){
        int lcm=1,bit=0;
        bool sech=1;
        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
                if(lcm>n/a[i]) { 
                    sech=0; 
                    break; 
                }
                lcm*=a[i]; 
                bit++;
            }
        }
        if(!sech) continue;
        int cnt=r/lcm-(l-1)/lcm;
        if(bit&1) ans+=cnt;
        else ans-=cnt;
    }
    cout << r-l+1-ans;
    return 0;
}

