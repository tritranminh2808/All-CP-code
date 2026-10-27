#include <bits/stdc++.h>
using namespace std;
int n,a[8],b[8],c[8],d1,d2,x;
set<pair<int,int>>s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RECTPAPERS.inp","r",stdin);
    freopen("RECTPAPERS.out","w",stdout);
    cin>>n;
    while(n--)
    {
        s.clear();
        cin>>a[1]>>a[2]>>b[1]>>b[2]>>c[1]>>c[2];
        for(int ia=1;ia<=2;ia++)
        {
            for(int ib=1;ib<=2;ib++)
            {
                for(int ic=1;ic<=2;ic++)
                {
                    if(a[ia]==b[ib]&&b[ib]==c[ic])
                    {
                        s.insert(make_pair(min(a[ia],a[3-ia]+b[3-ib]+c[3-ic]),max(a[ia],a[3-ia]+b[3-ib]+c[3-ic])));
                    }
                    if(a[ia]==b[ib])
                    {
                        if(a[3-ia]+b[3-ib]==c[ic])
                        {
                            s.insert(make_pair(min(c[ic],a[ia]+c[3-ic]),max(c[ic],a[ia]+c[3-ic])));
                        }
                    }
                    if(a[ia]==c[ic])
                    {
                        if(a[3-ia]+c[3-ic]==b[ib])
                        {
                            s.insert(make_pair(min(b[ib],a[ia]+b[3-ib]),max(b[ib],a[ia]+b[3-ib])));
                        }
                    }
                    if(c[ic]==b[ib])
                    {
                        if(c[3-ic]+b[3-ib]==a[ia])
                        {
                            s.insert(make_pair(min(a[ia],c[ic]+a[3-ia]),max(a[ia],c[ic]+a[3-ia])));
                        }
                    }
                }
            }
        }
        cout<<s.size()<<'\n';
    }
    return 0;
}
