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
void solve() {
    // solve
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