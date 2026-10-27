#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> sol;
int a,b,c,d,e,f;
void check(pair <int, int > a, pair <int, int> b, pair <int, int > c, int id){
    int lf=0,rt=0;
    if(b.first>c.first) swap(b,c);
    if(b.second>=c.first&&b.first<=c.second){
        lf=min(b.first,c.first);
        rt=max(b.second,c.second);
        if(lf<=a.first&&rt>=a.second) sol.push_back(id);
    }
    else{
        if(b.first<=a.first&&b.second>=a.second){
            sol.push_back(id);
            return;
        }
        if(c.first<=a.first&&c.second>=a.second){
            sol.push_back(id);
            return;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    check({a,b},{c,d},{e,f},1);
    check({c,d},{a,b},{e,f},2);
    check({e,f},{a,b},{c,d},3);
    cout << sol.size() << "\n";
    for(auto i:sol){
        if(i==1) cout << "AB ";
        if(i==2) cout << "CD ";
        if(i==3) cout <<"EF ";
    }
    return 0;
}
