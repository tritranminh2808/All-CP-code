#include <bits/stdc++.h>
using namespace std;
struct node{
    node *child[26];
    int cnt;
    node(){
        cnt=0;
        for(int i=0;i<=25;i++) child[i]=NULL;
    }
};
const int mod=1e9+7;
node root;
void add(const string &a, node &root){
    node *cur=&root;
    for(int i=a.size()-1;i>=0;i--){
        if(!(cur->child[a[i]-'a'])) cur->child[a[i]-'a']=new node();
        cur=cur->child[a[i]-'a'];
    }
    cur->cnt++;
}
int dp[5005];
void run(node &root,string &s,int x){
    node *cur=&root;
    // cout << s << ":";
    for(int i=s.length()-1;i>=0;i--){
        int c=s[i]-'a';
        
        if(!(cur->child[c])) break;
        cur=cur->child[c];
        if(cur->cnt>0)dp[x]=(dp[x]+cur->cnt*dp[i])%mod;
        // cout << i << " ";
        
    }
    // cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A; cin >> A;
    int q; cin>> q;
    map<string,int>mp;
    while(q--){
        string s; cin >> s;
        mp[s]++;
        add(s,root);
    }
    int n=A.length();
    dp[0]=1;
    for(int i=1;i<=n;i++){
        string xet;
        xet = A.substr(0, i); 
        run(root,xet,i);
    }
    // cout << "\n\n";
    cout << dp[n]%mod;
    return 0;
}