#include<bits/stdc++.h>
using namespace std;
int res=-9999,p,l;
int y;
bool chck[250];
int main()
{
	freopen("STRINGSEARCH.INP", "r", stdin);
	freopen("STRINGSEARCH.OUT", "w", stdout);
	string s;cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		chck[s[i]]=1;
	}
	for(int i=0;i<250;i++){
		if(chck[i]==1) y++;
	}
	cout << y << " ";
	for(int i=0;i<n;i++){
		
		
		for(int j=n-1;j>i;j--){
			int k=i;
			int chck=0;
			for(int h=j;h>k;h--){
				if(s[h]!=s[k]){
					chck++;
					break;
				}
				else k++;
			}
			if(chck==0)	p=j-i+1;
			if(p>res) res=p;
		}
		
	}
	cout << res;
	return 0; 
}
