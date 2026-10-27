#include <bits/stdc++.h>
using namespace std;
int sol[5000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n=s.length();
    vector<int> z(n);
    z[0]=n;
    int l=0,r=0;
    for(int i=1;i<n;i++) {
        if(i < r)  z[i] =min(r-i,z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])  z[i]++;
        if(i+z[i]>r) {
            l=i;
            r=i+z[i];
        }
    }
    for(int i=0;i<n;i++){
        sol[1]++;
        sol[z[i]+1]--;
    }
    for(int i=1;i<=n;i++) {
        sol[i]+=sol[i-1];
        cout << sol[i] << " ";
    }
}