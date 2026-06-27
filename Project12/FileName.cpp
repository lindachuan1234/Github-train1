#include<vector>
#include<iostream>
using namespace std;
const int max_num = 200005;
vector<int>adj[max_num], dp;
int dfs(int x) {
	for (int v : adj[x]) {
		dp[x] = max(dp[v] + 1, dp[x]);
	}
}
int main()
{
	int n, m; cin >> n >> m;
	dp.assign(n + 1, 0);
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dp[i]) {
			dfs(i);
		}
	}
	return 0;
}