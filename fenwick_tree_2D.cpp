#include <bits/stdc++.h>
using namespace std;
int st[2024][2024],s;
void update (int x, int y,int v){
    for(int i=x;i<=s;i+=i&-i){
        for(int j=y;j<=s;j+=j&-j) st[i][j]+=v;
    }
}
int find (int x, int y){
    int S=0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j) S+=st[i][j];
    }
    return S;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int ty;
        cin >> ty;
        if(ty==0){
            cin >> s;
        }
        if(ty==3) exit(0);
        if(ty==1) {
            int x,y,a; cin>> x >> y >> a;
            x++;
            y++;
            update(x,y,a);
        }
        if(ty==2) {
            int x,y,p,q;
            cin >> x >> y >> p >> q;
            x++;y++;
            p++;q++;
            cout << find(p,q)-find(x-1,q)-find(p,y-1)+find(x-1,y-1) << "\n";
        }
    }
    return 0;
}