#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];
bool MAX(long long i , long long j, string s){
	string str;str+='M';str+='A';str+='X';str+='(';
	string str2;
	for(long long k=i;k<=j;k++){
		str2+=s[k];
	}
	if(str!=str2) return false;
	return true;
}
bool SUM(long long i , long long j, string s){
	string str;str+='S';str+='U';str+='M';str+='(';
	string str2;
	for(long long k=i;k<=j;k++){
		str2+=s[k];
	}
	if(str!=str2) return false;
	return true;
}
int main(){
	int n,m; cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack < string > st;
		stack < char > st2;
		stack <long long> v;
		for(long long i=0;i<s.length();i++)
		{
			
			//cout << i << " ";
			if(MAX(i,i+3,s)){
				string str;str+='M';str+='A';str+='X';str+='(';
				st.push(str);
				st2.push('(');
				i+=3;
			}
			else if(SUM(i,i+3,s)){
				string str;str+='S';str+='U';str+='M';str+='(';
				st.push(str);
				st2.push('(');
				i+=3;
			}
			//cout << st.top() << " " << st2.top() << endl;
			if(s[i]>='A'&&s[i]<='Z'&&s[i+1]>='1'&&s[i+1]<='9'){
				int k=a[s[i+1]-'1'+1][s[i]-'A'+1];
//				cout << s[i]-'A'+1 << " ";
				i++;
				v.push(k);
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
				else if(st.top()=="SUM("){
					
					long long so_cuoi=v.top();
					v.pop();
					long long so_cuoi2=v.top();
					v.pop();
					long long m=so_cuoi+so_cuoi2;
					v.push(m);
				}
				st2.pop();
				st.pop();
				
			}
			
		}
		cout << v.top() << "\n";
	}
	
	
	return 0;
}
