#include<bits/stdc++.h>
using namespace std;

bool check[(long long)5e7 + 5];int sum[(long long ) 5e7+5];

int main()
{
	long long n;
	cin >> n;
	set <long long> st;
	
	for(long long i=0;i<10000000;i++)
	{
		check[i]=0;
	}
	check [0]=1;check[1]=1;
	for(long long i=2;i*i<=10000000;i++)
	{
		if(check[i]!=0) continue;
		else
		{
			for(long long k=i;i*k<=10000000;k++)
			{
				check[i*k]=1;
			}
		}		
	}
	
	for(long long i=2;i<=10000000;i++){
		if(check[i]==1) sum[i]=sum[i-1];
		else 	sum[i]=sum[i-1]+1;
			
		
	}
//	cout << check [0] << check [1];
	//for(auto i:st) cout << i << " ";
	while(n--){
		long long a,b; cin >> a >> b;
		long long sol=sum[b]-sum[a];
		if(check[a]==0) sol++;
		cout << sol << "\n";
		//cout << sum[b] - sum[a] << endl;
		//out << *t1;
	}
	return 0;
}
