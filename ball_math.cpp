#include <bits/stdc++.h>
using namespace std;
int x[200005],r[200005];
long double ans[200005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++)  cin>> x[i] >> r[i];
    stack <int> st;
    // set<pair <long double, int > > st;st.inert({0.0,0});
    for(int i=1;i<=n;i++){
        long double cur=1.0*r[i];
        while(!st.empty()){
            int j=st.top();
            long double rr=1.0*(x[i]-x[j])*(x[i]-x[j])/(4.0*ans[j]);
            if(rr<cur) cur=rr;
            if(cur<ans[j]) break;
            else st.pop();
        }
        ans[i]=cur;
        st.push(i);
    }
    for(int i=1;i<=n;i++) cout << fixed << setprecision(3) << ans[i] << "\n";
    return 0;
}