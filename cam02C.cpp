#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> cok(const vector<int>&A,const vector<int>&B,bool s){
	int i=0,j=0;int l=2386486432876;vector<int> r;bool c=s;
	while(1){
		if(c){
			while(i<A.size()&&A[i]>l)i++;
			if(i==A.size())break;
			r.push_back(A[i]);l=A[i];i++;c=!c;
		}else{
			while(j<B.size()&&B[j]>l)j++;
			if(j==B.size())break;
			r.push_back(B[j]);l=B[j];j++;c=!c;
		}
	}
	return r;
}
bool tangdan(const vector<int>&x,const vector<int>&y){
	int m=min(x.size(),y.size());
	for(int i=0;i<m;i++){
		if(x[i]!=y[i])return x[i]>y[i];
	}
	return x.size()>y.size();
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n
	vector<int> A(n),B(n);
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++) cin>>B[i];
	sort(A.begin(),A.end(),cmp);
	sort(B.begin(),B.end(),cmp);
	vector<int> r1=cok(A,B,1),r2=cok(A,B,0),sol;
	if(r1.size()>r2.size())sol=r1;
	else if(r2.size()>r1.size())sol=r2;
	else sol=tangdan(r1,r2)?r1:r2;
	for(auto v:sol) cout<<v<<" ";
	return 0;
}

