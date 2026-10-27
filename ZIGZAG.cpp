#include <iostream>
using namespace std;

int main() {
    unsigned long long n, x, y, z;
    cin >> n >> x >> y >> z;

    unsigned long long v;
    if (x % 2 == 1) {
        v = (x - 1) * n + y;
    } else {
        v = (x - 1) * n + (n - y + 1);
    }
    cout << v << "\n";

    unsigned long long r = (z - 1) / n + 1;
    unsigned long long c = (z - 1) % n + 1;

    cout << r << " ";
    if (r % 2 == 1) {
        cout << c;
    } else {
        cout << n - c + 1;
    }
    
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
const long long p=1e6+5;


int main(){
unsigned	long long n,x,y,z; cin >> n >> x >> y >> z;
	unsigned long long k;

	k=n*(x-1)+y;cout << k << "\n";
	unsigned long long p=z/n;
	if(z%n!=0) p++;
	cout << p <<" ";
	if(z%n==0){
		if(p%2==0){
		cout << "1";return 0;}
		else {
			cout << n;return 0;
		}
	}
	if(p%2!=0){
		cout << z%n;return 0;
	}
	cout << n-(z%n)+1;
	return 0;
}*/
