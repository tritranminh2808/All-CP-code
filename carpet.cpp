#include <bits/stdc++.h>
using namespace std;
int a[305][305];
void xu_li_V(vector <int> z){
	int x1=z[0],y1=z[1],x2=z[2],y2=z[3];
	vector <vector <int> > vv(x2-x1+1);
	int ind=0;
	
	while(ind<x2-x1+1){
		for(int i=y1;i<=y2;++i) vv[ind].push_back(a[x1+ind][i]);
		ind++;
	}
	reverse (vv.begin(),vv.end());
	int in1=0;
	for(int i=x1;i<=x2;i++){
		int in2=0;
		for(int j=y1;j<=y2;j++){
			a[i][j]=vv[in1][in2];
			in2++;
		}
		in1++;
	}
	//cout << x1 << y1 << x2 << y2 << endl;
}
void xu_li_H(vector<int> z) {
    int x1 = z[0], y1 = z[1], x2 = z[2], y2 = z[3];
    vector<vector<int>> vv(y2 - y1 + 1);
    for (int i = y1; i <= y2; ++i) {
        for (int j = x1; j <= x2; ++j) {
            vv[i - y1].push_back(a[j][i]);
        }
    }
    reverse(vv.begin(), vv.end());
    for (int i = y1; i <= y2; ++i) {
        for (int j = x1; j <= x2; ++j) {
            a[j][i] = vv[i - y1][j - x1];
        }
    }
}
int m,n,t;
int main(){
	cin >> n >> m >> t;
	int kt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			a[i][j]=kt;
			kt++;
		}
	}
	vector <pair <char , vector <int> > >  v;
	while (t--){
		char c; cin >> c;
		int x,y,x1,y1; cin >> x >> y >> x1 >> y1;
		v.push_back({c,{x,y,x1,y1}});
	}
	reverse(v.begin(),v.end());
	for(auto i : v){
		if(i.first=='V') xu_li_V(i.second);
		else xu_li_H(i.second);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
