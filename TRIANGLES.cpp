#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#pragma GCC optimize ("O3,unroll-loops")
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned int n,x,i,j,k,s=0;
    cin>>n;
    vector<unsigned int> A,B;
    unordered_map<unsigned int,unsigned int> D;
    for (i=0;i<n;++i) {
        cin>>x;
        if (D[x]<3) {
            ++D[x];
            if (D[x]<2) A.push_back(x);
            else if (D[x]<3) B.push_back(x);
            else ++s;
        }
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for (k=2;k<A.size();++k) {
        i=0,j=k-1;
        while (i<j) {
            if (A[i]+A[j]>A[k]) {
                s+=j-i;
                --j;
            } else ++i;
        }
    }
    for (i=0;i<B.size();++i) {
        for (j=0;j<A.size();++j) {
            if (A[j]!=B[i]) {
                if (B[i]<A[j]) {
                    if (B[i]*2>A[j]) ++s;
                } else ++s;
            }
        }
    }
    cout<<s;
}
