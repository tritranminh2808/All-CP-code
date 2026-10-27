#include <bits/stdc++.h>
using namespace std;
const int pp=2e5+1;
struct gg{
    int x,y,id;
};
gg a[200005];
bool cmp(gg u, gg v){
    return u.x+u.y<v.x+v.y;
}
bool cmp2(gg u, gg v){
    return u.x-u.y<v.x-v.y;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n;cin>> n;
        for(int i=1;i<=n;i++){
            cin>> a[i].x >> a[i].y;
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        int sol=0,res=0;
        for(int i=1;i<=n/2;i++){
            // cout << a[i].id << " " << a[n-i+1].id << "\n";
            sol+=abs(a[i].x-a[n-i+1].x)+abs(a[i].y-a[n-i+1].y);
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n/2;i++){
            // cout << a[i].id << " " << a[n-i+1].id << "\n";
            res+=abs(a[i].x-a[n-i+1].x)+abs(a[i].y-a[n-i+1].y);
        }
        if(sol<res){
            for(int i=1;i<=n/2;i++) cout << a[i].id << " " << a[n-i+1].id << "\n";
        }
        else{
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++) cout << a[i].id << " " << a[n-i+1].id << "\n";
        }
        // cout << sol << "\n";
	}
	return 0;
	
}
