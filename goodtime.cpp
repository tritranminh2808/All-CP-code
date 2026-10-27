#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("goodtime.inp","r",stdin);
    freopen("goodtime.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector < string > v;
    v.push_back("01:10");
    v.push_back("02:20");
    v.push_back("03:30");
    v.push_back("04:40");
    v.push_back("05:50");
    v.push_back("10:01");
    v.push_back("20:02");
    v.push_back("11:11");
    v.push_back("12:21");
    v.push_back("13:31");
    v.push_back("14:41");
    v.push_back("15:51");
    v.push_back("21:12");
    v.push_back("22:22");
    v.push_back("23:32");
    v.push_back("24:42");
    sort (v.begin(),v.end());
    int t;
    cin >> t;
   // for (auto i : v) cout << i << endl;
    while (t--) {
        string time;
       	cin >> time;
        auto it=upper_bound(v.begin(),v.end(),time)-v.begin();
        if(it==v.size()-1) cout << "00:00\n";
        else cout << v[it]<< endl;
    }
    
    return 0;
}

