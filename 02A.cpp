#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x1,y1,a1,x2,y2,a2; cin >> x1 >> y1 >> a1 >> x2 >> y2 >> a2;
	if(x1==x2&&y1==y2&&a1==a2){
		cout << 1; return 0;
	}
	if(x1<=x2&&y1<=y2&&a1>=a2+abs(x1-x2)&&a1>=a2+abs(y1-y2)){
		cout << 2;
		return 0;
	}
	if(x2<=x1&&y2<=y1&&a2>=a1+abs(x1-x2)&&a2>=a1+abs(y1-y2)){
		cout << 2;
		return 0;
	}
	if(x1+a1<=x2||y1+a1<=y2){
		cout << 4;return 0;
	}
	if(x2+a2<=x1||y2+a2<=y1){
		cout << 4; return 0;
	}
	cout << 3;
}

