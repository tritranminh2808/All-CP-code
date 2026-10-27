#include <bits/stdc++.h>
using namespace std;
struct node{
    node *childe[26];
    int cnt;
    string str;
    node (){
        cnt=0;
        str="";
        for(int i=0;i<=25;i++) childe[i]=NULL;
    }
};  
node root;
void add(string &s,node& root){
    node *cur=&root;
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        if(!(cur->childe[c])) cur->childe[c]=new node();    
        
        cur=cur->childe[c];
    }
    cur->cnt++;
    cur->str=s;
}
void dfs(node* v){
    for(int i=0;i<=25;i++){
        if(v->childe[i]){
            dfs(v->childe[i]);
            if(v->cnt<v->childe[i]->cnt){
                v->cnt=v->childe[i]->cnt;
                v->str=v->childe[i]->str;
            }
        }
    }
}
pair<string, int > find(string &s,node &root){
    node *cur=&root;
    int maxx=0;
    string g;
    for(int i=0;i<s.length();i++){
        int c=s[i]-'a';
        if(!(cur->childe[c])) return {"",0};
        cur=cur->childe[c]; 
    }
    return {cur->str,cur->cnt};
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        add(s,root);
    }
    int m; cin >> m;
    dfs(&root);
    while(m--){
        string s; cin >> s;
        pair <string,int> sol=find(s,root);
        if(sol.second==0) cout << "-1\n";
        else cout << sol.first << " " << sol.second << "\n";
    }
    return 0;
}