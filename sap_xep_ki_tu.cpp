#include <bits/stdc++.h>
using namespace std;
pair <char, int > minn[100005];
stack<pair <char, int > > st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    // for(auto i:s) cout << i;
    int n=s.length();
    s='!'+s;
    int cur=5000,ii=0;
    char c='!';
    for(int i=n;i>=1;i--){
        // cout << s[i];
        if(s[i]-'a'<=cur){
            cur=s[i]-'a';
            ii=i;
            c=s[i];
        }
        minn[i]={c,ii};
    } 
    
    int g=1;
    string ans;
    while(1){
        while(!st.empty()&&st.top().first<=minn[g].first){
            ans+=st.top().first;
            st.pop();
        }

        auto x=minn[g];
        for(int i=g;i<x.second;i++) st.push({s[i],i});
        ans+=x.first;
        g=x.second+1;
        if(g==n+1) break;
    }
    while(!st.empty()){
        ans+=st.top().first;
        st.pop();
    }
    cout << ans;
    return 0;
}