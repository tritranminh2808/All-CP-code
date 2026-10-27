#include <bits/stdc++.h>
using namespace std;
int res=0;
int main(){
	int n; cin >> n;
	string a,b;
	cin >> a >> b;
//	swap(a,b);
//	int n=a.length();
	int cntc1=0,cntc2=0;
	for(int i=0;i<n;i++){
		if(a[i]=='1') cntc1++;
		if(b[i]=='1') cntc2++;
	}
	if(cntc1!=cntc2){
		cout <<-1;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]=='1'&&b[i]=='0'){
			for(int j=i+1;j<n;j++){
				if(a[j]=='0'){
					swap(a[i],a[j]);
					res++;
					break;
				}
			}
		}
		if(a[i]=='0'&&b[i]=='1'){
			swap(a,b);
			--i;
		}
	}
//	cout << a;
	cout << res;
	return 0;
}
