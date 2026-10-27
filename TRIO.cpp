/*#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    long long count = 0;
    
    for (long long a = 1; a < n / 3; ++a) {
		
		if((a+1)<=(n-a-1)/2)count += (n-a-1)/2-(a+1)+1;
    }
  
    cout << count ;
    
    return 0;
}*/
#include <iostream>
using namespace std;
long long sol=0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    int k=n-4;
    while(k>0){
    	sol+=k/2;
    	k-=3;
	}
	cout << sol;
    return 0;
}


