#include <bits/stdc++.h>
using namespace std;
int SD(int x)

{

   int s=1, i;
   for (i = 2; i * i < x; i++)
   {
	   	if (x % i == 0)
	    s += i + x / i;
	   
   }
	int b=sqrt(x);if(b*b==x) s+=sqrt(x);
   return s ;
}


int main()

{

         int n, a, b;
         cin >> n;
         for (b = 2; b <= n; b++)
    if (SD(a) == b && SD(b) == a)
        cout << "NO\n";
    else{
    cout << "YES\n";

    }

}
