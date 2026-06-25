#include<iostream>
#include<vector>
using namespace std;
signed main()
{
	string ret; cin >> ret;
	int cnt = 0;
	vector<string>ans(4, "");
	int flag = 1;
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i] >= '0' && ret[i] <= '9') {
			int flag1 = 0, cnnt = 0;
			if (ret[i] == '0')	flag1 = 1;
			int first = i;
			while (ret[i] <= '9' && ret[i] >= '0') {
				if (ret[first] == '0' && i == first && i + 1 < ret.size() && ret[i + 1] >= '0' && ret[i + 1] <= '9') {
					first = i + 1; i++; flag = 0; continue;
				}
				ans[cnt] += ret[i];
				i++;
				cnnt++;
				if (cnnt > 1 && flag1)	flag = 0;
			}
			i--;
			if (ans[cnt].size() > 3 || ans[cnt].size() == 3 && ans[cnt] > "255")	ans[cnt] = "255", flag = 0;
			cnt++;
		}
		else if (ret[i] != '.')  flag = 0;
		else {
			if (i + 1 <= ret.size() - 1 && ret[i + 1] == '.')	flag = 0;
			if (i == 0 || i == ret.size() - 1)	flag = 0;
		}
	}
	if (!flag) {
		cout << "NO" << '\n';
		for (int i = 0; i < 4; i++) {
			if (i != 3)
				cout << ans[i] << '.';
			else
				cout << ans[i];
		}
	}
	else  cout << "YES";
	return 0;
}
//int main()
//{
//	int n, m, ans = 0; cin >> n >> m;
//	vector<int>v(m + 1, 0), w(m + 1, 0), dp(n + 1, 0);
//	for (int i = 1; i <= m; i++) {
//		cin >> v[i] >> w[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		for (int j = n; j >= v[i]; j--) {
//			dp[j] = max(dp[j], dp[j - v[i]] + v[i] * w[i]);
//		}
//	}
//	cout << dp[n];
//	return 0;
//}
//int main()
//{
//	string ret, res;
//	while (cin >> ret >> res) {
//		int n = ret.size(); int m = res.size();
//		ret = ' ' + ret;
//		res = ' ' + res;
//		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++)
//				if (ret[i] == res[j]) {
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				}
//				else {
//					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//				}
//		}
//		cout << dp[n][m] << '\n';
//	}
//	return 0;
//}