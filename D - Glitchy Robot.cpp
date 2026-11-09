#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n + 1), s(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    const long long INF = (1LL << 62);

    vector<long long> lmin(n + 1), lmax(n + 1);
    vector<long long> rmin(n + 2, INF), rmax(n + 2, -INF);

    lmin[0] = lmax[0] = s[0];

    for (int i = 1; i <= n; i++) {
        lmin[i] = min(lmin[i - 1], s[i]);
        lmax[i] = max(lmax[i - 1], s[i]);
    }

    for (int i = n; i >= 0; i--) {
        rmin[i] = min(rmin[i + 1], s[i]);
        rmax[i] = max(rmax[i + 1], s[i]);
    }

   
    long long ans = lmax[n] - lmin[n] + 1;

    for (int i = 1; i <= n; i++) {
        
        long long d = -2LL * a[i];

        long long mn = lmin[i - 1];
        long long mx = lmax[i - 1];

        mn = min(mn, rmin[i] + d);
        mx = max(mx, rmax[i] + d);

        ans = max(ans, mx - mn + 1);
    }

    cout << ans << '\n';

    return 0;
}
