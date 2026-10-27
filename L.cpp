#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
int a[100005],ans[100005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int> lf,rt;
    unordered_set<int> in;
    int cur=0;
    for(int i=0;i<n;i++){
        int v=a[i];
        if(!in.count(v)){
            bool l=rt.count(v-1), r=lf.count(v+1);
            if(!l&&!r){
                lf[v]=v; rt[v]=v;
                cur++;
            } 
            else if(l&&!r){
                int l=rt[v-1], r=v-1;
                int o=r-l+1, add=(o+2)/2-(o+1)/2;
                cur+=add;
                lf[l]=v; 
                rt[v]=l;
                rt.erase(r);
            } 
            else if(!l&&r){
                int l=v+1, r=lf[v+1];
                int o=r-l+1, add=(o+2)/2-(o+1)/2;
                cur+=add;
                lf.erase(l);
                lf[v]=r; rt[r]=v;
            } 
            else {
                int l1=rt[v-1], r1=v-1;
                int l2=v+1, r2=lf[v+1];
                int o1=r1-l1+1, o2=r2-l2+1;
                int sech=(o1+1)/2+(o2+1)/2;
                int add=(o1+o2+2)/2;
                cur+=add-sech;
                lf.erase(l1); rt.erase(r1);
                lf.erase(l2); rt.erase(r2);
                lf[l1]=r2; rt[r2]=l1;
            }
            in.insert(v);
        }
        ans[i]=cur;
    }
    for(int i=0;i<n;i++)cout << ans[i] << " ";
    return 0;
}
