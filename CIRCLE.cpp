#include <bits/stdc++.h>
#define int long long
using namespace std;
int b[100005];
vector <int> a(100005,0),finala(100005,999999);
vector <bool> na(100005,false);
int n;
void xu_li1(){
	int t=0;
	while(a[(t+3)%n]==0)
	{
		//cout << t << "\n";
		a[(t+3)%n]=a[t]+b[(t+2)%n]-b[(t+1)%n];
		t+=3;
		t%=n;
	}
	int d=999999;
	for(int i=0;i<n;i++) d=min(d,a[i]);
	d=1-d;
	for(int i=0; i<n;i++) a[i]+=d;
	for(int i=0;i<n;i++) cout << a[i] << " ";
	return;
}
void guess(int d, int e, int f){
	vector <int> c[3];
	for(int i=0;i<n;i++)	(c[i%3]).push_back(a[i]);
	int d1=*min_element(c[d].begin(),c[d].end());
	for(int i=d;i<n;i+=3){
		a[i]+=d1;
		if(a[i]>n||na[a[i]])return;
		na[a[i]]=true;
	}
	int x=1;while(na[x])++x;
	int d2=x-*min_element(c[e].begin(),c[e].end());
	for(int i=e;i<n;i+=3){
		a[i]+=d2;
		if(a[i]>n||na[a[i]])return;
		na[a[i]]=true;
	}
	int y=x;while(na[y])++y;
	int d3=y-*min_element(c[f].begin(),c[f].end());
	for(int i=f;i<n;i+=3){
		a[i]+=d3;
		if(a[i]>n||na[a[i]])return;
		na[a[i]]=true;
	}
	if(a<finala) finala=a;
}
void xu_li2(){
	a[0]=0;a[1]=0;a[2]=0;
	for(int i=3;i<n;i++){
		a[i]=a[i-3]+b[i-1]-b[i-2];
	}
	guess(0,1,2);
	guess(0,2,1);
	guess(1,0,2);
	guess(1,2,0);
	guess(2,0,1);
	guess(2,1,0);
	for(int i=0;i<n;i++) cout << finala[i] << " ";
}
signed main(){
//	freopen("circle.inp","r",stdin);
//	freopen("circle.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++) cin >> b[i];
	if(n%3!=0) xu_li1();
	else xu_li2();
	return 0;
}
