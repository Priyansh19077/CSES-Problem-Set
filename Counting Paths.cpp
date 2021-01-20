/* Priyansh Agarwal*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<map>
using namespace std;
using namespace __gnu_pbds;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define nline "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define debug(x) cout << #x << " " << x <<endl;
#define set_bits __builtin_popcount
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll* fact) {ll val1 = fact[n]; ll val2 = mminvprime(fact[r], m); ll val3 = mminvprime(fact[n - r], m); return ((val1 * val2) % m * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*--------------------------------------------------------------------------------------------------------------------------*/
int find_lca(int a, int b, int **parent, int *level, int limit)
{
	if (level[a] > level[b])
		swap(a, b);
	int d = level[b] - level[a];
	while (d > 0)
	{
		int i = int(log2(d));
		b = parent[b][i];
		d -= (1 << i);
	}
	if (a == b)
		return a;
	for (int i = limit - 1; i >= 0; i--)
	{
		if (parent[a][i] != -1 && (parent[a][i] != parent[b][i]))
		{
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}
void dfs(int start, vector<int>*edges, int *level, int parent, int **parent1)
{
	for (auto i : edges[start])
	{
		if (i != parent)
		{
			parent1[i][0] = start;
			level[i] = level[start] + 1;
			dfs(i, edges, level, start, parent1);
		}
	}
}
void dfs1(int start, vector<int>*edges, int parent, int *value)
{
	int x = value[start];
	for (auto i : edges[start])
	{
		if (i != parent)
		{
			dfs1(i, edges, start, value);
			x += value[i];
		}
	}
	value[start] = x;
}
int main()
{
	fastio();
	int n, m;
	cin >> n >> m;
	vector<int>*edges = new vector<int>[n];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	int limit = log2(n) + 1;
	int **parent = new int*[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = new int[limit];
		for (int j = 0; j < limit; j++)
			parent[i][j] = -1;
	}
	int *level = new int[n]();
	dfs(0, edges, level, - 1, parent);
	for (int i = 1; i < limit; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x = parent[j][i - 1];
			if (x != -1)
				parent[j][i] = parent[x][i - 1];
		}
	}
	int *value = new int[n]();
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int x = find_lca(a, b, parent, level, limit);
		value[a] += 1;
		value[b] += 1;
		value[x] -= 1;
		int y = parent[x][0];
		if (y != -1)
			value[y] -= 1;
	}
	dfs1(0, edges, -1, value);
	for (int i = 0; i < n; i++)
		cout << value[i] << " ";
	return 0;
}