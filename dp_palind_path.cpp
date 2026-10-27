#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
char a[505][505];
int dp[2][505][505];
signed main(){
	
    freopen("palpath.in","r",stdin);
    freopen("palpath.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n; 
    cin >> n;
	for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=n;j++) a[i][j]=s[j-1];
    }
	if(a[1][1]!=a[n][n]){
        cout << 0;
        return 0;
    }
	int c=0,nx=1; 
    dp[c][1][n]=1;
	for(int s=0;s<=n-2;s++){
		memset(dp[nx],0,sizeof dp[nx]);
		int lx=max((int)1,2+s-n),rx=min(n,1+s), lu=max((int)1,n-s),ru=n;
		for(int x=lx;x<=rx;x++){
			int y=s-x+2; 
            if(y<1||y>n) continue;
			for(int u=lu;u<=ru;u++){
				int v=2*n-s-u; 
                if(v<1||v>n) continue;
                if(dp[c][x][u]==0) continue;
				int x1=x+1,y1=y,x2=x,y2=y+1,u1=u-1,v1=v,u2=u,v2=v-1;
				if(x1<=n&&u1>=1&&a[x1][y1]==a[u1][v1]) dp[nx][x1][u1]=(dp[nx][x1][u1]+dp[c][x][u])%mod;
				if(x1<=n&&v2>=1&&a[x1][y1]==a[u2][v2]) dp[nx][x1][u2]=(dp[nx][x1][u2]+dp[c][x][u])%mod;
				if(y2<=n&&u1>=1&&a[x2][y2]==a[u1][v1]) dp[nx][x2][u1]=(dp[nx][x2][u1]+dp[c][x][u])%mod;
				if(y2<=n&&v2>=1&&a[x2][y2]==a[u2][v2]) dp[nx][x2][u2]=(dp[nx][x2][u2]+dp[c][x][u])%mod;
			}
		}
		swap(c,nx);
	}
	int ans=0,s=n-1;
	int lx=max((int)1,2+s-n),rx=min(n,1+s),lu=max((int)1,n-s),ru=n;
	for(int x=lx;x<=rx;x++){
		int y=s-x+2; 
        if(y<1||y>n) continue;
		for(int u=lu;u<=ru;u++){
			int v=2*n-s-u; 
            if(v<1||v>n) continue;
			if(abs(x-u)+abs(y-v)<=1) ans=(ans+dp[c][x][u])%mod;
		}
	}
	cout << ans;
}
