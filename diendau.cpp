#include <bits/stdc++.h>
using namespace std;
int trans(string a){
	int x=0;
	for(int i=0;i<a.length();i++) {
		x*=10;
		x+=a[i]-'0';
	}
	return x;
}
int cal(int a, int b, int c, int k){
	int x=0;
	if(a+b+c==k) x++;
	if(a+b-c==k) x++;
	if(a-b+c==k) x++;
	if(a-b-c==k) x++;
	return x;
}
int sol=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int k;
	cin >> s >> k;
	if(s.length()==2){
		if(trans(s)==k) sol++;
		if(s[0]-'0'+s[1]-'0'==k) sol++;
		if(s[0]-s[1]-'0'-'0'==k) sol++;
		cout << sol;
		return 0;
	}
	if(s.length()==3){
		if(trans(s)==k) sol++;
		if(s[0]+s[1]-'0'+s[2]-'0'-'0'==k) sol++;
		if(s[0]-s[1]-'0'+'0'+s[2]-'0'==k) sol++;
		if(s[0]+s[1]-'0'-'0'-s[2]+'0'==k) sol++;
		if(s[0]-s[1]-'0'+'0'-s[2]+'0'==k) sol++;
		string k1,k2;
//		cout << s[0]-s[1]-'0'-'0'+s[2]-'0';
		k1+=s[1];k1+=s[2];k2+=s[0];k2+=s[1];
//		cout << trans(k1);
		if(s[0]-'0'+trans(k1)==k) sol++;
		if(s[0]-'0'-trans(k1)==k) sol++;
		if(trans(k2)+s[2]-'0'==k) sol++;
		if(trans(k2)-s[2]-'0'==k) sol++;
		cout << sol;
		return 0;
	}
	if(s.length()==4){
		int a=s[0]-'0',b=s[1]-'0',c=s[2]-'0',d=s[3]-'0';
//		cout << a << b << c << d;
		if(a+b+c+d==k) sol++;
		if(a+b+c-d==k) sol++;
		if(a+b-c+d==k) sol++;
		if(a+b-c-d==k) sol++;
		if(a-b+c+d==k) sol++;
		if(a-b+c-d==k) sol++;
		if(a-b-c+d==k) sol++;
		if(a-b-c-d==k) sol++;
//		cout << sol;
		string hai1,hai2,hai3,ba1,ba2;
		hai1+=s[0];hai1+=s[1];
		hai2+=s[1];hai2+=s[2];
		hai3+=s[2];hai3+=s[3];
		ba1+=s[0];ba1+=s[1];ba1+=s[2];
		ba2+=s[1];ba2+=s[2];ba2+=s[3];
		if(trans(ba1)+d==k) sol++;
		if(trans(ba2)+a==k) sol++;
		if(trans(ba1)-d==k) sol++;
		if(a-trans(ba2)==k) sol++;
//		cout << trans(hai3);
		if(trans(hai1)+trans(hai3)==k) sol++;
		if(trans(hai1)-trans(hai3)==k) sol++;
//		cout << 
		sol+=cal(trans(hai1),c,d,k);
		sol+=cal(a,trans(hai2),d,k);
		sol+=cal(a,b,trans(hai3),k);
		cout << sol;
		return 0;
	}
	else cout << 1;
	return 0;
}
