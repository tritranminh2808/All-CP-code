#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair <int, int > a, pair <int, int > b){
    return a.first<b.first;
}
void solve(int n, int d, int k, int a, int b){
    vector <int> fib;
    fib.push_back(a);
    fib.push_back(b);
    map<int,int> mp;
    bool ck1=false,ck2=false;
    for (int i=2;i<n;i++) {
        fib.push_back((fib[i-1]%d + fib[i-2]%d)%d);
        mp[fib[i]]++;
        if(i>3){
            if(!ck1) {
            	if(fib[i]==fib[2]) ck1=true;
            }
            
            else if(fib[i]==fib[3]){
            	ck2=true;break;
			}
			else ck1=false;
        }
    }
    if(ck2){
    	mp[fib.back()]--;
    	fib.pop_back();
    	mp[fib.back()]--;
    	fib.pop_back();
	}
	if(fib.size()<=2) return;
    int z=(n-2)/(fib.size()-2);
    int zz=(n-2)%(fib.size()-2);
    for (auto it = mp.begin();it!=mp.end();++it){
		(*it).second *= z;
	}
    for(int i=2;i<zz+2;i++){
        mp[fib[i]]++;
    }
    mp[a]++,mp[b]++;
    for (auto i:mp){
		if(k>i.second){
			k-=i.second;
		}else{
			cout << i.first << "\n";
			break;
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,d,k,a,b;
        cin >> n >> d >> k >> a >> b;
        if(n==1) cout << a << "\n";
        if(n==2) {
        	if(k==1) cout << min(a,b)<< "\n";
        	else cout << max(a,b) << "\n";
        }
        else solve(n,d,k,a,b);
    }
    return 0;
}

