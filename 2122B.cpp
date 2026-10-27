#include <bits/stdc++.h>
using namespace std;
const int pp=2e5+1;
int a[pp],b[pp],c[pp],d[pp];
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
        long long sol=0;
        for(int i=1;i<=n;i++){
            if(b[i]>d[i]) sol+=a[i];
            else sol+=max(0,a[i]-c[i]);
        }
        for(int i=1;i<=n;i++) sol+=max(0,b[i]-d[i]);
        cout << sol << "\n";
	}
	return 0;
	
}
