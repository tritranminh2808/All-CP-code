#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4.2,popcnt")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wformat-security"
using namespace std;
int a[100005],n;
vector <int> idx[1000005];
const int pp=1e6+1;
int minpr[pp+4],dem[pp+4];
pair <int, int > f[pp+4],f2[pp+4];
void sang(){
    iota(minpr,minpr+pp+4,0);
    for(int i=0;i<=pp;i++){
        f[i].first=1e9;
        f[i].second=0;
        f2[i].first=1e9;
        f2[i].second=0;
        if(i<2) continue;
        for(int j=i;j<=pp;j+=i){
            if(minpr[j]==j) minpr[j]=i;
        }
        dem[i]=dem[i/minpr[i]]+1;
    }
}

void cal(pair <int, int>& a, pair <int, int > &b, pair <int, int > c){
    if(c.second==0) return;
    if(c<a){
        if(a.second!=c.second) b=a;
        a=c;
        return;
    }
    if(c.second!=a.second&&c<b) b=c; 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    // dem[1]=0;
    sang();
    for(int i=pp-1;i>=1;--i){
        for(int j=2*i;j<=pp;j+=i){
            if(f[j].second!=0){
                if(f[j]<f[i]){
                    if(f[i].second!=f[j].second) f2[i]=f[i];
                    f[i]=f[j];
                }
                else if(f[j].second!=f[i].second&&f[j]<f2[i]) f2[i]=f[j];
            }
            // cal(f[i],f2[i],f[j]);
            // cal(f[i],f2[i],f2[j]);
        }
        for(auto j:idx[i]) cal(f[i],f2[i],{dem[i],j});
    }
    for(int i=1;i<=n;i++){
        vector <int> uoc;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0) {
                uoc.push_back(j);
                if(j*j!=a[i]) uoc.push_back(a[i]/j);
            }
        }
        int cur=a[i];
        pair <int, int > maxx={1e9,-1};
        for(auto j:uoc){
            // int g=__gcd(cur,j);
            if(f[j].second!=0&&f[j].second!=i){
                int dist=dem[cur]+f[j].first-2*dem[j];
                pair <int, int >  p={dist,f[j].second};
                if(maxx>p) maxx=p;
            }
            if(f2[j].second!=0&&f2[j].second!=i){
                int dist=dem[cur]+f2[j].first-2*dem[j];
                pair <int, int >  p={dist,f2[j].second};
                if(maxx>p) maxx=p;
            } 
        }
        cout << maxx.second << "\n";
    }
    return 0;
}
