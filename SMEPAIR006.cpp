#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
bool check(int a, int b){
	int u=gcd(a,b);
	vector <int> v;
	for(int i=2;i<=u;i++) {
		if(u%i==0) v.push_back(i);
	}
	for(int i=0;i<v.size();i++){
		while (a%v[i]==0  )a/=v[i];
		while (b%v[i]==0  )b/=v[i];
	}
	if(a==1&&b==1) return true;
	else return false;
}
long res=0;
int main()
{
	freopen("SAMEPAIR006.inp","r",stdin);
	freopen("SAMEPAIR006.out","w",stdout);
	
	int a,b;
	cin >> a >> b;
	for(int i=a;i<b;i++){
		for(int j=i+1;j<=b;j++){
			//cout << i << " " << j << "\n";
			if(check(i,j)) res++;
		}
	}
	cout << res;
	return 0;
}
