#include<bits/stdc++.h>
using namespace std;
const int p=1e7+5;
bool chck[p];
int k;
int main()
{ 
	freopen("MARATHON.inp", "r+", stdin);
	freopen("MARATHON.out", "w+", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n; int a[n];for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		if(chck[a[i]]==0){
			k++;
			chck[a[i]]=1;
		}
	}cout << k;
	return 0;
}
