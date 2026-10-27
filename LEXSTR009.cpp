#include<bits/stdc++.h>
using namespace std;
int chck[26];
int main()
{
	freopen("LEXSTR009.INP", "r", stdin);
	freopen("LEXSTR009.OUT", "w", stdout);
	int n; cin >> n; char a[n];
	
	for(int i=0;i<n;i++) {
		cin >> a[i];
		if(a[i]!='?') chck[int(a[i])-97]++;
	}
	//for(int i=0;i<26;i++) cout << chck[i] << " ";
	int k[26];
	for(int i=0;i<26;i++) cin >> k[i];
	for(int i=0;i<26;i++) {
		if(chck[i]!=0) {
			if(chck[i]>k[i]){
				cout << "-1";
				return 0;
			}
		}
	}
	for(int i=0;i<26;i++){
		k[i]-=chck[i];
	}
	int j=0;
	for(int i=0;i<n;i++){
		if(a[i]!='?') cout << a[i];
		else{
			while (k[j]==0) j++;
			cout << char(j+97);
			k[j]--;
			
		}
	}
	return 0; 
}
