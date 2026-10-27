#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
const long long p=1e7+5;
bool checka[p];
bool checkb[p];
long long sol=0;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n,k; cin >> n >> k;
	long long a[n],b[n];
	for(long long i=0;i<n;i++) cin >> a[i];
	for(long long i=0;i<n;i++) cin >> b[i];
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	//cout << a[0];
	for(long long i=1;i<=(a[0]+b[0])/k;++i){
		while(a[n-1]+b[n-1]>k*i) i++;
		for(long long j=0;j<n;j++){
			for(long long t=0;t<n;t++){
				if(a[j]+b[t]<=i*k&&checka[j]==0&&checkb[t]==0){
					checka[j]=1;
					checkb[t]=1;
					sol+=i;
					//cout << a[j] << " " << b[t] << endl;
					break;
				}
			}
		}
		bool c=0;
		for(long long i=0;i<n;i++){
			if (checka[i]==0||checkb[i]==0){
				c=1;
				break;
			}
		}
		if(c==0){
			cout << sol;
			return 0;
		}
	}

}
