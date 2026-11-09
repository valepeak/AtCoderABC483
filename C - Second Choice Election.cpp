#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    vector<int> c(a + 1, 0);
    vector<vector<int> > d(a + 1);

    for (int i = 0; i < b; i++) {
        int e, f;
        cin >> e >> f;
        c[e]++;
        d[e].push_back(f);
    }

    set<pair<int, int> > g;

    for (int i = 1; i <= a; i++) {
        g.insert(make_pair(c[i], -i));
    }

    for (int k = 1; k <= a; k++) {
        g.erase(make_pair(c[k], -k));

        for (vector<int>::iterator it = d[k].begin(); it != d[k].end(); ++it) {
            int h = *it;

            g.erase(make_pair(c[h], -h));
            c[h]++;
            g.insert(make_pair(c[h], -h));
        }

        int w = -(g.rbegin()->second);
        cout << w << "\n";

        for (vector<int>::iterator it = d[k].begin(); it != d[k].end(); ++it) {
            int h = *it;

            g.erase(make_pair(c[h], -h));
            c[h]--;
            g.insert(make_pair(c[h], -h));
        }

        g.insert(make_pair(c[k], -k));
    }

    return 0;
}
