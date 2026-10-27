#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    node *childe[2];
    int cnt,val;
    node(){
        cnt=0;
        childe[0]=NULL;
        childe[1]=NULL;
    }
};
node root;
void add(int &s, node &root){
    node *cur=&root;
    for(int i=30;i>=0;i--){
        bool g=(s>>i)&1;
        if(!(cur->childe[g])) cur->childe[g]=new node();
        cur=cur->childe[g];
        cur->cnt++;
    }
    
}
void remove(int &s, node &root){
    node *cur=&root;
    for(int i=30;i>=0;i--){
        bool g=(s>>i)&1;
        if(!(cur->childe[g])) return;        
        cur=cur->childe[g];
        cur->cnt--;
    }
    
}
int sol=0;
void query(int &s, node &root){
    node *cur=&root;
    for(int i=30;i>=0;i--){
        bool g=(s>>i)&1;
        if((cur->childe[1-g])&&cur->childe[1-g]->cnt>0){
            sol|=(1<<i);
            cur=cur->childe[1-g];
        }
        else if((cur->childe[g])&&cur->childe[g]->cnt>0) cur=cur->childe[g];
        else return;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    int stt=0;
    add(stt,root);
    while(q--){
        char c;int u;
        cin >> c >> u;
        if(c=='+') add(u,root);
        else if(c=='-') remove(u,root);
        else {
            sol=0;
            query(u,root);
            cout << sol << "\n";
        }
    }
}