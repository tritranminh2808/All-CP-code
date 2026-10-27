#include <bits/stdc++.h>
using namespace std;
struct pl{
	int traitren,phaitren,traiduoi,phaiduoi;
};
pl pre[2005][2005];
int x[2005][2005];
pair<int,int> a[2005];
int n,m;
vector <int> v;
int gtrimoi[1000006];
void nen(){
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++) gtrimoi[v[i]]=i+1;
	for(int i=0;i<n;i++){
		a[i].first=gtrimoi[a[i].first];
		a[i].second=gtrimoi[a[i].second];
		x[a[i].first][a[i].second]=1;
	}
}
int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin>> a[i].first>>a[i].second;
		v.push_back(a[i].first);
		v.push_back(a[i].second);
	}
	nen();
	int K=v.size();
	for(int i=1;i<=K;i++){
		for(int j=1;j<=K;j++) pre[i][j].traiduoi=pre[i-1][j].traiduoi+pre[i][j-1].traiduoi-pre[i-1][j-1].traiduoi+x[i][j];
	}
	for(int i=K;i>=0;i--){
		for(int j=1;j<=K;j++) pre[i][j].traitren=pre[i+1][j].traitren+pre[i][j-1].traitren-pre[i+1][j-1].traitren+x[i][j];
	}
	for(int i=K;i>=0;i--){
		for(int j=K;j>=0;j--) pre[i][j].phaitren=pre[i+1][j].phaitren+pre[i][j+1].phaitren-pre[i+1][j+1].phaitren+x[i][j];
	}
	for(int i=1;i<=K;i++){
		for(int j=K;j>=0;j--) pre[i][j].phaiduoi=pre[i-1][j].phaiduoi+pre[i][j+1].phaiduoi-pre[i-1][j+1].phaiduoi+x[i][j];
	}
	int sol = INT_MAX;
    for(int i=1;i< K;i++){
      for(int j=1;j< K;j++){
        int bl = pre[i][j].traiduoi;  
        int br = pre[i][j+1].phaiduoi;  
		int tl = pre[i+1][j].traitren;  
        int tr = pre[i+1][j+1].phaitren;  
        sol = min(sol, max(max(bl,br), max(tl,tr)));
      }
    }
    cout<<sol;
    return 0;
}
