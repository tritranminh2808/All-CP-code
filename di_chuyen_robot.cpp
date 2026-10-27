#include <bits/stdc++.h>
using namespace std;
int prex[2000005],prey[2000005];
const int cu=1e6;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int posx=0,posy=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int x, y; cin >> x >> y;
        ans+=abs(x);
        ans+=abs(y);
        prex[x]++;
        prey[y]++;
    }
    for(int i=1;i<=2000000;i++){
        prex[i]+=prex[i-1];
        prey[i]+=prey[i-1];
    }
    string s; cin >> s;
    for(auto i:s){
        if(i=='E') posx++;
        else if(i=='W') posx--;
        else if(i=='n') posy++;
        else posy--;
        int sol=0;
        
    }
    return 0;
}