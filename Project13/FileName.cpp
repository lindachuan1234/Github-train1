#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main() {
	int n, m; cin >> n >> m;
	int max_b = 0;
	vector<int>a(n, 0), b(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		max_b = max(max_b, b[i]);
	}
	int r = (max_b + 1) * m;
	int l = 1;
	int mid = 0;
	while (l < r) {
		mid = (l + r) / 2;
		int aa = 0;
		for (int i = 0; i < n; i++) {
			aa += ((mid / (a[i] + b[i]))) * a[i];
			if (mid % (a[i] + b[i]) > 0) {
				aa += min(a[i], mid % (a[i] + b[i]));
			}
		}
		if (aa >= m)	r = mid;
		else if (aa < m)	l = mid + 1;
	}
	cout << l << '\n';
	return 0;
}
//#include<iostream>
//#include<vector>
//using namespace std;
//#define int long long
//signed main() {
//	int t; cin >> t;
//	while (t--) {
//		int n, k; cin >> n >> k;
//		vector<int>a(n + 1, 0);
//		int ans = 0;
//		for (int i = 1; i <= n; i++)	cin >> a[i];
//		for (int i = 1; i <= n; i++) {
//			a[i] += a[i - 1];
//		}
//		for (int i = 0; i <= k; i++) {
//			ans = max(ans, a[i] + a[n] - a[n - k + i]);
//		}
//		cout << ans << '\n';
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main() {
//	int n; cin >> n; float p = 0.000000, ans = 0.000000;
//	float m = 1.000000, mm = 20.000000, hun = 100.000000;
//	for (int i = 1; i <= n; i++) {
//		cin >> p;
//		float t = (float)hun / (float)p - (float)m;
//		ans += (float)t * (float)mm;
//	}
//	printf("%llf", (float)ans);
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	int n; cin >> n;
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		int a; cin >> a;
//		if (a == 1)	ans++;
//	}cout << ans;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	int n; cin >> n;
//	vector<int>cnt(1005, 0);
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		int a; cin >> a;
//		if (!cnt[a]) {
//			ans += a * 2;
//			cnt[a] = 1;
//		}
//	}
//	cout << ans;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//int main() {
//	int n, k; cin >> n >> k;
//	string ret; cin >> ret;
//	k %= 26;
//	for (int i = n - 1; i >= 0; i--) {
//		if (ret[i] - k >= 'a' && ret[i] - k <= 'z') {
//			ret[i] -= k;
//		}
//		else {
//			ret[i] -= k;
//			ret[i] += 26;
//		}
//	}
//	for (int i = n - 1; i >= 0; i--)	cout << ret[i];
//	return 0;
//}