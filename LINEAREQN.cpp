#include <bits/stdc++.h>
using namespace std;

int main(){
	float p,s; cin >> p >> s;
	float tong=p/2;
	float delta=tong*tong-4*s;
	cout << fixed << setprecision(2)<<min(abs((float)(-tong-sqrt(delta))/2 ),abs((float)(-tong+sqrt(delta))/2))<< endl << fixed << setprecision(2) << max(abs((float)(-tong+sqrt(delta))/2),abs((float)(-tong-sqrt(delta))/2));
	
}
