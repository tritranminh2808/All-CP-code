#include<bits/stdc++.h>
using namespace std;
const int MN=1e6+1209;
long long n,m,k,ans,pfsum[MN],trace[MN],MIN;
string a[MN],sex,skibidi;
bool dp[MN];
struct trie
{
    struct Node
    {
        int val=0,cnt=0;
        Node *child[26];
       Node()
       {
           for(int i=0;i<26;i++)
               child[i]=NULL;
       }
    };
    Node *root=new Node();
    void addstring(const string &s)
    {
        Node *cur=root;
        for (int i=0;i<s.size();i++)
        {
            if(!(cur->child[s[i]-'a']))
            {
                cur->child[s[i]-'a']=new Node();
            }
            cur=cur->child[s[i]-'a'];
            cur->cnt++;
        }
        cur->val++;
    }
    void checkstring(const string &s,int id)
    {
        cout<<s<<'\n';
        Node *cur=root;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!cur->child[s[i]-'a'])return;
            cur=cur->child[s[i]-'a'];

                cout<<id<<' '<<id-s.size()+i<<' '<<cur->val<<'\n';
            if(cur->val>0&&dp[id-s.size()+i])
            {
                cout<<id<<' '<<id-s.size()+i<<'\n';
                trace[id]=id-s.size()+i;
                dp[id]=true;
            }
        }
    }
};
trie TRIE;
int main()
{
    if(fopen("GAME.INP","r"))
    {
        freopen("GAME.INP","r",stdin);
        freopen("GAME.OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            reverse(a[i].begin(),a[i].end());
            TRIE.addstring(a[i]);
        }
    cin>>m;
    dp[0]=true;
    while(m--)
    {
        cin>>sex;
        for(int i=1;i<=sex.length();i++)
        {
            dp[i]=false;
            int j=i-1;
            int cnt=20;
            skibidi="";
            while(cnt--&&j>=0)
            {
                skibidi.push_back(sex[j]);
                j--;
            }
            reverse(skibidi.begin(),skibidi.end());
            cout<<skibidi<<'\n';
            TRIE.checkstring(skibidi,i);
        }
        if(!dp[sex.length()])
        {
            cout<<-1<<'\n';
            continue;
        }
        int start=0;
        int endd=sex.length();
        while(endd!=0)
        {
            pfsum[++k]=endd-trace[endd];
            endd=trace[endd];
        }
        for(int i=k;i>0;i--)
        {
            cout<<sex.substr(start,pfsum[i])<<' ';
            start+=pfsum[i];
        }
        cout<<'\n';
    }
}