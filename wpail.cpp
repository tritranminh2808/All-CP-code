#include <bits/stdc++.h>
//#define int long long
using namespace std;
int a,b,k,m;
int vst[1005][1005],dep[1005][1005];
struct PL{
	int step,l,r;
};
queue<PL> q;
int sol=812738321;
void cook(){
	while(!q.empty()){
		int i=q.front().l,j=q.front().r,st=q.front().step;
		q.pop();
		if(st<=k) sol=min(sol,abs(i+j-m));
		if(vst[0][j]==0&&st<k) {
			q.push({st+1,0,j});
			vst[0][j]=1;
		}
		if(vst[i][0]==0&&st<k) {
			q.push({st+1,i,0});
			vst[i][0]=1;
		}
		if(vst[i][b]==0&&st<k) {
			q.push({st+1,i,b});
			vst[i][b]=1;
		}
		if(vst[a][j]==0&&st<k) {
			q.push({st+1,a,j});
			vst[a][j]=1;
		}
		int k1=max(0,(i-(b-j))),k2=min(b,i+j),k3=min(a,i+j),k4=max(0,j-(a-i));
		if(vst[k1][k2]==0&&st<k) {
			q.push({st+1,k1,k2});
			vst[k1][k2]=1;
		}
		if(vst[k3][k4]==0&&st<k) {
			q.push({st+1,k3,k4});
			vst[k3][k4]=1;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a>> b>> k >> m;
	PL ff;
	ff.step=0;
	ff.l=0;
	ff.r=0;
	q.push(ff);
	cook();
	cout << sol;
	return 0;
}
