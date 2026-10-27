#include <bits/stdc++.h>

using namespace std;
const int p=1e3+5;
int a[p][p];
int main(){

    int n,m; cin >> n >> m;
    
    vector <int> s;
    for(int i=1;i<=m*n;i++){
    	s.push_back(i);
    }
    sort(s.begin(),s.end());
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = m - 1;
    int dem = 1;
    int p=0;
    while(h1 <= h2 && c1 <= c2){
        for(int i = c1; i <= c2; i++){
            a[h1][i] = s[p]; ++p;
            
        }
        if(p==s.size()) break;
        ++h1;
        for(int i = h1; i <= h2; i++){
            a[i][c2] = s[p]; ++p;
        }
        --c2;
        if(p==s.size()) break;
        for(int i = c2; i >= c1; i--){
            a[h2][i] = s[p]; ++p;
        }
        --h2;
        if(p==s.size()) break;
        for(int i = h2; i >= h1; i--){
            a[i][c1] = s[p]; ++p;
        }
        ++c1;
        if(p==s.size()) break;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}
