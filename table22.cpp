#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[1005][1005],minhag[1005][1005],maxhag[1005][1005];

int sol=-9999;          
int main(){
	int kk;
	cin >> m >> n>>kk;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) cin >> a[i][j];
	}
	deque <int> dq;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			while(!dq.empty()&&a[i][j]<a[i][dq.back()]) dq.pop_back();
			dq.push_back(j);
			if(dq.front()<=j-kk) dq.pop_front();
			minhag[i][j]=a[i][dq.front()];
		}
		dq.clear();
	}
/*	for(int i=1;i<=m;i++){
		for(int j=1;)
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			while(!dq.empty()&&minhag[j][i]<minhag[dq.back()][i]) dq.pop_back();
			dq.push_back(j);
			if(dq.front()<=j-kk) dq.pop_front();
			maxhag[j][i]=minhag[dq.front()][i];
		}
		dq.clear();
	}
	for(int i=kk;i<=m;i++){
		for(int j=kk;j<=n;j++) sol=max(sol,maxhag[i][j])
	;}
	cout << sol;
}
