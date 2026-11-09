#include <bits/stdc++.h>
using namespace std;
const int HS = 1 << 20;
const int HMASK = HS - 1;
int hkey[HS];
int hval[HS];
bool hused[HS];

int hfind(int k) {
    unsigned h = (unsigned)k * 2654435761u & HMASK;
    while (hused[h] && hkey[h] != k) h = (h + 1) & HMASK;
    return hused[h] ? hval[h] : 0;
}

void hinsert(int k) {
    unsigned h = (unsigned)k * 2654435761u & HMASK;
    while (hused[h] && hkey[h] != k) h = (h + 1) & HMASK;
    if (hused[h]) hval[h]++;
    else {
        hused[h] = true;
        hkey[h] = k;
        hval[h] = 1;
    }
}

struct Node {
    int key, x, y;
    bool operator<(const Node &o) const {
        return key < o.key;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        char buf[10];
        scanf("%s", buf);
        s[i] = buf;
    }

    int pw[7];
    pw[0] = 1;
    for (int i = 1; i <= m; i++) pw[i] = pw[i - 1] * 26;

    vector<int> code(n);
    long long ans = 0;

    // æ‡¿Î 0
    for (int i = 0; i < n; i++) {
        int key = 0;
        for (int j = 0; j < m; j++) key = key * 26 + (s[i][j] - 'a');
        code[i] = key;
        ans += hfind(key);
        hinsert(key);
    }

   
    long long cnt1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int old = s[i][j] - 'a';
            int base = code[i] - old * pw[m - 1 - j];
            for (int c = 0; c < 26; c++) {
                if (c == old) continue;
                int nc = base + c * pw[m - 1 - j];
                cnt1 += hfind(nc);
            }
        }
    }
    ans += cnt1 / 2;

   
    static int f12[26][26];

    for (int p = 0; p < m; p++) {
        for (int q = p + 1; q < m; q++) {
            vector<Node> v(n);
            for (int i = 0; i < n; i++) {
                int key = 0;
                for (int j = 0; j < m; j++) {
                    if (j == p || j == q) continue;
                    key = key * 26 + (s[i][j] - 'a');
                }
                v[i].key = key;
                v[i].x = s[i][p] - 'a';
                v[i].y = s[i][q] - 'a';
            }
            sort(v.begin(), v.end());

            for (int l = 0; l < n; ) {
                int r = l;
                while (r < n && v[r].key == v[l].key) r++;

                int f1[26] = {0};
                int f2[26] = {0};

                for (int i = l; i < r; i++) {
                    f1[v[i].x]++;
                    f2[v[i].y]++;
                    f12[v[i].x][v[i].y]++;
                }

                long long tot = 1LL * (r - l) * (r - l - 1) / 2;
                long long a1 = 0, a2 = 0, a12 = 0;

                for (int c = 0; c < 26; c++) {
                    a1 += 1LL * f1[c] * (f1[c] - 1) / 2;
                    a2 += 1LL * f2[c] * (f2[c] - 1) / 2;
                }
                for (int i = l; i < r; i++) {
                    int x = v[i].x, y = v[i].y;
                    if (f12[x][y] > 0) {
                        long long f = f12[x][y];
                        a12 += f * (f - 1) / 2;
                        f12[x][y] = 0;
                    }
                }

                ans += tot - a1 - a2 + a12;
                l = r;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
