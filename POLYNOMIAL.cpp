#include <bits/stdc++.h>
using namespace std;
const int pp=1e6+5,mod=123456789;

long long a[pp];

long long n,x,s=0,p=1; 
unsigned long long mul(long long a, long long b, long long m){
	if(b==0) return 0;
	long long t=mul(a,b/2,m);
	
	if(b%2==0) return (t+t)%m;
	else return (t+t+a)%m;
}
int  main()
{
    cin >> n >> x;  
   vector <long long > v;
    for(long long i=0;i<=n;i++)	{
    	cin >> a[i];
    	v.push_back(a[i]);
	}

    for(auto i:v){
    	s=(long long)(s%mod+mul(i,p,mod)+mod)%mod;
    	p=(long long)mul(p,x,mod);
	}
	cout << (long long )(s+mod)%mod;
}
