#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int mod = 100003;
int main()
{
	int n, k; cin >> n >> k;
	vector<int>dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i >= j)
				dp[i] += dp[i - j] % mod;
		}
	}cout << dp[n] % mod;
	return 0;
}
//int main()
//{
//	int n, k; cin >> n >> k;
//	vector<int>s(n + 1, 0);
//	for (int i = 0; i < k; i++) {
//		int a, b; cin >> a >> b;
//		s[a]++;
//		if (b + 1 <= n)
//			s[b + 1]--;
//	}
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		s[i] = s[i - 1] + s[i];
//	}
//	sort(s.begin() + 1, s.end());
//	cout << s[n / 2 + 1];
//	return 0;
//}
//const int mod = 998244353;
//// 00 01 11 10
//int dp[2][5][5050];
//int main()
//{
//	int n, k; cin >> n >> k;
//	string ret;	cin >> ret;
//	for (int i = 0; i < n - 2; i++) {
//		string res;
//		int g = ret[i] - '0';
//		for (int j = i + 1; j <= i + 2; j++) {
//			res.push_back(ret[j]);
//		}
//		if (res == "00")	dp[g][0][i] = 1;
//		else if (res == "01")	dp[g][1][i] = 1;
//		else if (res == "11")	dp[g][2][i] = 1;
//		else   dp[g][3][i] = 1;
//	}
//	for (int i = 0; i < n - 2; i++) {
//		for (int j = 0; j < min(i, k); j++) {
//			dp[1][0][i] = (dp[1][1][i] + dp[1][3][i] + dp[0][0][i]) % mod;
//			dp[1][1][i] = (dp[1][0][i] + dp[1][2][i] + dp[0][1][i]) % mod;
//			dp[1][2][i] = (dp[1][1][i] + dp[1][3][i] + dp[0][2][i]) % mod;
//			dp[1][3][i] = (dp[1][2][i] + dp[1][0][i] + dp[0][3][i]) % mod;
//			dp[0][0][i] = (dp[0][1][i] + dp[0][3][i] + dp[1][0][i]) % mod;
//			dp[0][1][i] = (dp[0][0][i] + dp[0][2][i] + dp[1][1][i]) % mod;
//			dp[0][2][i] = (dp[0][1][i] + dp[0][3][i] + dp[1][2][i]) % mod;
//			dp[0][3][i] = (dp[0][2][i] + dp[0][0][i] + dp[1][3][i]) % mod;
//		}
//	}
//	return 0;
//}
//struct a {
//	int sum;
//	int p;
//	int s;
//};
//bool cmp(const a& x, const a& y) {
//	return x.sum < y.sum;
//}
//int main() {
//	int n, b; cin >> n >> b;
//	int record = b;
//	vector<a>m(n + 1);
//	for (int i = 1; i <= n; i++) {
//		cin >> m[i].p >> m[i].s;
//		m[i].sum = m[i].s + m[i].p;
//	}sort(m.begin() + 1, m.end(), cmp);
//	int ans = 0, cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (i == j)	b -= m[j].p / 2 + m[i].s, ans++;
//			else	b -= m[j].sum, ans++;
//			if (b < 0) {
//				ans--; break;
//			}
//			else if (b == 0)	break;
//		}
//		cnt = max(cnt, ans);
//		b = record;
//		ans = 0;
//	}cout << cnt;
//	return 0;
//}