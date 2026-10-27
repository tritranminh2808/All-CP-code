#include <bits/stdc++.h>
#pragma GCC optimize ("O3,unroll-loops")
using namespace std;
int sopt=1, n, soday=0, luu=1;
int main()
{
	
    int n;cin >> n;int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
	for (int i=0; i<n-1; i++)
	{
		if (a[i+1]>=a[i]){
			sopt++;
			if (sopt>luu) luu=sopt;
		}
		else sopt=1;
	
	}
    
	cout << luu;
	return 0;
}
