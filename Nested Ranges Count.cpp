/* Priyansh Agarwal*/
#include<iostream>
#include<vector>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) (int)(x.size())

//#ifndef ONLINE_JUDGE
//#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
//#else
//#define debug(x);
//#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
struct range {
      int left;
      int right;
      int index;
};
bool compare(range r1, range r2) {
      if (r1.left < r2.left)
            return true;
      if (r1.left > r2.left)
            return false;
      return r1.right > r2.right;
}
bool compare1(pair<int, int> p1, pair<int, int> p2) {
      if (p1.ff < p2.ff)
            return true;
      if (p1.ff > p2.ff)
            return false;
      return p1.ss > p2.ss;
}
void update(int start, vector<int> &tree, int n, int value) {
      for (; start <= n; start += start & (-start))
            tree[start] += value;
}
int query(int start, vector<int> &tree) {
      int sum = 0;
      for (; start > 0; start -= start & (-start))
            sum += tree[start];
      return sum;
}
void solve() {
      int n;
      cin >> n;
      vector<range> v1(n);
      vector<int> BIT1(n + 1, 0);
      for (int i = 0; i < n; i++) {
            int left, right;
            cin >> left >> right;
            v1[i] = {left, right, i};
      }
      sort(v1.begin(), v1.end(), compare);
      vector<pair<int , int >> opening(n);
      vector<pair<int, int>> closing(n);
      for (int i = 0; i < n; i++) {
            opening[i] = {v1[i].left, v1[i].index};
            closing[i] = {v1[i].right, i};
      }
      sort(closing.begin(), closing.end(), compare1);
//       debug(opening);
//       debug(closing);
      int i = 0, j = 0;
      vector<int> ans(n);
      while (i < n || j < n) {
            if (i < n && opening[i].ff < closing[j].ff) {
                  update(i + 1, BIT1, n, 1);
                  i++;
            } else {
                  update(closing[j].ss + 1, BIT1, n, -1);
                  int val = query(closing[j].ss + 1, BIT1);
//                   debug(val);
                  int index_in_sorted = closing[j].ss;
                  int actual_index = opening[index_in_sorted].ss;
                  ans[actual_index] = val;
                  j++;
            }
      }
      vector<int> ans2(n);
      vector<int> BIT2(n + 1, 0);
      i = 0, j = 0;
      while (i < n || j < n) {
            if (i < n && opening[i].ff < closing[j].ff) {
                  i++;
            } else {
                  int val = query(closing[j].ss + 1, BIT2);
//                   debug(val);
                  int index_in_sorted = closing[j].ss;
                  int actual_index = opening[index_in_sorted].ss;
                  ans2[actual_index] = val;
                  update(1, BIT2, n, 1);
                  if (closing[j].ss + 2 <= n)
                        update(closing[j].ss + 2, BIT2, n, -1);
                  j++;
            }
      }
      for (int i = 0; i < n; i++)
            cout << ans2[i] << " ";
      cout << nline;
      for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
      cout << nline;
}
int main() {
      fastio();
//      #ifndef ONLINE_JUDGE
//      freopen("Input.txt", "r", stdin);
//      freopen("Output.txt", "w", stdout);
//      freopen("Error.txt", "w", stderr);
//      #endif
      auto start1 = high_resolution_clock::now();
      solve();
      auto stop1 = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop1 - start1);
//      #ifndef ONLINE_JUDGE
//      cerr << "Time: " << duration.count() / 1000 << endl;
//      #endif
      return 0;
}