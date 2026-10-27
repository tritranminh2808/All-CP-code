#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 1e6 +7;
int a[MAX];

int main(){
    long long res = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    int k = n-1;
    for (int i = 0; i < n; i++){
        while(a[i] + a[k] > m)k--;
        if (k > i) res += k-i;
        else break;
    }
    cout << res;
}
