#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int max_num = 3005;
vector<int>adj[max_num];
int n,m,s1,s2,t1,t2,dist1[max_num],dist2[max_num],dist3[max_num];
bool vis[max_num];
void bfs(int t,int* dist){
    queue<int>q;q.push(t);
    dist[t] = 0;
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        int x = q.front();
        vis[x] = true;
        q.pop();
        for (int v : adj[x]){
            if (vis[v] == false){
                vis[v] = true;
                q.push(v);
                dist[v] = dist[x] + 1;
            }
        }
    }
}
int main()
{
    fill(dist1,dist1 + max_num,-1e9);
    fill(dist2,dist2 + max_num,-1e9);
    fill(dist3,dist3 + max_num,-1e9);
    cin >> n >> m;
    for (int i = 1;i <= m;i++){
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s1 >> t1 >> s2 >> t2;
    bfs(1,dist1);
    bfs(s1,dist2);
    bfs(s2,dist3);
    int ans = 1e9;bool flag = false;
    for (int i = 1;i <= n;i++){
        if (dist1[i] + dist2[i] <= t1 && dist1[i] + dist3[i] <= t2 && dist1[i] >= 0 && dist2[i] >= 0 && dist3[i] >= 0)
            ans = min(ans,dist1[i] + dist2[i] + dist3[i]),flag = true;
    }
    if (flag)   cout << m - ans;
    else   cout << -1;
    return 0;
}
// int ans,fa[50005],c;
// int find(int x){
//     if (x != fa[x] && c <= 2){
//         c++;
//         fa[x] = find(fa[x]);
//     }
//     return fa[x];
// }
// void unite(int x,int y){
//     x = find(x);
//     y = find(y);
//     if (x != y){
//         fa[y] = x;
//     }
// }
// int main(){
//     int n,k;cin >> n >> k;
//     for (int i = 1;i <= n;i++){
//         fa[i] = i;
//     }
//     for (int i = 1;i <= k;i++){
//         int t,x,y;cin >> t >> x >> y;
//         if (t == 1){
//             if (x > n || y > n)     ans++; 
//             else if (x != y) ans++; 
//         }
//         else if (t == 2){
//             if (x > n || y > n)     ans++;
//             else if (x == y)    ans++;
//             else {
//                 c = 0;
//                 unite(x,y);
//                 int t1 = find(x);
//                 if (t1 != y && c == 3){
//                     ans++;c = 0;
//                 }    
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }
// struct node{
//     int x,y,z;
//     node():x(0),y(0),z(0){}
// };
// vector<node>q;
// int fa[5005],ans,cnt;
// bool cmp(const node& x,const node& y){
//     return x.z < y.z;
// }
// int find(int x){
//     if (x != fa[x]){
//         fa[x] = find(fa[x]);
//     }
//     return fa[x];
// }
// void unite(int x,int y){
//     x = find(x);
//     y = find(y);
//     if (x != y){
//         fa[y] = x;
//     }
// }
// int main(){
//     int n,m;cin >> n >> m;
//     q.resize(m + 1);
//     for (int i = 1;i <= m;i++){
//         int x,y,z;cin >> x >> y >> z;
//         q[i].x = x;q[i].y = y;q[i].z = z;
//     }sort(q.begin() + 1,q.end(),cmp);
//     for (int i = 1;i <= n;i++)  fa[i] = i;
//     for (int i = 1;i <= m;i++){
//         if (find(q[i].x) == find(q[i].y))   continue;
//         if (cnt == n - 1)   break;
//         unite(q[i].x,q[i].y);
//         ans += q[i].z;
//         cnt++;
//     }
//     if (cnt != n - 1)   cout << "orz";
//     else   cout << ans;
//     return 0;
// }
// int f[200005];
// int find(int x){
//     if (x != f[x]){
//         f[x] = find(f[x]);
//     }
//     return f[x];
// }
// void unite(int x,int y){
//     x = find(x);
//     y = find(y);
//     if (x != y) f[y] = x;
// }
// int main()
// {
//     int n,m;cin >> n >> m;
//     for (int i = 1;i <= n;i++)  f[i] = i;
//     for (int i = 0;i < m;i++){
//         int z,x,y;cin >> z >> x >> y;
//         if (z == 1){
//             unite(x,y);
//         }
//         else if (z == 2){
//             if (find(x) == find(y)){
//                 cout << 'Y' << '\n';
//             }
//             else  cout << 'N' << '\n';
//         }
//     }
//     return 0;
// }
// #include<queue>
// #include<algorithm>
// #include<cstring>
// using namespace std;
// const int max_num = 5005;
// int vis[max_num],ans;
// priority_queue<int,vector<int>,greater<int>>a[max_num];
// vector<int>adj[max_num];
// struct node{
//     int z,x,y;
//     node():z(0),x(0),y(0){}
// };
// void dfs(int x,int fa){
//     vis[x] = 1;
//     for (int v : adj[x]){
//         if (v == fa)    continue;
//         if (vis[v] == 1)    continue;
//         dfs(v,x);
//     }
// }
// bool cmp(const node& x,const node& y){
//     return x.z < y.z;
// }
// int main(){
//     int n,m;cin >> n >> m;
//     vector<node>q;
//     q.resize(m + 1);
//     for (int i = 1;i <= m;i++){
//         cin >> q[i].x >> q[i].y >> q[i].z;
//         a[q[i].x].push(q[i].z);
//         a[q[i].y].push(q[i].z);
//         adj[q[i].x].push_back(q[i].y);
//         adj[q[i].y].push_back(q[i].x);
//     }
//     sort(q.begin(),q.end(),cmp);
//     dfs(1,0);
//     int flag = 1;
//     for (int i = 1;i <= n;i++)  
//         if (vis[i] == 0)
//             flag = 0;
//     memset(vis,0,sizeof(vis));
//     if (flag){
//         for (int i = 1;i < n - 1;i++){
//             ans += q[i].z;
//             vis[q[i].x] = 1;
//             vis[q[i].y] = 1;
//         }
//         int ok = 1,tt = 0;
//         for (int i = 1;i <= n;i++){
//             if (vis[i] == 0)    ok = 0,tt = i;
//         }
//         if (ok) ans += q[n - 1].z;
//         else  ans += a[tt].top();
//         cout << ans;
//     }
//     else{
//         cout << "orz";
//     }
//     return 0;
//}
// const int max_num = 105;
// vector<int>adj[max_num];
// int s[max_num],sum,sz[max_num],max_sub[max_num],ans;
// void dfs_size(int x,int f,int step){
//     sz[x] = s[x];
//     for (int v : adj[x]){
//         if (v == f) continue;
//         dfs_size(v,x,step + 1);
//         sz[x] += sz[v];
//         max_sub[x] = max(max_sub[x],sz[v]);
//     }
//     max_sub[x] = max(max_sub[x],sum - sz[x]);
// }
// void dfs(int x,int f,int step){
//     ans += step * s[x];
//     for (int v : adj[x]){
//         if (v == f) continue;
//         dfs(v,x,step + 1);
//     }
// }
// int main()
// {
//     int n;cin >> n;
//     for (int i = 1;i <= n;i++){
//         int w,u,v;cin >> w >> u >> v;
//         if (u != 0){
//             adj[u].push_back(i);
//             adj[i].push_back(u);
//         }
//         if (v != 0){
//             adj[v].push_back(i);
//             adj[i].push_back(v);
//         }
//         s[i] = w;sum += w;
//     } 
//     dfs_size(1,0,0);
//     int root = 1;
//     for (int i = 2;i <= n;i++){
//         if (max_sub[root] > max_sub[i]){
//             root = i;
//         }
//     }
//     dfs(root,0,0);
//     cout << ans;
//     return 0;
// }
// const int max_num = 100005;
// vector<int>adj[max_num];
// int dist[max_num],ans;
// void dfs_1(int x,int f,int step){
//     dist[x] = step;
//     for (int v : adj[x]){
//         if (v == f) continue;
//         dfs_1(v,x,step + 1);
//     }
// }
// void dfs_2(int x,int f,int step){
//     ans = max(ans,step);
//     for (int v : adj[x]){
//         if (v == f) continue;
//         dfs_2(v,x,step + 1);
//     }
// }
// int main()
// {
//     int n;cin >> n;
//     for (int i = 1;i < n;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     dfs_1(1,0,0);
//     int start = 1;
//     for (int i = 2;i <= n;i++){
//         if (dist[i] > dist[start]){
//             start = i;
//         }
//     }
//     dfs_2(start,0,0);
//     cout << ans;
//     return 0;
// }
// const int max_num = 50005;
// vector<int>adj[max_num];
// int sz[max_num],max_sub[max_num],n,ans;
// void dfs_size(int x,int f){
//     sz[x] = 1;
//     for (int v : adj[x]){
//         if (v == f) continue;
//         dfs_size(v,x);
//         sz[x] += sz[v];
//         max_sub[x] = max(max_sub[x],sz[v]);
//     }
//     max_sub[x] = max(max_sub[x],n - sz[x]);
// }
// void dfs(int x,int f,int step){
//     ans += step;
//     for (int v : adj[x]){
//         if (v == f) continue;
//         dfs(v,x,step + 1);
//     }
// }
// int main(){
//     cin >> n;
//     for (int i = 1;i < n;i++){
//         int u,v;cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     dfs_size(1,0);
//     int root = 1;
//     for (int i = 2;i <= n;i++){
//         if (max_sub[root] > max_sub[i])
//             root = i;
//     }
//     dfs(root,0,0);
//     cout << root << ' ' << ans;
//     return 0;
// }
// int main()
// {
//     int n,k;cin >> n >> k;
//     if (n == k) cout << 0;
//     else{
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
//     bool mp[200005];
//     q.push({0,n});
//     while(!q.empty()){
//         int step = q.top().first;
//         int val = q.top().second;
//         mp[val] = 1;
//         q.pop();
//         if (val * 2 == k)   {
//             cout << step + 1;
//             break;
//         }
//         if (val + 1 == k){
//             cout << step + 1;
//             break;
//         }
//         if (val - 1 == k){
//             cout << step + 1;
//             break;
//         }
//         if (val < k && mp[val * 2] == 0)    q.push({step + 1,val * 2});
//         if (val + 1 < 200005 && mp[val + 1] == 0)    q.push({step + 1,val + 1});
//         if (val - 1 > 0 && mp[val - 1] == 0)   q.push({step + 1,val - 1});
//     }
//     }
//     return 0;
// }
// int main()
// {
//     int n,k;cin >> n >> k;
//     int ans = 0;
//     while(n * 2 <= k){
//         n *= 2;
//         ans++;
//     }
//     int t = n - k;
//     if (t == 0) cout << ans;
//     else{
//         int t = 2 * n - k;
//         int aa = k - n + ans;
//         ans++;
//         for (int i =20;i > 0;i--){
//             if ((1 << i) <= t){
//                 ans += i;
//                 t -= (1 << i);
//                 break;
//             }
//         }
//         ans += t;
//         cout << min(aa,ans);
//         }
//     return 0;
// }
// const int max_num = 500005;const int LOGN = 20;
// vector<int>adj[max_num];
// int fa[max_num][LOGN],depth[max_num];
// void dfs_size(int x,int f,int step){
//     fa[x][0] = f;
//     depth[x] = step;
//     for (int i = 1;i < 20 && (1 << i) < step;i++){
//         fa[x][i] = fa[fa[x][i - 1]][i - 1];
//     }
//     for (int v : adj[x]){
//         if (v == f) continue;
//         dfs_size(v,x,step + 1);
//     }
// }
// int dfs(int x,int y){
//     if (depth[x] < depth[y]){
//         int tmp = x;
//         x = y;
//         y = tmp;
//     }
//     for (int i = 19;i >= 0;i--){
//         if (depth[x] - (1 << i) >= depth[y]){
//             x = fa[x][i];
//         }
//     }
//     if (x == y) return x;
//     else{
//         for (int i = 19;i >= 0;i--){
//             if (fa[x][i] != fa[y][i]){
//                 x = fa[x][i];
//                 y = fa[y][i];
//             }
//         }
//         return fa[x][0];
//     }
// }
// int main(){
//     int n,m,s;cin >> n >> m >> s;
//     for (int i = 1;i < n;i++){
//         int x,y;cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     dfs_size(s,0,1);
//     for (int i = 1;i <= m;i++){
//         int a,b;cin >> a >> b;
//         int ans = dfs(a,b);
//         cout << ans << '\n';
//     }
//     return 0;
// }
// int dx[4] = {-1,0,0,1};
// int dy[4] = {0,1,-1,0};
// vector<vector<int>>mp;
// vector<vector<bool>>vis;
// queue<pair<int,int>>q;
// int n;
// void bfs(int a,int b){
//     q.push({a,b});
//     vis[a][b] = true;
//     while(!q.empty()){
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();
//         for (int i = 0;i < 4;i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if (nx >= 1 && nx <= n && ny >= 1 && ny <= n){
//                 if (!vis[nx][ny]&& mp[nx][ny] == 0){
//                     vis[nx][ny] = true;
//                     q.push({nx,ny});
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n;
//     mp.assign(n + 1,vector<int>(n + 1,0));
//     vis.assign(n + 1,vector<bool>(n + 1,0));
//     for (int i = 1;i <= n;i++){
//         for (int j = 1;j <= n;j++){
//             cin >> mp[i][j];
//         }
//     }
//     for (int i = 1;i <= n;i++){
//         if (!vis[i][1] && mp[i][1] == 0){
//             bfs(i,1);
//         }
//         if (!vis[1][i] && mp[1][i] == 0){
//             bfs(1,i);
//         }
//         if (!vis[i][n] && mp[i][n] == 0){
//             bfs(i,n);
//         }
//         if (!vis[n][i] && mp[n][i] == 0){
//             bfs(n,i);
//         }
//     }
//     for (int i = 1;i <= n;i++){
//         for (int j = 1;j <= n;j++){
//             if (mp[i][j] == 0){
//                 if (vis[i][j] == true)
//                     cout << 0 << ' ';
//                 else
//                     cout << 2 << ' ';
//             }
//             else   cout << mp[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }