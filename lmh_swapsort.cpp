#include <bits/stdc++.h>
using namespace std;
int n; 
int a[100005],vt[100005],x[100005];
vector <int> b;
unordered_map<long long ,int > mp;
void nen(){
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<b.size();i++) mp[b[i]]=i+1;
    for(int i=1;i<=n;i++) a[i]=mp[a[i]];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b.push_back(a[i]);
    }
    nen();
    for(int i=1;i<=n;i++) x[i]=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) vt[x[i]]=i;
    vector <pair <int, int > > res;
    for(int i=1;i<=n;i++){
        // cout << a[i] << " " << vt[a[i]] << endl;
        int j=vt[i];
        if (j!=i) {
            res.push_back({i-1,j-1});
            int si=x[i],sj=x[j];
            swap(x[i],x[j]);
            vt[si]=j;
            vt[sj]=i;
            
        }
    }
    cout << res.size() << "\n";
    for(auto i:res) cout << i.first << " " << i.second << "\n";
}