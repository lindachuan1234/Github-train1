#include<iostream>
#include<vector>
using namespace std;

//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int t; cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		int n; cin >> n;
//		int ans = 0;
//		for (int x = 1; x <= n / 2 + 1; x++)
//		{
//			for (int y = x; y <= n / 2 + 1 && x * y <= n; y++)
//			{
//				if (y % x == 0 && n % (x * x) == 0)	ans++;
//			}
//		}
//		cout << ans << '\n';
//	}
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//#define int long long
//signed main()
//{
//	int n; cin >> n;
//	vector<int>cnt2(n + 1, 0);
//	string ret;
//	for (int i = 0; i < n; i++) {
//		char u; cin >> u;
//		ret.push_back(u);
//	}
//	for (int i = 0; i < ret.size(); i++) {
//		if (i >= 1)	cnt2[i] += cnt2[i - 1];
//		if (ret[i] == '+')	cnt2[i]++;
//	}
//	if (ret.size() > 200 || ret[n - 1] != '!')	cout << "NO" << '\n';
//	else
//	{
//		int cnt1 = 0, ans = 0;
//		for (int i = 0; i < ret.size(); i++)
//		{
//			if (ret[i] == '/')	cnt1++;
//			else if (ret[i] == '+') {
//				for (int j = i + 1; j < ret.size(); j++) {
//					if (ret[j] == '/' || j == n - 1) {
//						ans += (cnt1 * (cnt1 - 1)) / 2 * cnt2[j];
//						i = j - 1;
//						if (i < 0)	i = 0;
//						break;
//					}
//				}
//			}
//		}
//		if (ans >= 66)	cout << "YES" << '\n';
//		else	cout << "NO" << '\n';
//	}
//	return 0;
//}