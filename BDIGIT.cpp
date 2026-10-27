#include<bits/stdc++.h>
using namespace std;
unsigned long long f(unsigned long long n){
    if(n == 0)return 0;
    unsigned long long l = 1;
    while(l <= n/2)l = l * 2;
    return 1 - f(n - l);
}
int main()
{
    int t;
    cin >> t;
    for( int i = 1; i <= t; i++){
        unsigned long long n;
        cin >> n;
        //if(n>9223372036854780000) cout << 1 << endl;
        //else cout << f(n) << endl;
        cout << bitset<64>(n).count()%2 << "\n";
    }

}
