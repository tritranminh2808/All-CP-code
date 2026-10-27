#include <bits/stdc++.h>
#define int long long
using namespace std;
int xu_li(int r1,int p1,int s1, int r2, int p2,int s2,int maxn){
    maxn+=min(r1,s2)*2;
    int rr=min(r1,s2);
    r1-=rr;s2-=rr;
    maxn+=min(p1,r2)*2;
    int pp=min(p1,r2);
    p1-=pp;r2-=pp;
    maxn+=min(s1,p2)*2;
    int ss=min(s1,p2);
    s1-=ss;p2-=ss;
    while(r1>0&&r2>0){
    	maxn+=min(r1,r2);
    	int rrr=min(r1,r2);
    	r1-=rrr;r2-=rrr;
	}
	while(p1>0&&p2>0){
    	maxn+=min(p1,p2);
    	int ppp=min(p1,p2);
		p1-=ppp;p2-=ppp;
	}
	while(s1>0&&s2>0){
    	maxn+=min(s1,s2);
    	int sss=min(s1,s2);
    	s1-=sss;s2-=sss;
	}
	return maxn;
}
signed main() {
	freopen("rps.inp","r",stdin);
	freopen("rps.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int r1,p1,s1,r2,p2,s2;
        cin >> r1 >> p1 >> s1 >> r2 >> p2 >> s2;
        int maxn=0,minn=0;
        cout << xu_li(r1,p1,s1,r2,p2,s2,maxn) << " ";
        int rr=min(r1,p2),pp=min(p1,s2),ss=min(s1,r2);
        r1-=rr;p2-=rr;
        p1-=pp;s2-=pp;
        s1-=ss;r2-=ss;
        cout << xu_li(r1,p1,s1,r2,p2,s2,maxn) << "\n";
    }
    return 0;
}

