#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("zz.INP","r",stdin);
	freopen("zz.OUT","w",stdout);
    int n,m; cin >> n >> m;
    int a[n][m];
    vector <int> s;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> a[i][j];
    		s.push_back(a[i][j]);
		}
    }
    sort(s.begin(),s.end());
    a[0][0]=s[0];
    int x=1;
    for(int i=1;i<m;i++){
    	int k=i;
    	for(int j=0;j<n;j++){
    		a[j][k]=s[x];
    		k--;
    		x++;
    		if(k<0) break;
    		
		}
	}
	for(int i=1;i<n;i++){
    	int k=i;
    	for(int j=m-1;j>=0;j--){
    		a[k][j]=s[x];
    		k++;
    		x++;
    		if(k==n) break;
    		
		}
	}
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}
