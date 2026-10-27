#include <bits/stdc++.h>
using namespace std;
vector <int> pos[300005];
struct segtri{
    int n;
    vector <int> st;
    segtri(int sz){
        n=sz;
        st.resize(4*sz);
        for(int i=0;i<st.size();i++) st[i]=INT_MAX;
    }
    void update(int id, int l, int r, int u, int v){
        if(u<l||u>r) return;
        if(l==r){
            st[id]=v;
            return;
        }
        int mid=(l+r)/2;
        update(id*2,l,mid,u,v);
        update(id*2+1,mid+1,r,u,v);
        st[id]=min(st[id*2],st[id*2+1]);
    }
    int find(int id, int l,int r, int lf, int rt){
        if(lf>r||rt<l) return INT_MAX;
        if(lf<=l&&rt>=r) return st[id];
        int mid=(l+r)/2;
        return min(find(id*2,l,mid,lf,rt),find(id*2+1,mid+1,r,lf,rt));
    }
};
void cok(){
    int n; cin >> n;
    vector <int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        pos[a[i]].clear();
    }
    segtri s(n+2);
    for(int i=1;i<=n;++i) {
        cin >> b[i];
        pos[b[i]].clear();
    }
    for(int i=1;i<=n;++i) pos[a[i]].push_back(i);
    for(int i=1;i<=n;i++) s.update(1,1,n+1,a[i],pos[a[i]][0]);
    
    for(int i=1;i<=n;i++){
        if(pos[b[i]].empty()){
            cout << "NO\n";
            return;
        }
        int x=*pos[b[i]].begin();
        pos[b[i]].erase(pos[b[i]].begin());
        if(s.find(1,1,n+1,1,b[i])<x){
            cout << "NO\n";
            return;
        }
        int val=INT_MAX;
        if(!pos[b[i]].empty()) val=pos[b[i]][0];
        s.update(1,1,n+1,b[i],val);
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        cok();
    }
    return 0;
}