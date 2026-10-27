#include <bits/stdc++.h>
using namespace std;
bool scp(int a){
	int t=sqrt(a);
	if(t*t==a) return true;
	return false;
}

int main()
{
	int a[100000];
	freopen("PYTAGO.INP","r+",stdin);
	freopen("PYTAGO.OUT","w+",stdout);
	unsigned long long n;cin>>n;
	int count=0;
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			unsigned long long b=(i*i)-(j*j);
			if(scp(b)&&sqrt(b)>=j){
			
				count++;
				a[k+1]=sqrt((unsigned long long)b);a[k]=j;a[k+2]=i;
				//cout << sqrt(b) << " " << j  << " " << i << "\n";
				k+=3;
			}
		}
	}
	cout << k/3 <<"\n";
	for(int i=0;i<k-2;i+=3) cout << a[i] << " " << a[i+1] << " " << a[i+2] << "\n";
	return 0;
}
