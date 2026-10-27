#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n,l;
        cin >> n >> l;
        string s;
        cin >> s;
        vector<int> f(n);
        for(int c=0;c<l;c++){
            vector<int> idx;
            for(int i=c;i<n;i+=l) idx.push_back(i);
            int m=idx.size();
            vector <int> dp(m);
            deque <int> dq;
            map <char,int> mp;
            int l=0;
            for(int r=0;r<m;r++){
                char ch=s[idx[r]];
                if(ch!='*'){
                    mp[ch]++;
                    if(mp.size()==2){
                        while(l<r&&mp.size()>1){
                            char d=s[idx[l++]];
                            if(d!='*'&&--mp[d]==0) mp.erase(d);
                        }
                    }
                }
                dp[r]=r-l+1;
            }
            for(int i=0;i<m;i++) f[idx[i]]=dp[i];
        }
        int ans=0;
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty()&&f[dq.back()]>=f[i]) dq.pop_back();
            dq.push_back(i);
            if(dq.front()<=i-l) dq.pop_front();
            if(i>=l-1) {
                if(dq.empty()) ans=max(ans,0);
                else ans=max(ans,f[dq.front()]);
            }
        }
        cout<<ans*l<<"\n";
    }
    return 0;
}
