#include <bits/stdc++.h>
#include <fstream>
using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int rnd(int l, int r){
    return l+rng()%(r-l+1);
}
fstream f;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int ii=1;ii<=1;ii++){
        f.open("input.inp",ios::out);
        int n=3000,t=3000;
        vector <int> a(5001),b(5001);
        for(int i=1;i<=n;i++) b[i]=rnd(1,10);
        for(int i=1;i<=n;i++) a[i]=rnd(1,10);
        f << n << " " << t <<"\n";
        for(int i=1;i<=n;i++) f << a[i] << " ";
        f << "\n";
        for(int i=1;i<=n;i++) f << b[i] << " ";
        f << "\n";
        while(t--){
            int l=rnd(1,n);
            int r=rnd(l,n);
            int l2=rnd(1,n);
            int r2=rnd(1,n);
            f << l << " "<< r << " " << l2 << " " << r2 << "\n";
        }
        f.close();
        /*system("hashcor_L.exe");
        system("trau_hashxor_L.exe");
        if(system("fc output.out output.ans")){
            cout << "Test " << ii << ": Wrong!!!\n";
            return 0;
        }
        cout << "Test" << ii << ": Accepted!\n";*/
    }

}
