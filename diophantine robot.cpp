#include <bits/stdc++.h>
#define int long long
using i128=__int128;
using namespace std;
int sech(int a,int b, int& x, int& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int x1=0,y1=0;
	int k=sech(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return k;
}
i128 lamtron(i128 a,i128 b){
	if(a>=0) return (a+b-1)/b;
	return a/b;
}
i128 xuli(int a,int b, int c){
	int g=abs(__gcd(a,-b));
	if(c%g!=0) return -1;
	int x=0,y=0;
	int s=sech(a,b,x,y);
	i128 x0=(i128)x*c/g,y0=(i128)-y*c/g;
	i128 bd=b/g,ad=a/g;
	i128 k1=lamtron(-x0,bd),k2=lamtron(-y0,ad);
	i128 k=max(k1,k2);
	i128 xf=x0+bd*k,yf=y0+ad*k;
	if(xf<0||yf<0) return -1;
	return xf+yf;
}
void pr(i128 x){
	if(x<0){
		cout << "-1\n";
		return;
	}
	string s;
	while(x){
		s+='0'+x%10;
		x/=10;
	}
	reverse(s.begin(),s.end());
	cout << s << "\n";
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		int a,b,c;
		cin >> a >> b >> c;
		i128 ans=xuli(a,b,c);
		pr(ans);
	}
}

