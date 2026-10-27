#include <bits/stdc++.h>
using namespace std;
int n,m;
int f[1005][1005],w[1005][1005];
string a[1005];
int kmp[1005];
int l;
void cok(string s){
    kmp[0]=0;
    for(int i=1;i<s.length();++i){
        int j=kmp[i-1];
        while(j>0&&s[i]!=s[j]) j=kmp[j-1];
        if(s[i]==s[j]) j++;
        kmp[i]=j;
    }
}
int cal(string a, string b){
    int q=0;
    for(int i=0;i<l;i++){
        while(q>0&&a[q]!=b[i]) q=kmp[q-1];
        if(a[q]==b[i]) ++q;
        if(q==a.length()) q=kmp[q-1];

    }
    return l-q;
}
string merge(string x, string y, int cc){
    return x+y.substr(y.size()-cc);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    l=a[1].length();
    
    for(int i=1;i<=n;i++) {
        cok(a[i]);
        for(int j=1;j<=n;j++)w[i][j]=cal(a[i],a[j]);
    }
    for(int i=1;i<=n;i++)    f[1][i]=l;
    for(int k=2;k<=m;k++){
    for(int j=1;j<=n;j++) f[k][j]=INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        f[k][j]=min(f[k][j], f[k-1][i] + w[i][j]);
    }
    int i=1;
    for(int j=2;j<=n;++j) if(f[m][j]<f[m][i]) i=j;
    // cout << f[m][i] << "\n";
    for(int k=m;k>1;--k){
        int j1=0;
        for(int j=1;j<=n;++j){
            if(f[k][i]!=f[k-1][j]+w[i][j]) continue;
            if(j1==0||merge(a[i],a[j],w[i][j])<merge(a[i],a[j1],w[i][j1])) j1=j;

        }
        cout << a[i].substr(0,w[i][j1]);
        i=j1;
    }
    cout << a[i];
    return 0;
}
