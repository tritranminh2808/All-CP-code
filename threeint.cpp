#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("threeint.inp","r",stdin);
	freopen("threeint.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        vector <int> v;v.push_back(a);v.push_back(b);v.push_back(c);
        sort(v.begin(),v.end());
        int s1,s2;
        if(v[0]+1==v[1]&&v[1]+1==v[2]) s1=0;
        else if(v[0]+2==v[1]||v[1]+2==v[2]) s1=1;
        else s1=2;
        cout << s1 << " " << max(v[1]-v[0]-1,v[2]-v[1]-1) << "\n";
    }
    return 0;
}

