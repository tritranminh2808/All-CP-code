#include <bits/stdc++.h>
using namespace std;

struct segtri {
    int n; vector<int> t;
    segtri(int n): n(n), t(4*n) {}
    void upd(int v,int tl,int tr,int p,int val){
        if(tl==tr) t[v]=max(t[v],val);
        else{
            int tm=(tl+tr)/2;
            if(p<=tm) upd(v*2,tl,tm,p,val);
            else upd(v*2+1,tm+1,tr,p,val);
            t[v]=max(t[v*2],t[v*2+1]);
        }
    }
    int qry(int v,int tl,int tr,int l,int r){
        if(l>r) return 0;
        if(l==tl&&r==tr) return t[v];
        int tm=(tl+tr)/2;
        return max(qry(v*2,tl,tm,l,min(r,tm)),
                   qry(v*2+1,tm+1,tr,max(l,tm+1),r));
    }
    void update(int p,int val){ upd(1,0,n-1,p,val); }
    int query(int l,int r){ return qry(1,0,n-1,l,r); }
};

void solve(){
    int n; cin>>n;
    vector<int> a(n+1); a[0]=0;
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int &x:a) x=lower_bound(b.begin(),b.end(),x)-b.begin();
    
    vector<int> nxt(n+1,-1); 
    stack<int> s;
    for(int i=n;i>=0;i--){
        while(!s.empty() && a[s.top()]<a[i]) s.pop();
        if(!s.empty()) nxt[i]=s.top();
        s.push(i);
    }
    vector<vector<int>> pre(n+1);
    for(int i=0;i<=n;i++) if(nxt[i]!=-1) pre[nxt[i]].push_back(i);

    segtri st(b.size()); vector<int> d(n+1);
    for(int i=0;i<=n;i++){
        d[i]=st.query(0,a[i])+1;
        st.update(a[i],d[i]);
        for(int j:pre[i]) st.update(a[j],d[j]+1);
    }
    cout << st.query(0,b.size()-1)-1<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}
