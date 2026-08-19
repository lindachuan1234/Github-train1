#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int a,b;
};
bool cmp(const node& x,const node& y) {
    return x.a < y.a;
}
int main() {
    int n;cin >> n;
    vector<node>q(n + 1);
    for (int i = 1;i <= n;i++) {
        int a,b;cin >> a >> b;
        q[i].a = a;
        q[i].b = b;
    }
    sort(q.begin(),q.end(),cmp);
    return 0;
}
// #define int long long
// signed main() {
//     int n;cin >> n;
//     int cnt[100005],dp[100005];
//     fill(dp,dp + 100005,0);
//     fill(cnt,cnt + 100005,0);
//     for (int i = 1;i <= n;i++) {
//         int a;cin >> a;
//         cnt[a]++;
//     }
//     dp[1] = cnt[1];
//     for (int i = 2;i <= 100000;i++) {
//         dp[i] = max(dp[i - 1],dp[i - 2] + cnt[i] * i);
//     }
//     cout << dp[100000];
//     return 0;
// }
// int d[2] = {2,3};
// int main() {
//     int n;cin >> n;
//     vector<int>a(n + 1,0),b;
//     map<int,int>mp;
//     for (int i = 1;i <= n;i++)  {
//         cin >> a[i];
//         if (mp[a[i]] == 0)  b.push_back(a[i]);
//         mp[a[i]]++;
//     }
//     sort(a.begin(),a.end());
//     sort(b.begin(),b.end());
//     int ans = 0;
//     if (b.size() == 1) {
//         cout << b[0] * mp[b[0]];
//         return 0;
//     }
//     queue<pair<int,int>>q;
//     q.push({0,b[0] * mp[b[0]]});q.push({1,b[1] * mp[b[1]]});
//     while(!q.empty()) {
//         int val = q.front().second;
//         int x = q.front().first;
//         ans = max(ans,val);
//         q.pop();
//         for (int i = 0;i < 2;i++) {
//             if (d[i] + x >= b.size())   break;
//             int nx = x + d[i];
//             int v = val + b[d[i] + x] * mp[b[d[i] + x]];
//             q.push({nx,v});
//         }
//     }
//     cout << ans;
//     return 0;
// }
// int main() {
//     int n,a,b,c;cin >> n >> a >> b >> c;
//     int dp[4005];
//     fill(dp,dp + n + 1,-1);dp[0] = 0;
//     for (int i = 1;i <= n;i++) {
//         if (i >= a && dp[i - a] != -1)  dp[i] = max(dp[i],dp[i - a] + 1);
//         if (i >= b && dp[i - b] != -1)  dp[i] = max(dp[i],dp[i - b] + 1);
//         if (i >= c && dp[i - c] != -1)  dp[i] = max(dp[i],dp[i - c] + 1);
//     }
//     cout << dp[n];
//     return 0;
// }
// const int mod = 1e9 + 7;
// int main() {
//     int n,k,d;cin >> n >> k >> d;
//     int dp0[105] = {0},dp1[105] = {0};
//     dp0[0] = 1;
//     for (int i = 1;i <= n;i++) {
//         for (int j = 1;j < d && j <= i;j++) {
//             dp0[i] = (dp0[i] + dp0[i - j]) % mod;
//         }
//         for (int j = 1;j <= k && j <= i;j++) {
//             dp1[i] = (dp1[i] + dp1[i - j]) % mod;
//         }
//         for (int j = d;j <= k && j <= i;j++) {
//             dp1[i] = (dp1[i] + dp0[i - j]) % mod;
//         }
//     }
//     cout << dp1[n] % mod;
//     return 0;
// }
// const int mod = 1e9 + 7;
// int main() {
//     int ans = 0;
//     int n,k,d;cin >> n >> k >> d;
//     queue<pair<int,pair<int,bool>>>q;
//     q.push({1,{0,false}});
//     while(!q.empty()) {
//         int cnt = q.front().second.first;
//         bool flag = q.front().second.second;
//         int x = q.front().first;
//         for (int i = 1;i <= k;i++) {
//             if (cnt + i > n)    break;
//             if (cnt + i == n) {
//                 if (i >= d) flag = true;
//                 if (flag == false)  break;
//                 ans++;
//                 break;
//             }
//             if (i >= d) flag = true;
//             q.push({x * k + (i - k + 1),{cnt + i,flag}});
//         }
//     }
//     cout << ans;
//     return 0;
// }
// const int mod = 1e9 + 7;
// int main() {
//     int t,k;cin >> t >> k;
//     int dp[100005] = {0};
//     for (int i = 1;i < k;i++) {
//         dp[i] = 1;
//     }dp[k] = 2;
//     for (int i = k + 1;i <= 100000;i++) {
//         dp[i] = dp[i - 1] + dp[i - k];
//         dp[i] %= mod;
//     }
//     for (int i = 1;i <= 100000;i++) {
//         dp[i] = dp[i - 1] + dp[i];
//         dp[i] %= mod;
//     }
//     while(t--) {
//         int a,b;cin >> a >> b;
//         int ans = dp[b] - dp[a - 1] + mod;
//         ans %= mod;
//         cout << ans << '\n';
//     }
//     return 0;
// }
// int main() {
//     int a,b,c;cin >> a >> b >> c;
//     int t = max(a,max(b,c));
//     for (int i = 0;i < t;i++) {
//         cout << "3";
//     }cout << ' ';
//     for (int i = 0;i < t;i++) {
//         cout << "2";
//     }cout << ' ';
//     for (int i = 0;i < t;i++) {
//         cout << "3";
//     }cout << ' ';
//     for (int i = 0;i < t;i++) {
//         cout << "5";
//     }
//     return 0;
// }
// const int max_num = 300005;
// int start,ans;
// vector<int>a,b,adj[max_num];
// map<pair<int,int>,int>mp;
// map<pair<int,int>,bool>vis;
// void dfs(int x,int f,int step) {
//     if (x == start && step != 0) {
//         if (ans > step){
//             ans = step;
//             b = a;
//         }
//         return;
//     }
//     for (int v : adj[x]) {
//         if (v == f) continue;
//         if (vis[{v,x}]) continue;
//         if (vis[{x,v}] == true)  continue;
//         vis[{v,x}] = true;
//         vis[{x,v}] = true;
//         a.push_back(mp[{x,v}]);
//         dfs(v,x,step + pow(2,mp[{x,v}]));
//         vis[{v,x}] = false;
//         vis[{x,v}] = false;
//         a.pop_back();
//     }
// }
// int main(){
//     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     int t;cin >> t;
//     while(t--) {
//         ans = 1e9;
//         int n,m;cin >> n >> m;
//         for (int i = 1;i <= n;i++) {
//             adj[i].clear();
//         }
//         a.clear();b.clear();mp.clear();
//         for (int i = 1;i <= m;i++) {
//             int u,v;cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//             mp[{u,v}] = i;
//             mp[{v,u}] = i;
//         }
//         vis.clear();
//         for (int i = 1;i <= n;i++) {
//             start = i;
//             dfs(i,0,0);
//         }
//         if (b.size() == 0) {
//             cout << -1 << '\n';
//         }
//         else {
//             sort(b.begin(),b.end());
//             for (int i = 0;i < b.size() - 1;i++) {
//                 cout << b[i] << ' ';
//             }
//             cout << b[b.size() - 1];
//             cout << '\n';
//         }
//     }
//     return 0;
// }