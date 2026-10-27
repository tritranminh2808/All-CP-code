#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int l[26],m[26],w[26];
int n;
map <pair <int,int>, string > mp,mp2;
map<pair <int, int  > , ll> cnt,cnt2;
int k1,k2;
void backtrack1(string s){
    if(s.length()==k1){
        ll a=0,b=0,c=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='0'){
                b+=m[i+1];
                c+=w[i+1];
            }
            if(s[i]=='1'){
                a+=l[i+1];
                c+=w[i+1];
            }
            if(s[i]=='2'){
                b+=m[i+1];
                a+=l[i+1];
            }
        }
        if(cnt.find({a-b,b-c})==cnt.end()||cnt[{a-b,b-c}]<a+b+c){
            mp[{a-b,b-c}]=s;
            cnt[{a-b,b-c}]=a+b+c;
        }
        // cout << s << "\n";
        return ;
    }
    backtrack1(s+'0');
    backtrack1(s+'1');
    backtrack1(s+'2');
}
void backtrack2(string s){
    if(s.length()==k2){
        ll a=0,b=0,c=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='0'){
                b+=m[k1+i+1];
                c+=w[k1+i+1];
            }
            if(s[i]=='1'){
                a+=l[k1+i+1];
                c+=w[k1+i+1];
            }
            if(s[i]=='2'){
                b+=m[k1+i+1];
                a+=l[k1+i+1];
            }
        }
        if(cnt2.find({a-b,b-c})==cnt2.end()||cnt2[{a-b,b-c}]<a+b+c){
            mp2[{a-b,b-c}]=s;
            cnt2[{a-b,b-c}]=a+b+c;
        }
        // cout << s << "\n";
        return ;
    }
    backtrack2(s+'0');
    backtrack2(s+'1');
    backtrack2(s+'2');
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> l[i] >> m[i] >> w[i];
    k2=n/2;
    k1=n-k2;

    backtrack1("");
    backtrack2("");
    ll maxx = LLONG_MIN;
    int h1 = 0, h2 = 0;

    for (auto &it : cnt) {
        int d1 = it.first.first;
        int d2 = it.first.second;
        ll sum1 = it.second;
        auto it2 = cnt2.find({-d1,-d2});
        if (it2 == cnt2.end()) continue;
        ll sum2 = it2->second;
        if (sum1 + sum2 > maxx) {
            maxx = sum1 + sum2;
            h1 = d1;
            h2 = d2;
        }
    }

    if (maxx == LLONG_MIN) {
        cout << "Impossible\n";
        return 0;
    }
    string sp=mp[{h1,h2}];
    for(auto j:sp){
        if(j=='0') cout << "MW\n";
        if(j=='1') cout << "LW\n";
        if(j=='2') cout << "LM\n";
    }
    for(auto j:mp2[{0-h1,0-h2}]){
        if(j=='0') cout << "MW\n";
        if(j=='1') cout << "LW\n";
        if(j=='2') cout << "LM\n";
    }
    
    return 0;
}