#include <bits/stdc++.h>
using namespace std;
int st[2000005];
int n;
void update(int i, int v){
    for(;i<=n;i+=i&-i) st[i]+=v;
}
int find(int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=st[i];
    return s;
}
struct pl{
    int l,r,id;
};
int pre1[1000005],pre2[1000005];
vector <pl> qe;
bool cmp(pl a, pl b){
    return a.r<b.r;
}
int sol[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;
    string s;
    cin >> s;
    n=s.length();
    s='!'+s;
    vector <pair<int, int > > v;
    for(int i=1;i<=n;i++){
        if(s[i]=='(') st.push(i);
        else{
            if(!st.empty()){
                v.push_back({st.top(),i});
                st.pop();
            }
        }
    }
    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int l,r; cin >> l >> r;
        qe.push_back({l,r,i});
    }
    sort(qe.begin(),qe.end(),cmp);
    int idx=0;
    for(auto i:qe){
        while(idx<v.size()&&v[idx].second<=i.r){
            update(v[idx].first,1);
            idx++;
        }
        sol[i.id]=find(i.r)-find(i.l-1);
    }
    for(int i=1;i<=q;i++) cout << sol[i]*2 << "\n";
    return 0;
}