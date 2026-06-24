#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int n; cin >> n;
//	vector<int>ans(n);
//	for (int i = 0; i < n; i++) {
//		string ret; cin >> ret;
//		for (int j = 0; j < n; j++) {
//			if (ret[j] == '#')	ans[j] = 1;
//		}
//	}int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		if (ans[i])	cnt++;
//	}cout << cnt;
//	return 0;
//}
//const int max_num = 404;
//vector<pair<int, int>>adj[max_num];
//int dist[max_num];
//int main()
//{
//	int n, m; cin >> n >> m;
//	for (int i = 1; i <= n; i++)	dist[i] = 1e9;
//	for (int i = 0; i < m; i++) {
//		int a, b, c; cin >> a >> b >> c;
//		adj[a].push_back({ b,c });
//		adj[b].push_back({ a,c });
//	}
//	queue<int>q;
//	q.push(1); dist[1] = 0;
//	while (!q.empty()) {
//		int t = q.front();
//		q.pop();
//		for (auto& v : adj[t]) {
//			dist[v.first] = min(dist[v.first], v.second);
//		}
//	}
//	return 0;
//}
//const int max_num = 100005;
//vector<int>adj[max_num];
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int n, q; cin >> n >> q;
//	for (int i = 0; i < q; i++) {
//		int t, u, v; cin >> t >> u >> v;
//		if (t == 1) {
//			adj[u].push_back(v);
//			adj[v].push_back(u);
//		}
//		else
//		{
//			int flag = 0;
//			for (int m : adj[u]) {
//				if (m == v) {
//					flag = 1;
//					break;
//				}
//			}
//			if (flag)	cout << "Yes" << '\n';
//			else  cout << "No" << '\n';
//		}
//	}
//	return 0;
//}
//const int max_num = 100005;
//vector<int>adj[max_num];
//int sz[max_num];
//void dfs(int x, int fa) {
//	sz[x] = 1;
//	for (int v : adj[x]) {
//		dfs(v, x);
//		sz[x] += sz[v];
//	}
//}
//int main()
//{
//	int n; cin >> n;
//	for (int i = 2; i <= n; i++) {
//		int t; cin >> t;
//		adj[t].push_back(i);
//	}
//	dfs(1, 0);
//	for (int i = 1; i <= n; i++)
//		cout << sz[i] - 1 << ' ';
//	return 0;
//}
//const int max_num = 100005;
//vector<pair<int, int>>adj[max_num];
//int dist[max_num];
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int n, m; cin >> n >> m;
//	for (int i = 1; i <= n; i++)	dist[i] = 1e9;
//	for (int i = 0; i < m; i++) {
//		int u, v, w; cin >> u >> v >> w;
//		adj[u].push_back({ v,w });
//		adj[v].push_back({ u,w });
//	}
//	queue<int>q;
//	q.push(1); dist[1] = 0;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		for (auto& v : adj[u]) {
//			if (dist[v.first] == 1e9 || dist[u] + v.second < dist[v.first]) {
//				dist[v.first] = dist[u] + v.second;
//				q.push(v.first);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (dist[i] == 1e9)	cout << -1 << '\n';
//		else  cout << dist[i] << '\n';
//	}
//	return 0;
//}
 
//const int max_num = 100005;
//vector<int>adj[max_num];
//int dist[max_num];
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int n, m; cin >> n >> m;
//	for (int i = 1; i <= n; i++)	dist[i] = 1e9;
//	for (int i = 0; i < m; i++) {
//		int u, v; cin >> u >> v;
//		adj[u].push_back(v);
//		adj[v].push_back(u);
//	}
//	queue<int>q;
//	q.push(1); dist[1] = 0;
//	while (!q.empty()) {
//		int u = q.front();
//		q.pop();
//		for (int v : adj[u]) {
//			if (dist[v] == 1e9) {
//				dist[v] = dist[u] + 1;
//				q.push(v);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		if (dist[i] == 1e9)	cout << -1 << '\n';
//		else  cout << dist[i] << '\n';
//	}
//	return 0;
//}
//const int max_num = 100005;
//vector<pair<int, int>>adj[max_num];
//int s[max_num], cnt[max_num];
//void dfs(int x, int fa, int step) {
//	s[x] = min(step, s[x]);
//	cnt[x] = 1;
//	for (auto& v : adj[x]) {
//		s[v.first] = min(step + v.second, s[v.first]);
//		if (v.first == fa || cnt[v.first] == 1)	continue;
//		dfs(v.first, x, s[v.first]);
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int n, m; cin >> n >> m;
//	for (int i = 1; i <= n; i++)	s[i] = 1e9;
//	for (int i = 0; i < m; i++) {
//		int u, v, w; cin >> u >> v >> w;
//		adj[u].push_back({ v,w });
//		adj[v].push_back({ u,w });
//	}
//	dfs(1, 0, 0);
//	for (int i = 1; i <= n; i++) {
//		if (cnt[i] == 0)	cout << -1 << '\n';
//		else   cout << s[i] << '\n';
//	}
//	return 0;
//}
//using namespace std;
//const int max_num = 100005;
//vector<int>adj[max_num];
//void dfs(int x, int fa, int* cnt) {
//	cnt[x] = 1;
//	for (int v : adj[x]) {
//		if (v == fa || cnt[x] == 1)	continue;
//		dfs(v, x, cnt);
//	}
//}
//int main()
//{
//	int n, m; cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int u, v; cin >> u >> v;
//		adj[u].push_back(v);
//		adj[v].push_back(u);
//	}int cnt[100005] = { 0 };
//	dfs(1, 0, cnt);
//	bool a = true;
//	for (int i = 1; i <= n; i++) {
//		if (cnt[i] == 0) {
//			a = false;
//			break;
//		}
//	}
//	if (a)	cout << "The graph is connected.";
//	else   cout << "The graph is not connected.";
//	return 0;
//}
//const int max_num = 100005;
//priority_queue<int, vector<int>, greater<int>>adj[max_num];
//int main()
//{
//	ios::sync_with_stdio(false), cin.tie(0);
//	int n, m; cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int u, v; cin >> u >> v;
//		adj[u].push(v);
//		adj[v].push(u);
//	}
//	
//	for (int i = 1; i <= n; i++) {
//		cout << 1 << ": {";
//		while (!adj[i].empty()) {
//			int t = adj[i].top();
//			adj[i].pop();
//			if (adj[i].empty())	cout << t;
//			else  cout << t << ", ";
//		}cout << "}" << endl;
//	}
//	return 0;
//}
//int main()
//{
//	int n, m; cin >> n >> m;
//	vector<int>a(n + 1, 0), b(m + 1, 0);
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1; i <= m; i++)
//		cin >> b[i];
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	int l = 1, r = 1, ans = 0;
//	while (l <= n && r <= m) {
//		if (a[l] * 2 >= b[r]) {
//			ans++; l++; r++;
//		}
//		else   l++;
//	}cout << ans;
//	return 0;
//}
//#define int long long
//signed main()
//{
//	int t; cin >> t;
//	for (int i = 0; i < t; i++) {
//		int x1, y1, r1, x2, y2, r2;
//		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
//		if (r1 > r2) {
//			swap(r1, r2);
//			swap(x1, x2);
//			swap(y1, y2);
//		}
//		int a1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
//		int a2 = (r1 + r2) * (r1 + r2);
//		if (a2 < a1)	cout << "No" << endl;
//		else {
//			if (a1 < (r2 - r1) * (r2 - r1))	cout << "No" << endl;
//			else   cout << "Yes" << endl;
//		}
//	}
//	return 0;
//}