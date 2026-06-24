#include<iostream>
#include<vector>
using namespace std;
vector<int>a, tr, lazy, lazy1;
void pushup(int p) {
	tr[p] = tr[p * 2] + tr[p * 2 + 1];
}
void pushdown(int p, int l, int r) {
	if (lazy[p] == 0 && lazy1[p] == 1)	return;
	int mid = (l + r) / 2;
	tr[p * 2] *= lazy1[p];
	tr[p * 2] += lazy[p] * (mid - l + 1);
	lazy1[p * 2] *= lazy1[p];
	lazy[p * 2] = lazy[p * 2] * lazy1[p] + lazy[p];
	tr[p * 2 + 1] *= lazy1[p];
	tr[p * 2 + 1] += lazy[p] * (r - (mid + 1) + 1);
	lazy1[p * 2 + 1] *= lazy1[p];
	lazy[p * 2 + 1] = lazy[p] + lazy[p * 2 + 1] * lazy1[p];
	lazy[p] = 0;
	lazy1[p] = 1;
}
void build(int p, int l, int r) {
	if (l == r) {
		tr[p] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	pushup(p);
}
int query(int p, int l, int r, int ql, int qr) {
	if (l > qr || r < ql)	return 0;
	if (l >= ql && r <= qr)	return tr[p];
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	return query(p * 2, l, mid, ql, qr) + query(p * 2 + 1, mid + 1, r, ql, qr);
}
void query_add(int p, int l, int r, int ql, int qr, int k) {
	if (l > qr || r < ql)	return;
	if (l >= ql && r <= qr) {
		tr[p] += k * (r - l + 1);
		lazy[p] += k;
		return;
	}
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	query_add(p * 2, l, mid, ql, qr, k);
	query_add(p * 2 + 1, mid + 1, r, ql, qr, k);
	pushup(p);
}
void query_mul(int p, int l, int r, int ql, int qr, int k) {
	if (l > qr || r < ql)	return;
	if (l >= ql && r <= qr) {
		tr[p] *= k;
		lazy1[p] *= k;
		return;
	}
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	query_mul(p * 2, l, mid, ql, qr, k);
	query_mul(p * 2 + 1, mid + 1, r, ql, qr, k);
	pushup(p);
}
int main()
{
	int n, q, m; cin >> n >> q >> m;
	a.assign(n + 1, 0); tr.assign(4 * (n + 1), 0); lazy.assign(4 * (n + 1), 0);
	lazy1.assign(4 * (n + 1), 1);
	for (int i = 0; i < q; i++) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			int k; cin >> k;
			query_mul(1, 1, n, x, y, k);
		}
		else if (t == 2) {
			int k; cin >> k;
			query_add(1, 1, n, x, y, k);
		}
		else{
			int ans = query(1, 1, n, x, y);
			cout << ans << endl;
		}
	}
	return 0;
}
//#define int long long
//vector<int>a, tr, lazy;
//void pushup(int p) {
//	tr[p] = tr[p * 2] + tr[p * 2 + 1];
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
//void pushdown(int p, int l, int r) {  //更新左右孩子的值，如果父节点有lazy说明下面没更新
//	if (lazy[p] == 0)	return;
//	int mid = (l + r) / 2;
//	tr[p * 2] += lazy[p] * (mid - l + 1);
//	lazy[p * 2] += lazy[p];
//	tr[p * 2 + 1] += lazy[p] * (r - (mid + 1) + 1);
//	lazy[p * 2 + 1] += lazy[p];
//	lazy[p] = 0;
//}
//int query(int p, int l, int r, int ql, int qr) {
//	if (qr < l || r < ql)	return 0;
//	if (ql <= l && r <= qr)	return tr[p]; //包含就可以输出，左右孩子会自动包含整个区间
//	pushdown(p, l, r);
//	int mid = (l + r) / 2;
//	return query(p * 2, l, mid, ql, qr) + query(p * 2 + 1, mid + 1, r, ql, qr);
//}
//void query_add(int p, int l, int r, int ql, int qr, int k) {
//	if (qr < l || r < ql)	return;
//	if (l >= ql && r <= qr) {
//		tr[p] += k * (r - l + 1); 
//		lazy[p] += k;
//		return;
//	}
//	pushdown(p, l, r);
//	int mid = (l + r) / 2;
//	query_add(p * 2, l, mid, ql, qr, k);
//	query_add(p * 2 + 1, mid + 1, r, ql, qr, k);
//	pushup(p);
//}
//signed main()
//{
//	int n, m; cin >> n >> m;
//	a.assign(n + 1, 0); tr.assign(4 * (n + 1), 0), lazy.assign(4 * (n + 1), 0);
//	for (int i = 1; i <= n; i++)	cin >> a[i];
//	build(1, 1, n);
//	for (int i = 1; i <= m; i++) {
//		int b; cin >> b;
//		if (b == 1) {
//			int x, y, k; cin >> x >> y >> k;
//			query_add(1, 1, n, x, y, k);
//		}
//		else if (b == 2) {
//			int x, y; cin >> x >> y;
//			int ans = query(1, 1, n, x, y);
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}