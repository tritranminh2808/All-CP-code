#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    char n; cin >> n; cout << char(int(n)-1) << "\n" << char(int(n)+1);
    return 0;
}

