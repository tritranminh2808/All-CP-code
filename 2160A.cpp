#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int n,k;
void cok(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    unordered_map<int,int> mp;
    set<int> st;
    for(int i=1;i<=n;i++) {
        mp[a[i]]++;
        st.insert(a[i]);
    }
    int m=-1;
    int pre=-1;
    for(auto i:st){
        if(i!=pre+1){
            m=pre+1;
            break;
        }
        pre=i;
    }
    if(m==-1) m=*st.rbegin()+1;
    int base=mp[a[1]];
    pre=-1;
    for(auto i:st){
        if(pre+1!=i||mp[i]!=base){
            cout << m <<"\n";
            return;
        }
        pre=i;
    }
    cout << *st.rbegin()+1 << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cok();
    return 0;
}