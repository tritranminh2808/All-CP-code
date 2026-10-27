#include <bits/stdc++.h>
using namespace std;
int n;
bool check[10000005],check2[1000005];
vector <int> prime;
void tien_xu_li(){
	for(int i=2;i*i<=1000004;i++){
		if(check[i]==1) continue;
		for(int k=i;k*i<=1000004;++k) check[i*k]=1;
	}
	for(int i=2;i<=1004;i++) if(check[i]==0) prime.push_back(i);
}
int mu[1000004];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	tien_xu_li();
	int sol=0;
	vector <int> v;
	while(n--){
		int a; cin >> a;
		bool chck=0;
		int sqr=sqrt(a);
		for(auto i : prime){
			if(i>sqr||!check[a]) break;
			if(a%i==0&&check2[i]==0)  {
				v.push_back(i);
				check2[i]=1;
			}
			while(a%i==0) {
				a/=i;
				mu[i]++;
			}
		}
		if(a!=1) {
			mu[a]++;
			v.push_back(a);
		}
		for(auto i : v){
			if(mu[i]%2==1){
				chck=1;
				 break;
			}
		}
		if(chck==0) sol++;
	//	cout << endl;
	}
	cout << sol;
	return 0;
}

