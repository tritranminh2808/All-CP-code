#include <bits/stdc++.h>
#define int long long
using namespace std;
int node=0;
int st[256][500005],cnt[1000005];
void update(string s, int v){
    int id=0;
    for(int i=0;i<s.length();i++){
        int nid=st[s[i]][id];
        if(nid==-1){
            st[s[i]][id]=++node;
            nid=node;
        }
        cnt[nid]+=v;
        id=nid;
    }
}
int query(string s){
    int id=0;
    for(int i=0;i<s.length();i++){
        int nid=st[s[i]][id];
        if(nid==-1||cnt[nid]<=0) return 0;
        id=nid;
    }
    return cnt[id];
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    memset(st,-1,sizeof(st));
    cin >> q;
    while(q--){
        int o;
        cin >> o;
        // cout << o << "\n";
        string s; cin >> s;
        string a=s;
        // for(int i=1;i<s.length()-1;i++) a+=s[i];
        // cout << a << "\n";
        if(o==1) update(a,1);
        else if(o==2) update(a,-1);
        else if(o==3) cout << query(a) << "\n";
    }

    return 0;
}