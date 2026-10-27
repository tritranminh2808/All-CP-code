#include <bits/stdc++.h>
using namespace std;
int n;
int encode(int x, int y){
    return x*n+y;
}
int vst[25][25];
char a[25][25];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m;cin >> n >> m;
        memset(a,0,sizeof(a));
        memset(vst,0,sizeof(vst));
        bool cc=0;
        for(int i=1;i<=n;i++){
            string s; cin >> s;
            
            for(int j=0;j<m;j++){
                a[i][j+1]=s[j];
                // if(s[j]=='.') cc++;
            }
        }
        bool sech=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='.'){
                    int cnt=0;
                    if(a[i+1][j]=='.') cnt++;
                    if(a[i-1][j]=='.') cnt++;
                    if(a[i][j+1]=='.') cnt++;
                    if(a[i][j-1]=='.') cnt++;
                    if(cnt==1) {
                        sech=1;
                        break;
                    }
                }
            }
            if(sech==1) break;
        }
        if(sech) cout << "1\n";
        else cout << "0\n";
    }
    return 0;

}