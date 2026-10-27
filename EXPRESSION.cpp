#include <bits/stdc++.h>
using namespace std;
string s;
bool MAX(long long i , long long j){
	string str;str+='M';str+='A';str+='X';str+='(';
	string str2;
	for(long long k=i;k<=j;k++){
		str2+=s[k];
	}
	if(str!=str2) return false;
	return true;
}
bool DIF(long long i , long long j){
	string str;str+='D';str+='I';str+='F';str+='(';
	string str2;
	for(long long k=i;k<=j;k++){
		str2+=s[k];
	}
	if(str!=str2) return false;
	return true;
}
bool SUM(long long i , long long j){
	string str;str+='S';str+='U';str+='M';str+='(';
	string str2;
	for(long long k=i;k<=j;k++){
		str2+=s[k];
	}
	if(str!=str2) return false;
	return true;
}
bool MIN(long long i , long long j){
	string str;str+='M';str+='I';str+='N';str+='(';
	string str2;
	for(long long k=i;k<=j;k++){
		str2+=s[k];
	}
	if(str!=str2) return false;
	return true;
}
bool GCD(long long i , long long j){
	string str;str+='G';str+='C';str+='D';str+='(';
	string str2;
	for(long long k=i;k<=j;k++){
		str2+=s[k];
	}
	if(str!=str2) return false;
	return true;
}
long long nguyen(string k){
	long long t=0;
	for(long long i=0;i<k.length();i++){
		t+=int(k[i])-48;
		t*=10;
	}
	t/=10;
	return t;
}
int main(){
	freopen("expression.inp","r",stdin);
	freopen("expression.out","w",stdout);
	cin >> s;
	stack < string > st;
	stack < char > st2;
	stack <long long> v;
	for(long long i=0;i<s.length();i++)
	{
		
		//cout << i << " ";
		if(MAX(i,i+3)){
			string str;str+='M';str+='A';str+='X';str+='(';
			st.push(str);
			st2.push('(');
			i+=3;
		}
		else if(MIN(i,i+3)){
			string str;str+='M';str+='I';str+='N';str+='(';
			st.push(str);
			st2.push('(');
			i+=3;
		}
		else if(SUM(i,i+3)){
			string str;str+='S';str+='U';str+='M';str+='(';
			st.push(str);
			st2.push('(');
			i+=3;
		}
		else if(DIF(i,i+3)){
			string str;str+='D';str+='I';str+='F';str+='(';
			st.push(str);
			st2.push('(');
			i+=3;
		}
		else if(GCD(i,i+3)){
			string str;str+='G';str+='C';str+='D';str+='(';
			st.push(str);
			st2.push('(');
			i+=3;
		}
		//cout << st.top() << " " << st2.top() << endl;
		if(s[i]>='0'&&s[i]<='9'){
			string k;k+=s[i];i++;
			while (s[i]>='0'&&s[i]<='9'){
				k+=s[i];i++;
			}
			v.push(nguyen(k));
		}
		//if(!v.empty())cout << v.top() << " " << s[i] << " " << st.top() << endl;
		if(!st2.empty()&&s[i]==')'){
			//cout << st.top() << " ";
			if(st.top()=="MAX("){
				long long so_cuoi=v.top();
				v.pop();
				long long so_cuoi2=v.top();
				v.pop();
			
				long long m=max(so_cuoi,so_cuoi2);
				v.push(m);
				
			}
			else if(st.top()=="MIN("){
				long long so_cuoi=v.top();
				v.pop();
				long long so_cuoi2=v.top();
				v.pop();
				long long m=min(so_cuoi,so_cuoi2);
				v.push(m);
				
			}
			else if(st.top()=="SUM("){
				
				long long so_cuoi=v.top();
				v.pop();
				long long so_cuoi2=v.top();
				v.pop();
				long long m=so_cuoi+so_cuoi2;
				v.push(m);
				
			}
			else if(st.top()=="DIF("){
				long long so_cuoi=v.top();
				v.pop();
				long long so_cuoi2=v.top();
				v.pop();
				long long m=-so_cuoi+so_cuoi2;
				v.push(m);	
			}
			else if(st.top()=="GCD("){
				long long so_cuoi=v.top();
				v.pop();
				long long so_cuoi2=v.top();
				v.pop();
				long long m=__gcd(abs(so_cuoi),abs(so_cuoi2));
				v.push(m);
				
			}
			st2.pop();
			st.pop();
			
		}
		
	}
	cout << v.top();
	
	return 0;
}
