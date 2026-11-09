#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<pair<int,int>> v;
    long long sumA = 0;
    int N1 = 0;
    for (int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;
        sumA += A;
        if (B == 1) N1++;
        else v.push_back({B, A});
    }
    int Q; 
	cin >> Q;
    vector<int> q(Q);
    int maxX = 0;
    for (int i = 0; i < Q; i++) {
        cin >> q[i];
        maxX = max(maxX, q[i]);
    }
    sort(v.begin(), v.end());
    vector<long long> d(maxX + 2, 0);
    for (int i = 0; i < (int)v.size();) {
        int B = v[i].first, A = v[i].second;
        int j = i;
        while (j < (int)v.size() && v[j] == v[i]) j++;
        long long cnt = j - i;
        long long add = 1LL * B * cnt;
        for (int p = B - A; p <= maxX; p += B) d[p] += add;
        i = j;
    }
    for (int i = 1; i <= maxX; i++) d[i] += d[i - 1];
    for (int x : q) cout << 1LL * (N - N1) * x + sumA - d[x] << '\n';
}
