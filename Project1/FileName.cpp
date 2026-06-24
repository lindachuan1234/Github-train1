#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{

	return 0;
}
//const int max_num = 100005;
//vector<int>adj[max_num];
//int n, d, ans;
//void dfs(int x, int fa, int step) {
//	if (step <= d && x != 1) {
//		ans++;
//	}
//	else if (step > d)  return;
//	for (int v : adj[x]) {
//		if (v == fa)	continue;
//		dfs(v, x, step + 1);
//	}
//}
//int main()
//{
//	cin >> n >> d;
//	for (int i = 1; i < n; i++) {
//		int u, v; cin >> u >> v;
//		adj[u].push_back(v);
//		adj[v].push_back(u);
//	}
//	dfs(1, 0, 0);
//	cout << ans;
//	return 0;
//}
//#define int long long
//struct node {
//	int a;
//	int b;
//	int c;
//};
//bool cmp(const node& x, const node& y) {
//	return x.b * y.c > y.b * x.c;
//}
//signed main()
//{
//	int t, n; cin >> t >> n;
//	vector<node>no(n + 1);
//	vector<int>dp(t + 1, 0);
//	for (int i = 1; i <= n; i++)	cin >> no[i].a;
//	for (int i = 1; i <= n; i++)	cin >> no[i].b;
//	for (int i = 1; i <= n; i++)	cin >> no[i].c;
//	sort(no.begin() + 1, no.end(), cmp);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = t; j >= no[i].c; j--) {
//			dp[j] = max(dp[j], dp[j - no[i].c] + (no[i].a - j * no[i].b));
//			ans = max(ans, dp[j]);
//		}
//	}cout << ans;
//	return 0;
//}
//const int max_num = 100005;
//vector<int>adj[max_num];
//int sz[max_num], s[max_num], max_sub[max_num], sum, ans;
//void dfs(int x, int fa) {
//	s[x] = sz[x];
//	for (int v : adj[x]) {
//		if (v == fa)	continue;
//		dfs(v, x);
//		s[x] += s[v];
//		max_sub[x] = max(max_sub[x], s[v]);
//	}
//	max_sub[x] = max(max_sub[x], sum - s[x]);
//}
//void dfs_ans(int x, int fa, int step) {
//	ans += (step * sz[x]);
//	for (int v : adj[x]) {
//		if (v == fa)	continue;
//		dfs_ans(v, x, step + 1);
//	}
//}
//int main()
//{
//	int n; cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		int w, u, v; cin >> w >> u >> v;
//		sz[i] = w;
//		if (v != 0)
//			adj[i].push_back(v), adj[v].push_back(i);
//		if (u != 0)
//			adj[i].push_back(u), adj[u].push_back(i);
//		sum += w;
//	}
//	dfs(1, 0);
//	int root = 1;
//	for (int i = 2; i <= n; i++) {
//		if (max_sub[root] > max_sub[i]) {
//			root = i;
//		}
//	}
//	dfs_ans(root, 0, 0);
//	cout << ans;
//	return 0;
//}