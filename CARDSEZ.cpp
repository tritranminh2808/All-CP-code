#include <iostream>
#include <vector>
using namespace std;

void perform_shuffle(vector<int>& cards, int i, int m, int j) {   
    vector<int> segment(cards.begin() + i - 1, cards.begin() + i - 1 + m);

    cards.erase(cards.begin() + i - 1, cards.begin() + i - 1 + m);

    cards.insert(cards.begin() + j - 1, segment.begin(), segment.end());
}

int main() {
	freopen("cardsez.inp","r",stdin);
	freopen("cardsez.out","w",stdout);
    int n, x;
    cin >> n >> x;
    vector<int> cards(n);
 
    for (int i = 0; i < n; i++) {
        cards[i] = i + 1;
    }

    for (int k = 0; k < x; k++) {
        int i, m, j;
        cin >> i >> m >> j;
        perform_shuffle(cards, i, m, j);
    }

    for (int card : cards) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}

