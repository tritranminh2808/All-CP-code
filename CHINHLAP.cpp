#include <iostream>
#include <vector>

using namespace std;


void generatePermutations(vector<int>& current, int n, int k) {
    if (current.size() == k) {
        
        for (int i=0;i<current.size();++i) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = 1; i <= n; ++i) {
        current.push_back(i);
        generatePermutations(current, n, k);
        current.pop_back();  
    }
}

int main() {
    int n, k;
    freopen("CHINHLAP.INP","r+",stdin);
	freopen("CHINHLAP.OUT","w+",stdout);
    
    cin >> n >> k;
    
    vector<int> current;
   
    generatePermutations(current, n, k);
    
    return 0;
}

