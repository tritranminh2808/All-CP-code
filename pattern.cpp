#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
bool checkbeo(char ch,int d){
    if(ch>='0' && ch<='9') return d==(ch-'0');
    if(ch=='?') return true;
    if(ch>='a' && ch<='g'){
        int l=ch-'a';
        return d>=l && d<=l+3;
    }
    return false;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        string a,b;cin>>a>>b;
        int sol=1,n=a.size();
        bool chck=true;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int d=0;d<10;d++){
                if(checkbeo(a[i],d) && checkbeo(b[i],d)) cnt++;
            }
            if(cnt==0){chck=false; break;}
            sol=(sol*cnt)%mod;
        }
        cout<<(chck? sol : 0)<<"\n";
    }
    return 0;
}

