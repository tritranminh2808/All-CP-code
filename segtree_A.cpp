#include <bits/stdc++.h>
using namespace std;
string s;
int st[26][400005];
void update(int x,int id ,int l, int r, int u, int v){
    if(l>u||r<u) return;
    if(l==r){
        st[x][id]=v;
        return;
    }
    int mid=(l+r)/2;
    update(x,id*2,l,mid,u,v);
    update(x,id*2+1,mid+1,r,u,v);
    st[x][id]=st[x][id*2]+st[x][id*2+1];
}
int find(int x,int id, int l, int r, int lf, int rt){
    if(lf>r||rt<l) return 0;
    if(lf<=l&&rt>=r) return st[x][id];
    int mid=(l+r)/2;
    int f1=find(x,id*2,l,mid,lf,rt),f2=find(x,id*2+1,mid+1,r,lf,rt);
    return f1+f2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n=s.length();
    s='!'+s;
    for(int i=1;i<=n;i++ ) update(s[i]-'a',1,1,n,i,1);
    int q; cin >> q;
    while(q--){
        int qq; cin >> qq;
        if(qq==1){
            int u; char c;
            cin >> u >> c;
            char g=s[u];
            s[u]=c;
            update(g-'a',1,1,n,u,0);
            update(c-'a',1,1,n,u,1);
        }
        else {
            int l, r; cin >> l >> r;
            int sol=0;
            for(int i=0;i<=25 ;i++){
                if(find(i,1,1,n,l,r)) sol++;
            }
            cout << sol << "\n";
        }
    }
    return 0;
}