#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    if(n%2==0){
    	cout << n/2-1;
    	return 0;
	}
	cout << n/2;
    
    return 0;
}

