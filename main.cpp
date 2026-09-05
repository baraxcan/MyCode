#ifdef LOCAL
    #include "local.h"
#else
    #include <bits/stdc++.h>
#endif
#define ednl endl;

using namespace std;

#ifdef LOCAL
    #define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
    #define eprintf(...) 42;
#endif

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
#ifndef LOCAL
std::ostream& operator << (std::ostream& dest, __int128_t value) {
    if (value == 0) return dest << 0;
    if (value < 0) {
        dest << '-';
        value = -value;
    }
    __int128_t t = value;
    char buffer[64];
    char* d = std::end(buffer);
    while (t > 0) {
        --d;
        *d = "0123456789"[t % 10];
        t /= 10;
    }
    return dest.write(d, std::end(buffer) - d);
}
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<bool> vecbool;
typedef vector<vector<bool>> vecvecbool;
typedef vector<int> vecInt;
typedef vector<double> vecdbl;
typedef vector<char> vecChar;
typedef vector<vector<char>> vecvecChar;
typedef vector<pair<int, int>> vecpii;
typedef vector<vector<pair<int, int>>> vecvecpii;
typedef vector<pair<double, double>> vecdd;
typedef vector<string> vecStr;
typedef vector<long long> vecll;
typedef vector<vector<int>> vecvecInt;
typedef vector<vector<long long>> vecvecll;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef map<int, bool> mib;
typedef map<long long, long long> mll;
typedef set<int> seti;
struct cell {int x, y;};
/*----------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------WORK-AREA------------------------------------------------------*/
const int MOD = 1e9 + 7;

struct segtree {
    vecll tree;
    int size = 1;
    segtree(vecInt& a) {
        init(a.size());
        build(a, 0, 0, size);
    }
    void init(int n) {
        while (size <= n)
            size *= 2;
        tree.assign(2 * size - 1, LLONG_MAX);
    }
    void build(vecInt& a, int x, int l, int r) {
        if (r - l == 1) {
            if (l < a.size()) {
                tree[x] = a[l];
            }
        }
        else {
            int m = (l + r) / 2;
            build(a, 2 * x + 1, l, m);
            build(a, 2 * x + 2, m, r);
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }
    void set(int i, int v, int x, int l, int r) {
        if (r - l == 1) {
            tree[x] = v;
            return;
        }
        int m = (r + l) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, l, m);
        }
        else {
            set(i, v, 2 * x + 2, m, r);
        }
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    ll get(int lx, int rx, int x, int l, int r) {
        if (l >= rx || r <= lx) return LLONG_MAX;
        if (l >= lx && r <= rx) return tree[x];
        int m = (l + r) / 2;
        ll a = get(lx, rx, 2 * x + 1, l, m);
        ll b = get(lx, rx, 2 * x + 2, m, r);
        return min(a, b);
    }
    ll get(int lx, int rx) {
        return get(lx, rx, 0, 0, size);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vecInt a(n, 0); for (int i = 0; i < n; ++i) cin >> a[i];
    segtree tree(a);
    for (int q = 0; q < m; ++q) {
        int c; cin >> c;
        if (c == 1) {
            int i, v; cin >> i >> v;
            tree.set(i, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << tree.get(l, r) << endl;
        }
    }
}
/*----------------------------------------------------------------------------------------------------------------------*/
//   ####    ##  ##             ##    ##  ##    ######    ##    ######    ##    ######  ##   ##
//   ##  #   ##  ##             ##   ## ##  ##  ##  ##   ####   # ## #   ####   ##   #  ##   ##
//   ##  #   ##  ##             ##  ##  ##  ##  ##  ##  ##  ##    ##    ##  ##  ## #    ##   ##
//   #####    ####              ## ##   ##  ##  #####   ##  ##    ##    ##  ##  ####     ## ##
//   ##  ##    ##               ####    ######  ## ##   ######    ##    ######  ## #     ## ##
//   ##  ##    ##               ## ##   ##  ##  ##  ##  ##  ##    ##    ##  ##  ##   #    # #
//   ##  ##    ##               ## ##   ##  ##  ##  ##  ##  ##    ##    ##  ##  ##   #    ###
//   #####    ####              ##  ##  ##  ##  ##  ##  ##  ##   ####   ##  ##  ######     #
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    
    // int t; cin >> t;
    // while (t--) {
    //     solve();
    // }


    eprintf("time = %.5lf\n", getCurrentTime());
    
    return 0;
}