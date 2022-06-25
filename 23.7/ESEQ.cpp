#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define per(i, r, l) for (int i = (int)(r); i >= (int)(l); i--)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

template <typename _Tp> bool maximize(_Tp &__a, const _Tp &__b) { if (__a < __b) { __a = __b; return true; } return false; }
template <typename _Tp> bool minimize(_Tp &__a, const _Tp &__b) { if (__a > __b) { __a = __b; return true; } return false; }

const int siz = 1e5 + 2;
const int SIZ = 1e6 + 2;
const int mod = 1e9 + 7;
const int maxx = 2e9;
const ll MAXX = 1e18;
const string file = "ESEQ";

int a[siz];
ll ssum[siz];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);

    int n;
    cin >> n;

    rep (i, 1, n) {
        cin >> a[i];
    }

    unordered_map <ll, int> cnt;
    per (i, n, 1) {
        ssum[i] = ssum[i + 1] + a[i];

        cnt[ssum[i]]++;
    }

    ll psum = 0, ans = 0;
    rep (i, 1, n) {
        psum += a[i];
        cnt[ssum[i]]--;
        ans += cnt[psum];
    }

    cout << ans << "\n";

//    cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}