#include<iostream>
#include<vector>
using namespace std;
#define int long long
signed main()
{
	int n; cin >> n;
	int m = -1e9;
	vector<int>a(n + 1, 0);
	for (int i = 1; i <= n; i++)	cin >> a[i], m = max(m, a[i]);
	int t = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0)	t += a[i];
		else{
			if (t + a[i] > 0)	t += a[i];
			else  t = 0;
		}
		ans = max(ans, t);
	}
	if (m < 0)	cout << m;
	else	cout << ans;
	return 0;
}
//vector<vector<int>>a, dp;
//int n, m, ans;
//int dx[4] = { -1,0,0,1 };
//int dy[4] = { 0,1,-1,0 };
//int dfs(int x, int y) {
//	if (x < 1 || x > n || y < 1 || y > m)	return 0;
//	if (dp[x][y])	return dp[x][y];
//	dp[x][y] = 1;
//	for (int i = 0; i < 4; i++) {
//		int nx = dx[i] + x;
//		int ny = dy[i] + y;
//		if (nx < 1 || nx > n || ny < 1 || ny > m)	continue;
//		if (a[nx][ny] < a[x][y]) {
//			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
//		}
//	}
//	return dp[x][y];
//}
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	cin >> n >> m;
//	a.assign(n + 1, vector<int>(m + 1, 0));
//	dp.assign(n + 1, vector<int>(m + 1, 0));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			ans = max(ans, dfs(i, j));
//		}
//	}cout << ans;
//	return 0;
//}
//int main()
//{
//	int n, ans = 0; cin >> n;
//	vector<int>t(n + 1, 0), dp1(n + 1, 1), dp2(n + 1, 1);
//	for (int i = 1; i <= n; i++)	cin >> t[i];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < i; j++) {
//			if (t[i] > t[j])	dp1[i] = max(dp1[i], dp1[j] + 1);
//		}
//	}
//	for (int i = n; i >= 1; i--) {
//		for (int j = n; j > i; j--) {
//			if (t[i] > t[j])	dp2[i] = max(dp2[i], dp2[j] + 1);
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		ans = max(ans, dp1[i] + dp2[i] - 1);
//	}
//	cout << n - ans;
//	return 0;
//}
//int visited[105][105][105];
//struct node {
//	int x, y, z, cnt;
//};
//int dx[6] = { 1,-1,0,0,0,0 };
//int dy[6] = { 0,0,1,-1,0,0 };
//int dz[6] = { 0,0,0,0,1,-1 };
//int main()
//{
//	int n; cin >> n;
//	vector<vector<string>>a(n + 1, vector<string>(n + 1, " "));
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//		{
//			string ret; cin >> ret;
//			a[i][j] += ret;
//		}
//	queue<node>q; q.push({ 1,1,1,1 });
//	visited[1][1][1] = 1;
//	while (!q.empty()) {
//		int sx = q.front().x;
//		int sy = q.front().y;
//		int sz = q.front().z;
//		int nc = q.front().cnt;
//		q.pop();
//		for (int i = 0; i < 6; i++) {
//			int nx = sx + dx[i];
//			int ny = sy + dy[i];
//			int nz = sz + dz[i];
//			if (nx <= 0 || nx > n || ny <= 0 || ny > n || nz <= 0 || nz > n)	continue;
//			if (!visited[nx][ny][nz]) {
//				if (nx <= 0 || nx > n || ny <= 0 || ny > n || nz <= 0 || nz > n)	continue;
//				if (a[nx][ny][nz] == '*')	continue;
//				visited[nx][ny][nz] = 1;
//				if (nx == n && ny == n && nz == n) {
//					if (a[n][n][n] == '*') {
//						cout << -1;
//						exit(0);
//					}
//					else {
//						cout << nc + 1;
//						exit(0);
//					}
//				}
//				q.push({ nx,ny,nz,nc + 1 });
//			}
//		}
//	}
//	cout << -1;
//	return 0;
//}
//struct node {
//	int x, y, key, dist;
//};
//int h, w, cnt;
//vector<string>ret;
//vector<vector<vector<bool>>>visited;
//int dx[4] = { -1,0,0,1 };
//int dy[4] = { 0,1,-1,0 };
//queue<node>q;
//void bfs(int x, int y) {
//	visited[x][y][0] = 1;
//	while (!q.empty()) {
//		int sx = q.front().x; 
//		int sy = q.front().y;
//		int key = q.front().key;
//		int dist = q.front().dist;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = sx + dx[i];
//			int ny = sy + dy[i];
//			int nk = key;
//			if (nx < 0 || nx >= h || ny < 0 || ny >= w || ret[nx][ny] == 'W' || ret[nx][ny] == 'D' && !nk)	continue;
//			if (!visited[nx][ny][nk]) {
//				if (ret[nx][ny] == 'S' || ret[nx][ny] == 'E' || ret[nx][ny] == '.' || ret[nx][ny] == 'K' || ret[nx][ny] == 'D' && nk) {
//					if (ret[nx][ny] == 'K')	nk = 1;
//					if (ret[nx][ny] == 'E') {
//						cout << dist + 1;
//						exit(0);
//					}
//					q.push({ nx,ny,nk,dist + 1 });
//					visited[nx][ny][nk] = 1;
//				}
//			}
//		}
//	}
//	cout << -1;
//}
//int main()
//{
//	cin >> h >> w;
//	visited.assign(h, vector<vector<bool>>(w, vector<bool>(2, 0)));
//	ret.assign(h, "");
//	for (int i = 0; i < h; i++)
//		cin >> ret[i];
//	int s1 = 0, s2 = 0;
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (ret[i][j] == 'S') {
//				s1 = i; s2 = j;
//			}
//		}
//	}
//	q.push({ s1,s2,0,0 });
//	bfs(s1, s2);
//	return 0;
//}
//const int n = 9;
//vector<vector<int>>mat(n + 1, vector<int>(n + 1, 0));
//vector<vector<int>>col(n + 1, vector<int>(n + 1, 0)), row(n + 1, vector<int>(n + 1, 0));
//vector<vector<int>>c(n + 1, vector<int>(n + 1, 0)), block(n + 1, vector<int>(n + 1, 0));
//int getblock(int x, int y) {
//	return ((y - 1) / 3 + 1) + ((x - 1) / 3) * 3;
//}
//void c_out() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			cout << mat[i][j] << ' ';
//		cout << '\n';
//	}
//	exit(0);
//}
//void dfs(int x, int y) {
//	if (x > n) {
//		c_out();
//		return;
//	}
//	int ny = y + 1;
//	int nx = x;
//	if (ny > n) {
//		ny = 1; nx++;
//	}
//	if (c[x][y]) {
//		dfs(nx, ny);
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!row[x][i] && !col[y][i] && !block[getblock(x, y)][i]) {
//			row[x][i] = 1;
//			col[y][i] = 1;
//			mat[x][y] = i;
//			block[getblock(x, y)][i] = 1;
//			dfs(nx, ny);
//			row[x][i] = 0;
//			col[y][i] = 0;
//			mat[x][y] = 0;
//			block[getblock(x, y)][i] = 0;
//		}
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			cin >> mat[i][j];
//			if (mat[i][j] != 0) {
//				row[i][mat[i][j]] = 1;
//				col[j][mat[i][j]] = 1;
//				c[i][j] = 1;
//				block[getblock(i, j)][mat[i][j]] = 1;
//			}
//		}
//	}
//	dfs(1, 1);
//	return 0;
//}
//int n, m, ans;
//int dx[4] = { 1,1,2,2 };
//int dy[4] = { 2,-2,1,-1 };
//vector<vector<bool>>cnt;
//void dfs(int x, int y) {
//	if (x == n && y == m) {
//		ans++;
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		int nx = dx[i] + x;
//		int ny = dy[i] + y;
//		if (nx < 1 || nx > n || ny < 1 || ny > m)	continue;
//		if (!cnt[nx][ny]) {
//			cnt[nx][ny] = 1;
//			dfs(nx, ny);
//			cnt[nx][ny] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	cnt.assign(n + 1, vector<bool>(m + 1, 0));
//	cnt[1][1] = 1;
//	dfs(1, 1);
//	cout << ans;
//	return 0;
//}