#include <bits/stdc++.h>
using namespace std;
bool check[200005];
vector <int> pos[200005];
// int next[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    vector <int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=n;i>=1;i--) pos[a[i]].push_back(i);
    set<pair <int, int > > st;
    int sol=0;
    for(int i=1;i<=n;i++){
        
        pos[a[i]].pop_back();
        if(check[a[i]]){
            st.erase({i,a[i]});
            int nxt=n+1;
            if(!pos[a[i]].empty()) nxt=pos[a[i]].back();
            st.insert({nxt,a[i]});
        }
        else{
            if(st.size()==k){
                auto it=st.rbegin();
                check[it->second]=0;
                st.erase(*it);
                sol++;
            }
            int nxt=n+1;
            if(!pos[a[i]].empty()) nxt=pos[a[i]].back();
            st.insert({nxt,a[i]});
            check[a[i]]=1;
        }
        // cout << i << "\n";
        // for(auto j:st) cout << j.first << " " << j.second << "\n";
        // cout << "\n";
    }
    cout << sol;
}