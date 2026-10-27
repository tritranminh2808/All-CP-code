#include <bits/stdc++.h>
using namespace std;
int n; 
int a[1000005];
bool vst[1000005];
void prin(vector <int> A, vector <int> B){
	cout << A.size() << "\n";
	for(auto i:A) cout << i << " ";
	cout << "\n";
	cout << B.size() << "\n";
	for(auto i:B) cout << i << " ";
	exit(0);
}
void cok1(){
	vector <int> A,B;
	A.push_back(a[1]);
	A.push_back(a[2]);
	int kc=a[2]-a[1];
	vst[1]=1;vst[2]=1;
	for(int i=3;i<=n;i++) {
		if(a[i]-A[A.size()-1]==kc) A.push_back(a[i]);
		else B.push_back(a[i]);
	}
//	for(auto i:A) cout << i << " ";
//	cout << "\n";
//	for(auto i:B) cout << i << " ";
	if(B.empty())return;
	if(B.size()==1) prin(A,B);
	unordered_map<int,int> mp;
	mp[B[1]-B[0]]++;
	for(int i=2;i<B.size();i++) mp[B[i]-B[i-1]]++;
//	for(auto i:mp) cout << i.first << " " << i.second << "\n";
	for(int i=A.size()-1;i>=0;--i){
//		cout << mp.size() << " ";
 		if(mp.size()==1) break;
		auto it=lower_bound(B.begin(),B.end(),A[i])-B.begin();
		if(it==0)continue;
		if(it==B.size())continue;
//		cout << B[it] << " " << B[it-1] << "\n";
		mp[B[it]-B[it-1]]--;
		if(mp[B[it]-B[it-1]]==0) mp.erase(B[it]-B[it-1]);
		mp[A[i]-B[it-1]]++;
		mp[B[it]-A[i]]++;
		B.insert(B.begin()+it,A[i]);
		A.pop_back();
	}
	if(A.empty()||B.empty()||mp.size()>1) return;
	prin(A,B);
}
void cok2(){
	vector <int> A,B;
	A.push_back(a[1]);
	B.push_back(a[2]);
	A.push_back(a[3]);
	int kc=a[3]-a[1];
	vst[1]=1;vst[2]=1,vst[3]=1;
	for(int i=4;i<=n;i++) {
		if(a[i]-A[A.size()-1]==kc) A.push_back(a[i]);
		else B.push_back(a[i]);
	}
	if(B.empty())return;
	if(B.size()==1) prin(A,B);
	unordered_map<int,int> mp;
	mp[B[1]-B[0]]++;
	for(int i=2;i<B.size();i++) mp[B[i]-B[i-1]]++;
//	for(auto i:mp) cout << i.first << " " << i.second << "\n";
	for(int i=A.size()-1;i>=0;--i){
 		if(mp.size()==1) break;
		auto it=lower_bound(B.begin(),B.end(),A[i])-B.begin();
		if(it==0)continue;
		if(it==B.size())continue;
		mp[B[it]-B[it-1]]--;
		if(mp[B[it]-B[it-1]]==0) mp.erase(B[it]-B[it-1]);
		mp[A[i]-B[it-1]]++;
		mp[B[it]-A[i]]++;
		B.insert(B.begin()+it,A[i]);
		A.pop_back();
	}
	if(A.empty()||B.empty()||mp.size()>1) return;
	prin(A,B);
}
void cok3(){
	vector <int> A,B;
	A.push_back(a[1]);
	B.push_back(a[2]);
	B.push_back(a[3]);
	int kc=a[3]-a[2];
	vst[1]=1;vst[2]=1,vst[3]=1;
	for(int i=4;i<=n;i++) {
		if(a[i]-B[B.size()-1]==kc) B.push_back(a[i]);
		else A.push_back(a[i]);
	}
//	swap(A,B);
	if(A.empty())return ;
	if(A.size()==1) prin(A,B);
	unordered_map<int,int> mp;
	mp[A[1]-A[0]]++;
	for(int i=2;i<A.size();i++) mp[A[i]-A[i-1]]++;
//	for(auto i:mp) cout << i.first << " " << i.second << "\n";
	for(int i=B.size()-1;i>=0;--i){
 		if(mp.size()==1) break;
		auto it=lower_bound(A.begin(),A.end(),B[i])-A.begin();
		if(it==0)continue;
		if(it==A.size())continue;
		mp[A[it]-A[it-1]]--;
		if(mp[A[it]-A[it-1]]==0) mp.erase(A[it]-A[it-1]);
		mp[B[i]-A[it-1]]++;
		mp[A[it]-B[i]]++;
		A.insert(A.begin()+it,B[i]);
		B.pop_back();
	}
	if(A.empty()||B.empty()||mp.size()>1) return;
	prin(A,B);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;	
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n==2){
		cout << "1\n" << a[1] << "\n" << "1\n" << a[2];
		return 0;
	}
	sort(a+1,a+n+1);
	cok1();
	cok2();
	cok3();
	cout << -1;
	return 0;
}

