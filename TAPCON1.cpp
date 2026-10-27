#include <bits/stdc++.h>
using namespace std;
vector <string> vvv;
void in(const vector<int>& a, int idx, vector<int>& ca) {
    
    if (!ca.empty()) {
    	string s;
        for (int val : ca) {
        	s+=char(val+48);
            //cout << val << " ";
        }
        vvv.push_back(s);
        //cout << endl;
    }

    for (int i = idx; i < a.size(); i++) {
        ca.push_back(a[i]);
        in(a, i + 1, ca);
        ca.pop_back();
    }
}
bool cmp( string a, string b){
	if(a.length()==b.length()) return a<b;
	return a.length()<b.length();
}
int main() {
	freopen("tapcon1.inp","r",stdin);
	freopen("tapcon1.out","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ca;
    in(a, 0, ca);

	sort(vvv.begin(),vvv.end(),cmp);
	for(int i=0;i<vvv.size();i++){
		for(int j=0;j<vvv[i].length();j++){
			cout << int(vvv[i][j]-48) << " ";
		}
		cout << endl;
	}
    return 0;
}

