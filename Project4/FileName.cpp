#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<int>a(n + 1, 0), res;
	for (int i = 1; i <= n; i++) cin >> a[i];
	res = a;
	int cnt[32] = { 0 }, ans = 0;
	for (int i = 29; i >= 0; i--) {
		int flag = 0;
		vector<int>tmp;
		for (int j : res) {
			if ((j >> i) % 2 == 1) {
				tmp.push_back(j);
				flag = 1;
			}
		}
		if (tmp.size() >= 2) {
			res = tmp;
		}
	}
	cout << (res[0] & res[1]);
	return 0;
}
//#define int long long
//signed main()
//{
//	int t; cin >> t;
//	for (int i = 0; i < t; i++) {
//		int n; cin >> n;
//		vector<int>a(n + 1, 0);
//		for (int j = 1; j <= n; j++) {
//			cin >> a[j];
//		}sort(a.begin(), a.end());
//		int cnt = 1;
//		int ans = 0;
//		for (int j = 1; j <= n; j++) {
//			if (a[j] == cnt);
//			else if (a[j] > cnt)	ans += (a[j] - cnt);
//			else {
//				ans += a[j];
//				continue;
//			}
//			cnt++;
//		}ans++;
//		cout << ans << endl;
//	}
//	return 0;
//}
//int dp[405][405][3];
//int main()
//	int x, y, z; cin >> x >> y >> z;
//	for (int i = 0; i <= x; i++) {
//		for (int j = 0; j <= z; j++) {
//			for (int k = 0; k < 3; k++) {
//				dp[i][j][k] = -1e9;
//			}
//		}
//	}
//	dp[0][0][1] = 0;
//	for (int i = 0; i <= x; i++) {
//		for (int j = 0; j <= z; j++) {
//			for (int t = 0; t < 3; t++) {
//				if (dp[i][j][t] < 0)	continue;
//				if (i < x)
//				{
//					int m = max(0, t - 1);
//					dp[i + 1][j][m] = max(dp[i + 1][j][m], dp[i][j][t] + t);
//				}
//				if (j < z)
//				{
//					int n = min(2, t + 1);
//					dp[i][j + 1][n] = max(dp[i][j + 1][n], dp[i][j][t] + t);
//				}
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < 3; i++) {
//		ans = max(ans, dp[x][z][i]);
//	}
//	if (z == 0)	cout << ans + y;
//	else cout << ans + 2 * y;
//	return 0;
//}
//const long long max_money = 70;
//#define int long long
//signed main()
//{
//	int n; cin >> n;
//	vector<int>x(6, 0), y(6, 0);
//	vector<int>pre(max_money + 1, -1e9), cur(max_money + 1, -1e9);
//	pre[22] = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j <= 5; j++)	cin >> x[j];
//		for (int j = 1; j <= 5; j++)	cin >> y[j];
//		for (int j = 0; j <= max_money; j++)	cur[j] = -1e9;
//		for (int m = max_money; m >= 0; m--) {
//			if (pre[m] == -1e9)	continue;
//			int start = min(m + 2, max_money);
//			vector<int>dp(start + 1, 0); dp[0] = 0;
//			for (int j = 1; j <= 5; j++) {
//				for (int t = start; t >= y[j]; t--) {
//					dp[t] = max(dp[t], dp[t - y[j]] + x[j]);
//				}
//			}
//			for (int t = start; t >= 0; t--) {
//				if (dp[t] == 0)	continue;
//				int a = (start - t) / 10;
//				int ns = min(max_money, a + (start - t));
//				cur[ns] = max(cur[ns], pre[m] + dp[t]);
//			}
//		}
//		pre.swap(cur);
//	}int ans = 0;
//	for (int i = 0; i <= max_money; i++) {
//		ans = max(ans, pre[i]);
//	}cout << ans;
//	return 0;
//}