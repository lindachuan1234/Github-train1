#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int cnt[1000005];
bool zhi(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)	return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int l, r, k; cin >> l >> r >> k;
	for (int i = 1;; i++) {
		if (i * i > r)	break;
		cnt[i * i]++;
	}
	int flag = 1;
	for (int i = l; i <= r; i++) {
		if (zhi(i))	continue;
		int a = 0;
		int t = i;
		while (t) {
			a += t % 10;
			t /= 10;
		}
		if (cnt[a])	k--;
		if (k == 0) {
			cout << i;
			flag = 0;
			break;
		}
	}
	if (flag)	cout << -1;
	return 0;
}
//int main() {
//	int n; cin >> n;
//	string ret; cin >> ret;
//	int cnt = 1;
//	priority_queue<int, vector<int>, greater<int>>odd, even;
//	vector<int>flag(n + 1, 0), ans(1, 1);
//	flag[1] = 1;
//	for (int i = 0; i < ret.size(); i++) {
//		if (ret[i] == '0')	flag[i + 2] = flag[i + 1];
//		else   flag[i + 2] = 1 - flag[i + 1];
//		if (flag[i + 2] == 1)	cnt++;
//	}
//	for (int i = 2; i <= n; i++) {
//		if (i % 2 == 1)	odd.push(i);
//		else  even.push(i);
//	}int mm = 0;
//	if (n % 2 == 0)	mm = n / 2;
//	else  mm = n / 2 + 1;
//	if (cnt != mm) {
//		swap(odd, even);
//		ans[0] = 2;
//		even.push(1);
//		odd.pop();
//	}
//	int ttt = 1;
//	for (int i = 2; i <= n; i++) {
//		if (flag[i]) {
//			if (odd.empty()) {
//				ttt = 0;
//				break;
//			}
//			ans.push_back(odd.top());
//			odd.pop();
//		}
//		else
//		{
//			if (even.empty()) {
//				ttt = 0;
//				break;
//			}
//			ans.push_back(even.top());
//			even.pop();
//		}
//	}
//	if (ttt)	for (int i = 0; i < n; i++)	cout << ans[i] << ' ';
//	else  cout << -1;
//}
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int n; cin >> n;
//	string ret; cin >> ret;
//	vector<int>cnt(n + 1, 0), ans(1, 1);
//	cnt[1] = 1;
//	int flag = 1;
//	for (int i = 0; flag && i < ret.size(); i++)
//	{
//		int t = ans.size() - 1;
//		if (ret[i] == '0'){	
//			int m = 1, tt = 1;
//			while (ans[t] - 2 * m > 0) {
//				if (cnt[ans[t] - 2 * m] == 0) {
//					ans.push_back(ans[t] - 2 * m);
//					cnt[ans[t] - 2 * m]++;
//					tt = 0;
//					break;
//				}
//				m++;
//			}
//			m = 0;
//			if (tt) {
//				int m = 0;
//				while (1 | m++) {
//					if (ans[t] + 2 * m > n) {
//						flag = 0;
//						break;
//					}
//					if (cnt[ans[t] + 2 * m] == 0)
//					{
//						ans.push_back(ans[t] + 2 * m);
//						cnt[ans[t] + 2 * m]++;
//						break;
//					}
//				}
//			}
//		}
//		else {
//			int m = 1, tt = 1;
//			while (ans[t] - 1 * m > 0) {
//				if (cnt[ans[t] - 1 * m] == 0){
//					ans.push_back(ans[t] - 1 * m);
//					cnt[ans[t] - 1 * m]++;
//					tt = 0;
//					break;
//				}
//				m++;
//			}
//			m = 0;
//			if (tt) {
//				while (1 | m++) {
//					if (ans[t] + 1 * m > n) {
//						flag = 0;
//						break;
//					}
//					if (cnt[ans[t] + 1 * m] == 0)
//					{
//						ans.push_back(ans[t] + 1 * m);
//						cnt[ans[t] + 1 * m]++;
//						break;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)	if (cnt[i] == 0)	flag = 0;
//	if (flag)	for (int i = 0; i < n; i++)	cout << ans[i] << ' ';
//	else  cout << -1;
//	return 0;
//}
//int main()
//{
//	int n, m, k; cin >> n >> m >> k;
//	int q = m;
//	vector<int>a(n + 1, 0), b(n + 1, 0);
//	for (int i = 1; i <= n; i++)	cin >> a[i];
//	for (int i = 1; i < n; i++)	a.push_back(a[i]);
//	int l = 1, r = 1, ans = 0;
//	while (l <= r && r < a.size() - 1) {
//		if (abs(a[r] - a[r + 1]) > k) 	m--;
//		r++;
//		if (m < 0) {
//			ans = max(ans, r - l);
//			while (abs(a[l] - a[l + 1]) <= k)	l++;
//			l++; m++;
//		}
//	}
//	if (m >= 0) ans = max(ans, r - l + 1);
//	ans = min(n, ans);
//	cout << ans;
//	return 0;
//}