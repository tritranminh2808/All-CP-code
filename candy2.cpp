#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int xu_li(vector<int> &a, int m, int n) {
    sort(a.begin(),a.end(),cmp);
    int l=0,r=a[0],res=9999999999999;

    while (l<=r) {
        int mid=(l+r)/2;
        int need=0;
        for (int i=0;i<n;i++) {
            need+=max((int)0,a[i]-mid);
            if (need>m) break;
        }
        if (need<=m) {
            res=mid;
            r=mid - 1;
        } 
		else l= mid + 1;
    }

    int mm=m;
    for (int i=0;i<n;i++) {
        if (a[i]>res) {
            mm-=(a[i]-res);
            a[i]=res;
        }
    }

    for (int i=0;i<n&&mm>0;i++) {
        if (a[i]>0) {
            a[i]--;
            mm--;
        }
    }

    int sol = 0;
    for (int i = 0; i < n; i++) {
        sol += a[i]*a[i];
    }
    return sol;
}

signed main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << xu_li(a, m, n);
    return 0;
}

