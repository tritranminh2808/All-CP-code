#include <bits/stdc++.h>
using namespace std;
#define int long long
struct pl{
	int val,ind;
};
pl a[100005];
int n,q;
string sec;
bool check(string s, int A, int B){
	int x=0,y=0;
//	cout << A << " " << B << endl;
	for(int i=0;i<n;i++){
//		cout << x << " " << y << endl;
		if(s[i]=='1') x+=a[i+1].val;
		else if(s[i]=='2') y+=a[i+1].val;
		if(x>A||y>B) return false;
	}
	
	if(x<=A&&y<=B) return true;
	return false;
}
int maxx=-1;
vector <string > gg;
void cok(string sec){
//	cout << sec << "\n";
	if(sec.length()==n){
		gg.push_back(sec);
		return;
	}
	cok(sec+'0');
	cok(sec+'1');
	cok(sec+'2');
}
bool cmp(pl a, pl b){
	return a.val<b.val;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) {
		cin >> a[i].val;
		a[i].ind=i;
	}
	cok("");
//	for(auto i:gg) cout << i << endl;
//	sort(a+1,a+n+1,cmp);
	for(int z=0;z<q;z++){
		int A,B,k; 
		cin >> A >> B >>k;
		string gay="";
		int maxcnt=0;
		if(k==0){
			for(auto s:gg){
				if(check(s,A,B)){
	//				cout << s << "\n";
					int cnt=0;
					for(auto i : s) if(i!='0') cnt++;
					if(cnt>maxcnt){
						maxcnt=cnt;
						gay=s;
					}
				}
			}
			cout << maxcnt << "\n";
			if(z==0) cout << gay << "\n";
		}
		else{
			vector <int> vv(k);
			while(k--) cin >> vv[k];
			cout << "0\n" ;
		}
	}
	return 0;
}
