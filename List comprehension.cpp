#include <bits/stdc++.h>
using namespace std;
int trans(string s){
	int x=0;
	for(int i=0;i<s.length();i++) {
		x*=10;
		x+=s[i]-'0';
	}
	return x;
}
int cal(int a, char dau, int b){
	if(dau=='+') return a+b;
	if(dau=='-') return a-b;
	if(dau=='*') return a*b;
}
int main(){
	string s;
	char daui='!', dauj='!';
	int x=0,y=0;
	getline(cin,s);
	int n=s.length();
	int vng=0;
	for(int i=0;i<n;i++){
		if(s[i]=='|'){
			vng=i;
			break;
		}
	}
	for(int i=0;i<vng;i++){
		if(s[i]=='['||s[i]==' '||s[i]==','||s[i]=='('||s[i]==')') continue;
		if(s[i]=='i'){
			daui=s[i+1];
			i+=2;
			string k;
			while(s[i]<='9'&&s[i]>='0') {
				k+=s[i];
				i++;
			}
			x=trans(k);
		}
		if(s[i]=='j') {
			dauj=s[i+1];
			i+=2;
			string k;
			while(s[i]<='9'&&s[i]>='0') {
				k+=s[i];
				i++;
			}
			y=trans(k);
		}
	}
	if(daui!='+'&&daui!='-'&&daui!='*'){
		daui='+';
		x=0;
	}
	if(dauj!='+'&&dauj!='-'&&dauj!='*'){
		dauj='+';
		y=0;
	}
//	cout << daui << " " << dauj;
	int phay=0;
	for(int i=vng;i<n;i++){
		if(s[i]==']'){
			phay=i;
			break;
		}
	}
	vector <int> a,b;
	bool ch1=0,ch2=0;
	for(int i=vng;i<phay;i++){
		if(s[i]=='.')ch1=1;
		if(s[i]>='0'&&s[i]<='9'){
			string k;
			while(s[i]>='0'&&s[i]<='9'){
				k+=s[i];
				i++;
			}
			a.push_back(trans(k));
		}
	}
	for(int i=phay;i<n;i++){
		if(s[i]=='.')ch2=1;
		if(s[i]>='0'&&s[i]<='9'){
			string k;
			while(s[i]>='0'&&s[i]<='9'){
				k+=s[i];
				i++;
			}
			b.push_back(trans(k));
		}
	}
	if(ch1==1){
		int st=a[0],en=a[1];
		a.clear();
		for(int i=st;i<=en;i++) a.push_back(i);
	}
	if(ch2==1){
		int st=b[0],en=b[1];
		b.clear();
		for(int i=st;i<=en;i++) b.push_back(i);
	}
	vector <pair <int , int > > sol;
	cout << "[";
	for(auto i : a){
		for(auto j:b) sol.push_back({cal(i,daui,x),cal(j,dauj,y)});
	}
//	cout << "]";
	/*for(auto i: a) cout <<i << " ";
	cout << endl;
	for(auto i: b) cout << i << " ";*/
	for(int i=0;i<sol.size();i++) {
		cout << "(" << sol[i].first << "," << sol[i].second << ")";
		if(i<sol.size()-1) cout << ", ";
	}
	cout << "]";
	return 0;
}
