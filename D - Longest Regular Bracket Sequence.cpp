#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	vector < pair < char, int > > st;
	int id,sol=0;
	unordered_map <int, int> mp;
	
	for(int i=0;i<s.length();++i){
		if(s[i]=='('){
			if(st.size()>=1){
				id=st[st.size()-1].second;
			}
			st.push_back({'(',i});
			
		}
		else {
			if(!st.empty()&&st[st.size()-1].first=='('){
				st.pop_back();
				if(st.size()>=1) id= st[st.size()-1].second;
				else id=-1;
				if(i-id>=sol){
					sol=i-id;
					mp[sol]++;
				}
				
			}
			
				else st.push_back({')',i});
		}
	//	cout  << id << " " << sol <<endl;
	}
	
	if(sol>0)cout << sol << " " <<  mp[sol];
	else cout << "0 1";
	return 0;
}
