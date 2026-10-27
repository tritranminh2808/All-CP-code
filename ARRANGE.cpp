#include <bits/stdc++.h>
using namespace std;

long long sumint(long long a, long long i){
	long long b=a-i+1;
	if(b<1) b=1;
	return  (a+b)*(a-b+1)/2;
}
long long n, m, k;
bool keepable(long long a){
	return m-a>= (sumint(a-1,k-1)+sumint(a-1,n-k));
}
long long solve()
{
	long long a=0;
	while(keepable(a+1000000))a+=1000000;
	while(keepable(a+100000))a+=100000;
	while(keepable(a+10000))a+=10000;
	while(keepable(a+1000))a+=1000;
	while(keepable(a+100))a+=100;
	while(keepable(a+1))a+=1;
	return m-a;
}
int main() {
    long long T;
    cin >> T;
    while (T--) {
        
        cin >> n >> m >> k;
        cout << solve() << "\n";
    }
    return 0;
}

