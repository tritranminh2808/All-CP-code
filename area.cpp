#include <bits/stdc++.h>
using namespace std;
using i128=__int128;
long long n,x,y;
struct pl{
	int x,y;
};
void pr(i128 x){
	if(x<0){
		cout << "-1\n";
		return;
	}
	string s;
	while(x){
		s+='0'+x%10;
		x/=10;
	}
	reverse(s.begin(),s.end());
	cout << s << "\n";
}
int main(){
	cin >> n >> x >> y;
	long long d=abs(x-y);
	long long a=n-d,b=d+1;
    i128 s1=a*b+(a-1)*(b-1);
    long long s=x+y,c=0;
    if(s<=n+1) c=s-1;
    else c=2*n-s+1;
    long long d2=n-c+1;
    i128 s2=c*d2+(c-1)*(d2-1),s3=b*d2+(b-1)*(d2-1);
    pr(s1+s2-s3);
    return 0;
}
