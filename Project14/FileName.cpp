#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<string>mat;
vector<vector<int>>cnt;
int n, ans = 1e9;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
struct node {
	int x, y, d;
};
int main()
{
	cin >> n; 
	if (n == 1) {
		cout << 0;
	}
	else {
		cnt.assign(n + 1, vector<int>(n + 1));
		mat.assign(n + 1, "");
		for (int i = 1; i <= n; i++) {
			cin >> mat[i];
			mat[i] = ' ' + mat[i];
			for (int j = 1; j <= n; j++)	mat[i][j] -= '0';
		}
		deque<node>q; q.push_back({ 1,1,0 });
		while (!q.empty()) {
			int sx = q.front().x;
			int sy = q.front().y;
			int d = q.front().d;
			int di = 0;
			q.pop_front();
			for (int i = 0; i < 4; i++) {
				int nx = sx + dx[i];
				int ny = sy + dy[i];
				if (nx < 1 || nx > n || ny < 1 || ny > n)	continue;
				if (!cnt[nx][ny]) {
					cnt[nx][ny] = 1;
					if (mat[nx][ny] != mat[sx][sy])	q.push_back({ nx,ny,d + 1 }), di = d + 1;
					else  q.push_front({ nx,ny,d }), di = d;
				}
				if (nx == n && ny == n) {
					cout << di;
					exit(0);
				}
			}
		}
	}
	return 0;
}
//void dfs(int x, int y, int step) {
//	if (x == n && y == n) {
//		ans = min(ans, step);
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx < 1 || nx > n || ny < 1 || ny > n)	continue;
//		if (!cnt[nx][ny]) {
//			cnt[nx][ny] = 1;
//			if (mat[x][y] == 1 - mat[nx][ny])	dfs(nx, ny, step + 1);
//			else  dfs(nx, ny, step);
//			cnt[nx][ny] = 0;
//		}
//	}
//}
//int n, m, flag;
//vector<string>mat;
//vector<vector<int>>cnt;
//int dx[4] = { -1,0,0,1 };
//int dy[4] = { 0,1,-1,0 };
//void dfs(int x, int y) {
//	if (flag)	return;
//	if (x < 1 || x > n || y < 1 || y > m)	return;
//	if (mat[x][y] == 'x')	return;
//	if (mat[x][y] == 't') {
//		flag = 1;
//		cout << "YES" << '\n';
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		int nx = dx[i] + x;
//		int ny = dy[i] + y;
//		if (nx < 1 || nx > n || ny < 1 || ny > m)	continue;
//		if (mat[nx][ny] == 'x')	continue;
//		if (!cnt[nx][ny]) {
//			cnt[nx][ny] = 1;
//			dfs(nx, ny);
//		}
//	}
//}
//int main()
//{
//	int t; cin >> t;
//	while (t--) {
//		cin >> n >> m;
//		mat.assign(n + 1, "");
//		cnt.assign(n + 1, vector<int>(m + 1, 0));
//		int sx = 0, sy = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> mat[i], mat[i] = ' ' + mat[i];
//			for (int j = 1; j <= m; j++) {
//				if (mat[i][j] == 's')	sx = i, sy = j;
//			}
//		}
//		flag = 0;
//		cnt[sx][sy] = 1;
//		dfs(sx, sy);
//		if (!flag)	cout << "NO" << '\n';
//	}
//	return 0;
//}
//#define int long long
//int a, m, n;
//vector<int>s;
//bool check(int x) {
//	int cnt = 0;
//	int flag = s[0];
//	for (int i = 1; i <= n + 1; i++) {
//		if (s[i] - flag < x) {
//			cnt++;
//		}
//		else   flag = s[i];
//	}
//	if (cnt > m)	return false;
//	else return true;
//}
//signed main()
//{
//	cin >> a >> n >> m;
//	s.assign(n + 2, 0); s[n + 1] = a;
//	for (int i = 1; i <= n; i++)	cin >> s[i];
//	if (n <= m) {
//		cout << a;
//	}
//	else {
//		int l = 1, r = a;
//		while (l < r) {
//			int mid = (l + r + 1) / 2;
//			if (check(mid))	l = mid;
//			else  r = mid - 1;
//		}
//		cout << l;
//	}
//	return 0;
//}
//int main()
//{
//	int n, m, sum = 0; cin >> n >> m;
//	vector<int>a(n + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	vector<vector<int>>dp(n + 1, vector<int>(sum + 1, -1e9));
//	dp[0][0] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = sum - a[i]; j >= 0; j--) {
//			dp[i][j] = max(dp[i - 1][j], dp[i - 1][abs(j - a[i])] + a[i]);
//			dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]] + a[i]);
//		}
//	}
//	int ans = -1;
//	for (int i = 0; i <= m; i++)	ans = max(ans, dp[n][i]);
//	cout << ans;
//	return 0;
//}
//int main()
//{
//	int t, n; cin >> t >> n;
//	vector<int>a(n + 1, 0), v(n + 1, 0), dp(t + 1, 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i] >> v[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = t; j >= a[i]; j--) {
//			dp[j] = max(dp[j - a[i]] + v[i], dp[j]);
//		}
//	}
//	cout << dp[t];
//	return 0;
//}
//int main()
//{
//	int n; cin >> n;
//	int a;
//	for (int i = 1; i <= n; i++)	cin >> a;
//	cout << "//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+//+!";
//	return 0;
//}