#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n; 
ll a[1000005];
// ll prxor[1000005];
ll k;
struct node{
    node *child[2];
    int cnt;
    node(){
        child[0]=NULL;
        child[1]=NULL;
        cnt=0;
    }
};

void update(ll &x,node &root){
    node *cur=&root;
    for(int i=32;i>=0;i--){
        bool b=(x>>i)&1;
        if(!cur->child[b]) cur->child[b]=new node();
        cur=cur->child[b];
        cur->cnt++;
    }
}
int dem=0;
void find(ll &x, node *v){
    for(int i=32;i>=0;i--){
        bool bk=(k>>i)&1,bx=(x>>i)&1;
        if(!bk){
            if(!v->child[bx]) return;
            v=v->child[bx];
        }
        else{
            
            if(v->child[bx]) dem+=v->child[bx]->cnt;
            if(!v->child[1-bx]) return;
            v=v->child[1-bx];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t;
    while(t--){
        cin >> n >> k;
        node root;
        for(int i=1;i<=n;i++) cin >> a[i];
        ll prx=0;
        ll ans=0;
        update(prx,root);
        for(int i=1;i<=n;i++){
            prx^=a[i];
            find(prx,&root);
            ans+=dem;
            dem=0;
            update(prx,root);
        }
        cout << ans << "\n";
    }
}