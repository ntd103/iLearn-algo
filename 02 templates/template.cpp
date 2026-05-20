// ========================================
// Competitive Programming Template
// Author: [Your Name]
// ========================================

#include <bits/stdc++.h>
using namespace std;

// ============ TYPE DEFINITIONS ============
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// ============ MACROS ============
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)

// ============ CONSTANTS ============
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

// ============ FAST I/O ============
void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// ============ DEBUG ============
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#else
#define debug(x)
#define debug2(x, y)
#endif

// ============ UTILITY FUNCTIONS ============
template <typename T>
void print_vector(const vector<T> &v) {
    for (const auto &x : v)
        cout << x << " ";
    cout << "\n";
}

// ============ MATH UTILITIES ============
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll mod_inv(ll a, ll mod) {
    return mod_pow(a, mod - 2, mod);
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// ============ MAIN SOLUTION ============
void solve() {
    // Your solution here
}

int main() {
    setup();

    int t = 1;
    cin >> t; // Comment this line for single test case

    while (t--) {
        solve();
    }

    return 0;
}
