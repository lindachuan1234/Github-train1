#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int mod = 100003;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m;cin >> n >> m;
    vector<int>dist_min(n + 1,0),cnt_min(n + 1,0);
    vector<int>adj[n + 1];
    dist_min[1] = 0;
    for (int i = 2;i <= n;i++){
        dist_min[i] = 1e9;
        cnt_min[i] = 0;
    }cnt_min[1] = 1;
    for (int i = 0;i < m;i++){
        int u,v;cin >> u >> v;
        if (u == v){
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int v : adj[x]){
            if (dist_min[v] == 1e9){
                q.push(v);
                dist_min[v] = dist_min[x] + 1;
                cnt_min[v] = cnt_min[x];
            }
            else if (dist_min[x] + 1 == dist_min[v]){
                cnt_min[v] += cnt_min[x];
                cnt_min[v] %= mod;
            }
        }
    }
    for (int i = 1;i <= n;i++){
        cout << cnt_min[i] % mod << '\n';
    }
    return 0;
}
// const int max_num = 100005;
// vector<int>adj[max_num];
// int main(){
//     int n,m,s;cin >> n >> m >> s;
//     for (int i = 0;i < m;i++){
//         int n,m,s;cin >> n >> m >> s;
//         adj[n].push_back(m);
//         adj[m].push_back(n);

//     }
//     return 0;
// }
// const int max_num = 10005;
// vector<int>adj[max_num];
// vector<int>a,sz;
// vector<bool>vis;
// int n,m;
// void dfs(int x,int f){
//     sz[x] = a[x];
//     for (int v : adj[x]){
//         if (v == f) continue;
//         if (!vis[v]){
//             vis[v] = true;
//             dfs(v,x);
//             sz[x] += sz[v];
//         }
//         else sz[x] += sz[v];
//     }
// }
// int main(){
//     cin >> n >> m;
//     a.assign(n + 1,0);vis.assign(n + 1,false);
//     sz.assign(n + 1,0);
//     for (int i = 1;i <= n;i++)  cin >> a[i];
//     for (int i = 0;i < m;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//     }
//     for (int i = 1;i <= n;i++){
//         if (!vis[i]){
//             vis[i] = true;
//             dfs(i,0);
//         }
//     }
//     int ans = 0;
//     for (int i = 1;i <= n;i++){
//         ans = max(ans,sz[i]);
//     }
//     cout << ans;
//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     while(1){
//         bool vis[10005];
//         memset(vis,false,sizeof(vis));
//         queue<int>q;
//         int n,m;cin >> n;
//         if (n == 0) break;
//         cin >> m;
//         vector<int>adj[10005];
//         for (int i = 1;i <= n;i++)  adj[i].clear();
//         vector<int>ind(n + 1,0);
//         for (int i = 1;i <= n;i++)  ind[i] = 0;
//         for (int i = 0;i < m;i++){
//             int x,y;cin >> x >> y;
//             adj[x].push_back(y);
//             adj[y].push_back(x);
//             ind[x]++;ind[y]++;
//         }
//         bool fff = false;
//         for (int i = 1;i <= n;i++){
//             if (ind[i] % 2 != 0){
//                 cout << 0 << '\n';
//                 fff = true;
//                 break;
//             }
//         }
//         if (fff)    continue;
//         q.push(1);vis[1] = true;
//         while(!q.empty()){
//             int x = q.front();
//             q.pop();
//             vis[x] = true;
//             for (int v : adj[x]){
//                 if (!vis[v]){
//                     q.push(v);
//                 }
//             }
//         }
//         bool flag = true;
//         for (int i = 1;i <= n;i++){
//             if (vis[i] == false)    flag = false;
//         }
//         if (flag)   cout << 1 << '\n';
//         else cout << 0 << '\n';
//     }
//     return 0;
// }
// int main(){
//     int n;cin >> n;
//     vector<int>ind(n + 1,0),a[105];
//     for (int i = 1;i <= n;i++){
//         int t;
//         while(cin >> t && t > 0){
//             ind[t]++;
//             a[i].push_back(t);
//         }
//     }
//     queue<int>q;
//     for (int i = 1;i <= n;i++){
//         if (ind[i] == 0){
//             q.push(i);
//             break;
//         }
//     }
//     while(!q.empty()){
//         int x = q.front();
//         cout << x << ' ';
//         q.pop();
//         ind[x]--;
//         for (int v : a[x]){
//             ind[v]--;
//         }
//         for (int i = 1;i <= n;i++){
//             if (ind[i] == 0){
//                 q.push(i);
//                 break;
//             }
//         }
//     }
//     return 0;
// }