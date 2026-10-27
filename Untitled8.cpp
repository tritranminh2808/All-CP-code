#include <bits/stdc++.h>
using namespace std;
int f[1000005],a[10005];
int main(){
	int n,m; cin >> n;
	int tong=0;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		tong=0;
	}
	f[0]=0;
	for(int i=1;i<=1000000;i++){
		f[i]=n+1;
		for (int j = 1; j <= n; ++j)
        if (a[j] <= i && f[i - a[j]] < j)
        {
            f[i] = j; break;
        }
	}
	vector <int > s1,s2;
	int kc=1823784373;
	for(int m=1;m<=1000000/2;m++){
		if(f[m]==n+1) continue;
		if(abs(tong-m-m)>=kc) continue;
		vector <int> sol,sol2;
		int mm=m;
		while(mm!=0){
		//	cout << m << " ";
			int i=f[mm];
			sol.push_back(i);
			mm-=a[i];
		}
		int m2=tong-m;
		while(m!=0){
		//	cout << m << " ";
			int i=f[m];
			sol.push_back(i);
			m-=a[i];
		}
	}
	
}
