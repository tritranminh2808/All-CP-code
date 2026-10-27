#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt(int l, int x, int d) {
    int tot=x-l+1;
    int div=(x/d)- ((l-1)/d);
    return tot-div;
}
int find(int L, int R, int d, int id) {
    int l=L,r=R;
    while(l<r) {
        int mid = (l+r)/2;
        if(cnt(L,mid,d)>id)r=mid;
        else l=mid+1;
    }
    return l;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int i = 1;
    while(1>0){
        int l=(i==1?1:(int)pow(10,i-1));
        int r=(int)pow(10,i)-1;
        int tot=9*(i==1?1:(int)pow(10,i-1));
        int div=(r/(i+1))-((l-1)/(i+1));
        int valid=tot-div;
        int dg=valid*i;
        if(n > dg) { 
            n-=dg; 
            i++;
        } else {
            int id=(n-1)/i;
            int pos=(n-1)%i;
            int num=find(l,r,i+1,id);
            string s=to_string(num);
            cout << s[pos];
            break;
        }
    }
    return 0;
}
 
