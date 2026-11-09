#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cards[i] = i + 1;
    }

    for (int qi = 0; qi < Q; qi++) {
        int K;
        cin >> K;
for (int l = 0, r = K - 1; l < r; l++, r--) {
    swap(cards[l], cards[r]);
}

       
        for (int i = 0; i < K; i++) {
            cards[i] = -cards[i];
        }
    }

   for (int i = 0; i < N; i++) {
    cout << cards[i] << '\n';
}
        

    return 0;
}
