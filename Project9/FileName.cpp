#include<iostream>
#include<vector>
using namespace std;
int n, ans;
vector<int>col, row, line;
void dfs(int x) {
	if (x == n) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!col[i] && !row[x + i] && !line[x - i + 13]) {
			col[i] = row[x + i] = line[x - i + 13] = true;
			dfs(x + 1);
			col[i] = row[x + i] = line[x - i + 13] = false;
		}
	}
}
int main()
{
	cin >> n;
	col.assign(n + 1, 0); row.assign(100, 0); line.assign(100, 0);
	dfs(0);
	cout << ans;
	return 0;
}
//int path[9];
//bool flag[9];
//void dfs(int x) {
//	if (x == 8) {
//		for (int i = 0; i < 8; i++) {
//			cout << path[i] << ' ';
//		}cout << '\n';
//		return;
//	}
//	else {
//		for (int i = 1; i <= 8; i++) {
//			if (!flag[x]) {
//				path[x] = i;
//				flag[x] = true;
//				dfs(x + 1);
//				path[x] = 0;
//				flag[x] = false;
//			}
//		}
//	}
//}
//int main()
//{
//	dfs(0);
//	return 0;
//}
//#define int long long
//signed main() {
//    int n, b;
//    cin >> n >> b;
//    int pos = 0, ans = 0;
//    vector<int>a(n + 1, 0);
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//        if (a[i] == b) pos = i;
//    }
//    int sum = 0;
//    map<int, int>mp;    mp[0] = 1;
//    for (int i = 1; i < pos; i++) {
//        if (a[i] > b)   sum++;
//        else if (a[i] < b)  sum--;
//        mp[sum]++;
//    }
//    for (int i = pos; i <= n; i++) {
//        if (a[i] > b)   sum++;
//        else if (a[i] < b)  sum--;
//        ans += mp[sum];
//    }
//    cout << ans;
//    return 0;
//}
//int main()
//{
//	int L, m; cin >> L >> m;
//	vector<int>a(L + 2, 0);
//	int cnt = 0, ans = 0;
//	for (int i = 0; i < m; i++) {
//		int l, r; cin >> l >> r;
//		a[l]++; a[r + 1]--;
//	}
//	for (int i = 1; i <= L; i++) {
//		a[i] += a[i - 1];
//		if (a[i] > 0)	cnt++;
//	}if (a[0] > 0)	cnt++;
//	ans = L + 1 - cnt;
//	cout << ans;
//	return 0;
//}
//int main()
//{
//	int p1, p2, p3; cin >> p1 >> p2 >> p3;
//	string ret; cin >> ret;
//	string ans;
//	for (int i = 0; i < ret.size(); i++) {
//		if (ret[i] == '-') {
//			if (ret[i - 1] < ret[i + 1] && ret[i - 1] >= '0' && ret[i - 1] <= '9' && ret[i + 1] >= '0' && ret[i + 1] <= '9') {
//				if (p1 == 1 || p1 == 2) {
//					if (p3 == 1){
//						char cnt = 1;
//						while (ret[i - 1] + cnt != ret[i + 1]) {
//							for (int j = 0; j < p2; j++)	ans += ret[i - 1] + cnt;
//							cnt++;
//						}
//					}
//					else {
//						char cnt = ret[i + 1] - ret[i - 1] - 1;
//						while (ret[i - 1] + cnt != ret[i - 1]) {
//							for (int j = 0; j < p2; j++)	ans += ret[i - 1] + cnt;
//							cnt--;
//						}
//					}
//				}
//				else {
//					char cnt = 1;
//					while (ret[i - 1] + cnt != ret[i + 1]) {
//						for (int j = 0; j < p2; j++)	ans += '*';
//						cnt++;
//					}
//				}
//			}
//			else if (ret[i - 1] < ret[i + 1] && ret[i - 1] >= 'a' && ret[i - 1] <= 'z' && ret[i + 1] >= 'a' && ret[i + 1] <= 'z') {
//				if (p1 == 1) {
//					if (p3 == 1) {
//						char cnt = 1;
//						while (ret[i - 1] + cnt != ret[i + 1]) {
//							for (int j = 0; j < p2; j++)	ans += ret[i - 1] + cnt;
//							cnt++;
//						}
//					}
//					else {
//						char cnt = ret[i + 1] - ret[i - 1] - 1;
//						while (ret[i - 1] + cnt != ret[i - 1]) {
//							for (int j = 0; j < p2; j++)	ans += ret[i - 1] + cnt;
//							cnt--;
//						}
//					}
//				}
//				else if (p1 == 2) {
//					if (p3 == 1) {
//						char cnt = 1;
//						while (ret[i - 1] + cnt != ret[i + 1]) {
//							for (int j = 0; j < p2; j++)	ans += ret[i - 1] + cnt - 'a' + 'A';
//							cnt++;
//						}
//					}
//					else {
//						char cnt = ret[i + 1] - ret[i - 1] - 1;
//						while (ret[i - 1] + cnt != ret[i - 1]) {
//							for (int j = 0; j < p2; j++)	ans += ret[i - 1] + cnt - 'a' + 'A';
//							cnt--;
//						}
//					}
//				}
//				else {
//					char cnt = 1;
//					while (ret[i - 1] + cnt != ret[i + 1]) {
//						for (int j = 0; j < p2; j++)	ans += '*';
//						cnt++;
//					}
//				}
//			}
//			else   
//				ans += ret[i];
//			}
//		else
//			ans += ret[i];
//	}
//	cout << ans;
//	return 0;
//}
//int a, n, m;
//vector<int>d;
//bool check(int x) {
//	int cnt = 0, p = 0;
//	for (int i = 1; i <= n + 1; i++) {
//		if (d[i] - p < x)	cnt++;
//		else p = d[i];
//	}
//	if (cnt <= m)	return true;
//	else return false;
//}
//int main()
//{
//	cin >> a >> n >> m;
//	d.assign(n + 2, 0); d[n + 1] = a;
//	for (int i = 1; i <= n; i++) cin >> d[i];
//	int l = 1, r = a;
//	while (l < r) {
//		int mid = (l + r + 1) / 2;
//		if (check(mid))	l = mid;
//		else  r = mid - 1;
//	}
//	cout << l;
//	return 0;
//}
//vector<int>a, tr, lazy;
//int flag;
//void pushup(int p) {
//	tr[p] = min(tr[p * 2], tr[p * 2 + 1]);
//}
//void pushdown(int p, int l, int r) {
//	if (lazy[p] == 0)	return;
//	tr[p * 2] -= lazy[p];
//	lazy[p * 2] += lazy[p];
//	tr[p * 2 + 1] -= lazy[p];
//	lazy[p * 2 + 1] += lazy[p];
//	lazy[p] = 0;
//}
//void build(int p, int l, int r) {
//	if (l == r) {
//		tr[p] = a[l];
//		return;
//	}
//	int mid = (l + r) / 2;
//	build(p * 2, l, mid);
//	build(p * 2 + 1, mid + 1, r);
//	pushup(p);
//}
//void sub(int p, int l, int r, int ql, int qr, int k) {
//	if (l > qr || r < ql)	return;
//	if (l >= ql && r <= qr) {
//		tr[p] -= k;
//		lazy[p] += k;
//		if (tr[p] < 0)	flag = 0;
//		return;
//	}
//	pushdown(p, l, r);
//	int mid = (l + r) / 2;
//	sub(p * 2, l, mid, ql, qr, k);
//	sub(p * 2 + 1, mid + 1, r, ql, qr, k);
//	pushup(p);
//}
//int main()
//{
//	int n, m; cin >> n >> m; flag = 1;
//	a.assign(n + 1, 0); tr.assign(4 * (n + 1), 0); lazy.assign(4 * n + 4, 0);
//	for (int i = 1; i <= n; i++)	cin >> a[i];
//	build(1, 1, n);
//	int tt = 1e9;
//	for (int i = 0; i < m; i++)
//	{
//		int d, s, t; cin >> d >> s >> t;
//		sub(1, 1, n, s, t, d);
//		if (!flag)	tt = min(tt, i + 1);
//	}
//	if (flag)	cout << 0;
//	else
//	{
//		cout << -1 << '\n';
//		cout << tt;
//	}
//	return 0;
//}
//int main()
//{
//	string ret;
//	int flag = 1;
//	while (flag) {
//		string res; cin >> res;
//		for (int i = 0; i < res.size(); i++) {
//			if (res[i] != 'E')
//				ret += res[i];
//			else {
//				flag = 0;
//				break;
//			}
//		}
//	}
//	int a = 0, b = 0;
//	for (int i = 0; i < ret.size(); i++) {
//		if (ret[i] == 'W')	a++;
//		else if (ret[i] == 'L')	b++;
//		if (a >= 11 && a - b >= 2)	cout << a << ':' << b << '\n', a = 0, b = 0;
//		else if (b >= 11 && b - a >= 2)	cout << a << ':' << b << '\n', a = 0, b = 0;
//	}cout << a << ':' << b << '\n' << '\n';
//	a = 0; b = 0;
//	for (int i = 0; i < ret.size(); i++) {
//		if (ret[i] == 'W')	a++;
//		else if (ret[i] == 'L')	b++;
//		if (a >= 21 && a - b >= 2)	cout << a << ':' << b << '\n', a = 0, b = 0;
//		else if (b >= 21 && b - a >= 2)	cout << a << ':' << b << '\n', a = 0, b = 0;
//	}cout << a << ':' << b << '\n';
//	return 0;
//}
//int main()
//{
//	int n, m; cin >> n >> m;
//	int ans = 0;
//	vector<int>a(n + 1, 0);
//	for (int i = 1; i <= n; i++)	cin >> a[i];
//	for (int i = 0; i < m; i++) {
//		int x, y; cin >> x >> y;
//		if (y - a[x - 1] > 0 && x - 1 > 0 || x + 1 <= n && y - a[x + 1] > 0) {
//			if (x - 1 <= 0)	a[x + 1] = y;
//			else if (x + 1 > n)	a[x - 1] = y;
//			else if (y - a[x - 1] > y - a[x + 1])	a[x - 1] = y;
//			else  a[x + 1] = y;
//		}
//	}
//	for (int i = 1; i <= n; i++)	ans += a[i];
//	cout << ans;
//	return 0;
//}
//int main()
//{
//	int n, q; cin >> n >> q;
//	vector<double>x(n + 1, 0), y(n + 1, 0);
//	vector<double>k(n + 1, 0), b(n + 1, 0);
//	for (int i = 1; i <= n; i++)
//		cin >> k[i] >> b[i];
//	for (int i = 1; i < n; i++) {
//		double m = (b[i + 1] - b[i]) / (k[i] - k[i + 1]);
//		if (k[i + 1] == k[i])	x[i] = -1e10, y[i] = -1e10;
//		else
//		{
//			x[i] = m; y[i] = k[i] * m + b[i];
//		}
//	}
//	for (int i = 0; i < q; i++) {
//		int l, r; cin >> l >> r;
//		int flag = 1;
//		for (int j = l; j < r - 1; j++)
//			if (x[j] == -1e10 || x[j + 1] == -1e10 || x[j] != x[j + 1] || y[j] != y[j + 1]) {
//				flag = 0;
//				break;
//			}
//		if (flag)	cout << "Yes" << '\n';
//		else  cout << "No" << '\n';
//	}
//	return 0;
//}
//#define int long long
//signed main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int t; cin >> t;
//	for (int i = 0; i < t; i++) {
//		int a, b, c, x, y, z; cin >> a >> b >> c >> x >> y >> z;
//		if (a == b && b == c) {
//			if (x <= y && x <= z)	cout << 1 << '\n';
//			else if (y < x && y <= z)	cout << 2 << '\n';
//			else cout << 3 << '\n';
//		}
//		else if (x == 1 && y == 1 && z == 1) {
//			if (a >= b && a >= c)	cout << 1 << '\n';
//			else if (b > a && b >= c)	cout << 2 << '\n';
//			else  cout << 3 << '\n';
//		}
//		else{
//			if (a * y >= b * x && c * x <= a * z)	cout << 1 << '\n';
//			else if (b * x > a * y && c * y <= b * z)	cout << 2 << '\n';
//			else  cout << 3 << '\n';
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n, q; cin >> n >> q;
//	vector<int>a(n + 1, 0);
//	for (int i = 1; i <= n; i++)	cin >> a[i];
//	for (int i = 0; i < q; i++) {
//		int op, l, r, k;
//		cin >> op >> k >> l >> r;
//		int ans = 0;
//		if (op == 0) {
//			ans = a[l] & k;
//			for (int j = l + 1; j <= r; j++) {
//				ans ^= (a[j] & k);
//			}
//			cout << ans << '\n';
//		}
//		else{
//			ans = a[l] | k;
//			for (int j = l + 1; j <= r; j++) {
//				ans ^= (a[j] | k);
//			}
//			cout << ans << '\n';
//		}
//	}
//	return 0;
//}
//vector<int>a, tr, lazy1, lazy2; // Óë   »ò
//void pushup(int p) {
//	tr[p] = tr[p * 2] + tr[p * 2 + 1];
//}
//void build(int p, int l, int r) {
//	if (l == r){
//		tr[p] = a[l];
//		return;
//	}
//	int mid = (l + r) / 2;
//	build(p * 2, l, mid);
//	build(p * 2 + 1, mid + 1, r);
//	pushup(p);
//}
//void query_and(int p, int l, int r, int ql, int qr, int k) {
//	if (l > qr || r < ql)	return;
//	if (l >= ql && r <= qr) {
//		
//	}
//}
//int main() {
//	int n, q; cin >> n >> q;
//	a.assign(n + 1, 0), tr.assign(4 * (n + 1), 0), lazy1.assign(4 * (n + 1), 1), lazy2.assign(4 * (n + 1), 0);
//	for (int i = 1; i <= n; i++)	cin >> a[i];
//	build(1, 1, n);
//	for (int i = 0; i < q; i++)
//	{
//		int op, k, l, r; cin >> op >> k >> l >> r;
//		if (op == 1) {
//			query_and(1, 1, n, l, r, k);
//		}
//	}
//	return 0;
//}