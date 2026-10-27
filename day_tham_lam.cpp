#include <bits/stdc++.h>
using namespace std;
int a[1000005],nxt[1000005],f[1000005];
vector <int> adj[1000005];

int n,k;
struct pl{
    int val, lazy;
};
pl st[4000005];
void push(int id){
    st[id*2].val+=st[id].lazy;
    st[id*2].lazy+=st[id].lazy;
    st[id*2+1].val+=st[id].lazy;
    st[id*2+1].lazy+=st[id].lazy;
    st[id].lazy=0;
}
void update(int id, int l, int r, int lf,int rt, int v){
    if(lf>r||rt<l) return;
    if(lf<=l&&rt>=r){
        st[id].val+=v;
        st[id].lazy+=v;
        return;
    }
    push(id);
    int mid=(l+r)/2;
    update(id*2,l,mid,lf,rt,v);
    update(id*2+1,mid+1,r,lf,rt,v);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
}
int find(int id, int l, int r, int lf, int rt){
    if(lf>r||rt<l) return 0;
    if(lf<=l&&rt>=r) return st[id].val;
    push(id);
    int mid=(l+r)/2;
    return max(find(id*2,l,mid,lf,rt),find(id*2+1,mid+1,r,lf,rt));
}
int limit=0;
int ans[1000005];
int lo[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    stack<int> st;
    for(int i=n;i>=1;i--){
        while(!st.empty()&&a[i]>=a[st.top()]) st.pop();
        if(st.empty()) nxt[i]=n+1;
        else nxt[i]=st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++) lo[i]=i;
     for (int i=1;i<=n;i++) if (nxt[i]!=n+1) lo[nxt[i]]=min(lo[nxt[i]],lo[i]);
    for(int i=1;i<=n;i++){
        update(1,1,n,lo[i],i,1);
        if(i>=k) ans[i]=find(1,1,n,i-k+1,i);
    }
    for(int i=k;i<=n;i++) cout << ans[i] << " ";
    return 0;
}
