#include<iostream>
#include<vector>
using namespace std;
//#define int long long
//vector<int>a, tr, lazy1, lazy2;
//int m;
//void pushup(int p) {
//	tr[p] = (tr[p * 2] + tr[p * 2 + 1]) % m;
//}
//void pushdown(int p, int l, int r) {
//	if (lazy1[p] == 1 && lazy2[p] == 0)	return;
//	int mid = (l + r) / 2;
//	tr[p * 2] *= lazy1[p] % m;
//	tr[p * 2] += (lazy2[p] % m) * (mid - l + 1);
//	tr[p * 2] %= m;
//	lazy1[p * 2] = (lazy1[p] * lazy1[p * 2]) % m;
//	lazy2[p * 2] = ((lazy2[p * 2]) % m * (lazy1[p] % m) + (lazy2[p] % m)) % m;
//	lazy1[p * 2] %= m;
//	lazy2[p * 2] %= m;
//	tr[p * 2 + 1] = ((tr[p * 2 + 1] % m) * (lazy1[p] % m) + (lazy2[p] % m) * (r - mid)) % m;
//	tr[p * 2 + 1] %= m;
//	lazy1[p * 2 + 1] *= lazy1[p] % m;
//	lazy2[p * 2 + 1] = ((lazy2[p * 2 + 1] % m) * (lazy1[p] % m) + (lazy2[p] % m) ) % m;
//	lazy1[p * 2 + 1] %= m;
//	lazy2[p * 2 + 1] %= m;
//	lazy1[p] = 1; lazy2[p] = 0;
//}
//void build(int p, int l, int r) {
//	if (l == r) {
//		tr[p] = a[l] % m;
//		return;
//	}
//	int mid = (l + r) / 2;
//	build(p * 2, l, mid);
//	build(p * 2 + 1, mid + 1, r);
//	pushup(p);
//}
//int query(int p, int l, int r, int ql, int qr) {
//	if (l > qr || r < ql)	return 0;
//	if (l >= ql && r <= qr)	return tr[p];
//	int mid = (l + r) / 2;
//	pushdown(p, l, r); // ËÆºõ²»ÐèÒª
//	return (query(p * 2, l, mid, ql, qr) + query(p * 2 + 1, mid + 1, r, ql, qr)) % m;
//}
//void query_add(int p, int l, int r, int ql, int qr, int k) {
//	if (l > qr || r < ql)	return;
//	if (l >= ql && r <= qr) {
//		tr[p] += k * (r - l + 1);
//		lazy2[p] += k;
//		tr[p] %= m;
//		lazy2[p] %= m;
//		return;
//	}
//	int mid = (l + r) / 2;
//	pushdown(p, l, r);
//	query_add(p * 2, l, mid, ql, qr, k);
//	query_add(p * 2 + 1, mid + 1, r, ql, qr, k);
//	pushup(p);
//}
//void query_mul(int p, int l, int r, int ql, int qr, int k) {
//	if (l > qr || r < ql)	return;
//	if (l >= ql && r <= qr) {
//		tr[p] *= k;
//		lazy1[p] *= k;
//		lazy2[p] *= k;
//		tr[p] %= m;
//		lazy1[p] %= m;
//		lazy2[p] %= m;
//		return;
//	}
//	int mid = (l + r) / 2;
//	pushdown(p, l, r);
//	query_mul(p * 2, l, mid, ql, qr, k);
//	query_mul(p * 2 + 1, mid + 1, r, ql, qr, k);
//	pushup(p);
//}
//signed main()
//{
//	int n, q; cin >> n >> q >> m;
//	a.assign(n + 1, 0); tr.assign(4 * (n + 1), 0); 
//	lazy1.assign(4 * (n + 1), 1); lazy2.assign(4 * (n + 1), 0);
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		a[i] %= m;
//	}
//	build(1, 1, n);
//	for (int i = 0; i < q; i++) {
//		int t, x, y; cin >> t >> x >> y;
//		if (t == 1) {
//			int k; cin >> k;
//			query_mul(1, 1, n, x, y, k);
//		}
//		else if (t == 2) {
//			int k; cin >> k;
//			query_add(1, 1, n, x, y, k);
//		}
//		else if (t == 3) {
//			int ans = query(1, 1, n, x, y) % m;
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}