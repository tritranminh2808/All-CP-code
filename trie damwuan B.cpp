#include <bits/stdc++.h>
using namespace std;
struct node{
    node *child[26];
    int cnt;
    node(){
        for(int i=0;i<26;i++) child[i]=NULL;
        cnt=0;
    }
};
node root;
multiset <int> maxx[200005];
void update(string &s, node &root){
    node *cur=&root;
    int cc=0;
    for(auto i:s){
        int c=i-'a';
        cc++;
        if(!cur->child[c]) cur->child[c]=new node();
        cur=cur->child[c];
        auto it=maxx[cc].find(cur->cnt);
        if(it!=maxx[cc].end()) maxx[cc].erase(it);
        cur->cnt++;
        maxx[cc].insert(cur->cnt);
    }
}
void den(string &s, node &root){
    node*cur=&root;
    int cc=0;
    for(auto i:s){
        int c=i-'a';
        cc++;
        // if(!cur->child[c]) cur->child[c]=new node();
        cur=cur->child[c];
        auto it=maxx[cc].find(cur->cnt);
        if(it!=maxx[cc].end()) maxx[cc].erase(it);
        cur->cnt--;
        maxx[cc].insert(cur->cnt);
    }
}
int ans=0;
string tv[200005];
bool xoa[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int typ; cin >> typ;
        if(typ==1){
            string s; cin >> s;
            
            reverse(s.begin(),s.end());
            tv[i]=s;
            update(s,root);
        }
        else if(typ==2){
            int k, l; cin >> k >> l;
            if(!maxx[l].empty()&&*maxx[l].rbegin()>=k) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            int id; cin >> id;
            if(xoa[id]) continue;
            string s=tv[id];
            den(s,root);
            xoa[id]=1;
        }
    }
    return 0;
}