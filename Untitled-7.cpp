#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,m;cin >> n >> m;
    while(1){
        queue<int>q;
        int x,y;cin >> x;
        vector<int>adj[1005];
        if (x == 0) break;
        cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        for (int i = 1;i < m;i++){
            int x,y;cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool>vis(m + 1,false);
        bool flag = false;
        for (int i = 1;i <= n;i++){
            if (vis[i] == true) continue;
            q.push(i);
            int ff = i,cnt = 1;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for (int v : adj[x]){
                    if (v == ff)    {
                        vis[ff] = true;
                        break;
                    }
                    if (!vis[v]){
                        q.push(v);
                        cnt++;
                        vis[v] = true;
                    }
                }
            }   
            if (cnt == n){
                flag = true;
                break;
            }
        }
        if (flag)   cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
// const int max_num = 200005;
// vector<int>adj[max_num];
// int main(){
//     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     int t;cin >> t;
//     while(t--){
//         int n,m,k;cin >> n >> m >> k;
//         vector<int>ans;
//         vector<int>cntw(n + 1,0);
//         vector<bool>ww(n + 1,false);
//         queue<int>q;
//         for (int i = 0;i <= n;i++){
//             adj[i].clear();
//         }
//         for (int i = 0;i < m;i++){
//             int u,v;cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         int c;
//         for (int i = 1;i <= k;i++)  {
//             cin >> c;
//             ww[c] = true;
//             for (int v : adj[c]){
//                 if (ww[v] == true)  continue;
//                 cntw[v]++;
//                 if (cntw[v] == 2){
//                     q.push(v);
//                 }
//             }
//         }
//         for (int i = 1;i <= n;i++)  {
//             if(ww[i] == true){
//                 for (int v : adj[i]){
//                 if (ww[v] == true)  continue;
//                 cntw[v]++;
//                 if (cntw[v] == 2){
//                     q.push(v);
//                 }
//             }
//             }
//         }
//         while(!q.empty()){
//             int x = q.front();
//             q.pop();
//             for (int v : adj[x]){
//                 if (ww[v] == true)  continue;
//                 cntw[v]++;
//                 if (cntw[v] == 2)    q.push(v);
//             }
//         }
//         for (int i = 1;i <= n;i++){
//             if (cntw[i] >= 1 && ww[i] == false) {
//                 ans.push_back(i);
//             }
//         }
//         if (!ans.empty()) {
//             cout << ans.size() << '\n';
//             for (int i = 0;i < ans.size();i++)  cout << ans[i] << ' ';
//             cout << '\n';
//         }
//     }
//     return 0;
// }
// #define int long long
// struct node{
//     int x,y,val;
// };
// int dx[8] = {-1,0,0,1,-1,-1,1,1};
// int dy[8] = {0,1,-1,0,1,-1,1,-1};
// signed main(){
//     int n,m;cin >> n >> m;
//     int cx,cy,ddx,ddy;
//     vector<string>str(n + 1);
//     vector<vector<int>>dist1(n + 1,vector<int>(m + 1,0));
//     vector<vector<int>>dist2(n + 1,vector<int>(m + 1,0));
//     vector<vector<bool>>vis1(n + 1,vector<bool>(m + 1,0));
//     vector<vector<bool>>vis2(n + 1,vector<bool>(m + 1,0));
//     for (int i = 1;i <= n;i++){
//         str[i] = " ";
//         for (int j = 1;j <= m;j++){
//             string a;cin >> a;
//             str[i] += a;
//             if (a == "C"){
//                 cx = i;cy = j;
//             }
//             else if (a == "D") {
//                 ddx = i;ddy = j;
//             }
//         }
//     }
//     if (cx == ddx && cy == ddy){
//         cout << "YES" << '\n' << 0;
//         return 0;
//     }
//     queue<node>q;q.push({cx,cy,0});vis1[cx][cy] = true;
//     while(!q.empty()){
//         int x = q.front().x;
//         int y = q.front().y;
//         int val = q.front().val;
//         q.pop();
//         for (int i = 0;i < 8;i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if (nx < 1 || nx > n || ny < 1 || ny > m)   continue;
//             if (str[nx][ny] == '#') continue;
//             if (!vis1[nx][ny]){
//                 q.push({nx,ny,val + 1});
//                 dist1[nx][ny] = val + 1;
//                 vis1[nx][ny] = true;
//             }
//         }
//     }
//     q.push({ddx,ddy,0});vis2[ddx][ddy] = true;
//     while(!q.empty()){
//         int x = q.front().x;
//         int y = q.front().y;
//         int val = q.front().val;
//         q.pop();
//         for (int i = 0;i < 4;i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if (nx < 1 || nx > n || ny < 1 || ny > m)   continue;
//             if (str[nx][ny] == '#') continue;
//             for (int j = 0;j < 4;j++){
//                 int nnx = nx + dx[j];
//                 int nny = ny + dy[j];
//                 if (nnx < 1 || nnx > n || nny < 1 || nny > m)   continue;
//                 if (str[nnx][nny] == '#') continue;
//                 if (!vis2[nnx][nny]){
//                     q.push({nnx,nny,val + 1});
//                     dist2[nnx][nny] = val + 1;
//                     vis2[nnx][nny] = true;
//                 }
//             }
//         }
//     }
//     int ans = 1e18;
//     bool flag = false;
//     for (int i = 1;i <= n;i++){
//         for (int j = 1;j <= m;j++){
//             if (dist1[i][j] > 0 && dist2[i][j] > 0){
//                 ans = min(ans,max(dist1[i][j],dist2[i][j]));
//                 flag = true;
//             }
//         }
//     }
//     if (flag)   {
//         cout << "YES" << '\n' << ans;
//     }
//     else  cout << "NO";
//     return 0;
// }
// struct node{
//     int x,y,i,j;
//     int time;
// };
// int c1[8] = {-1,-1,-1,0,0,1,1,1};
// int c2[8] = {-1,0,1,1,-1,-1,0,1};
// int d1[4] = {-1,0,0,1};
// int d2[4] = {0,1,-1,0};
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     int n,m;cin >> n >> m;
//     vector<string>a(n + 1);
//     vector<vector<bool>>vis1(n + 1,vector<bool>(m + 1,false));
//     vector<vector<bool>>vis2(n + 1,vector<bool>(m + 1,false));
//     int cx = 0,cy = 0,dx = 0,dy = 0;
//     for (int i = 1;i <= n;i++)  {
//         a[i] += ' ';
//         for (int j = 1;j <= m;j++){
//             string c;cin >> c;
//             a[i] += c;
//             if (a[i][j] == 'C'){
//                 cx = i,cy = j;
//             }
//             else if (a[i][j] == 'D'){
//                 dx = i,dy = j;
//             }
//         }
//     }
//     queue<node>q;q.push({cx,cy,dx,dy,0});
//     vis1[cx][cy] = true;vis2[dx][dy] = true;
//     while(!q.empty()){
//         int cx = q.front().x;
//         int cy = q.front().y;
//         int dx = q.front().i;
//         int dy = q.front().j;
//         int time = q.front().time;
//         q.pop();
//         for (int i = 0;i < 8;i++){
//             int ncx = cx + c1[i];
//             int ncy = cy + c2[i];
//             if (ncx < 1 || ncx > n || ncy < 1 || ncy > m)   continue;
//             if (a[ncx][ncy] == '#') continue;
//             if (vis1[ncx][ncy])  continue;
//             vis1[ncx][ncy] = true;
//             if (vis2[ncx][ncy]){
//                 cout << "YES" << '\n';
//                 cout << time + 1;
//                 exit(0);
//             }
//             for (int j = 0;j < 4;j++){
//                 int ndx = dx + d1[j];
//                 int ndy = dy + d2[j];
//                 if (ndx < 1 || ndx > n || ndy < 1 || ndy > m)   continue;
//                 if (vis2[ndx][ndy])  continue;
//                 if (a[ndx][ndy] == '#') continue;
//                 vis2[ndx][ndy] = true;
//                 if (vis1[ndx][ndy]){
//                     cout << "YES" << '\n';
//                     cout << time + 1;
//                     exit(0);
//                 }
//                 if (abs(ndx - ncx) + abs(ndy - ncy) == 0)   {
//                     cout << "YES" << '\n';
//                     cout << time + 1;
//                     exit(0);
//                 }
//                 q.push({ncx,ncy,ndx,ndy,time + 1});
//                 for (int k = 0;k < 4;k++){
//                     int ndx2 = d1[k] + ndx;
//                     int ndy2 = d2[k] + ndy;
//                     if (ndx2 < 1 || ndx2 > n || ndy2 < 1 || ndy2 > m)   continue;
//                     if (a[ndx2][ndy2] == '#') continue;
//                     if (vis2[ndx2][ndy2])  continue;
//                     vis2[ndx2][ndy2] = true;
//                     if (vis1[ndx2][ndy2]){
//                     cout << "YES" << '\n';
//                     cout << time + 1;
//                     exit(0);
//                 }
//                     if (abs(ndx2 - ncx) + abs(ndy2 - ncy) == 0)   {
//                         cout << "YES" << '\n';
//                         cout << time + 1;
//                         exit(0);
//                     }
//                 q.push({ncx,ncy,ndx2,ndy2,time + 1});
//                 }
//             }
//         }
//     }
//     cout << "NO";
//     return 0;
// }
// #define int long long
// const int base = 131;
// int hashe[1500005];
// const int mod = 1500005;
// signed main(){
//     int t;cin >> t;
//     int ans = 0;
//     while(t--){
//         string ret;cin >> ret;
//         int tt = 0;
//         for (int i = 0;i < ret.size();i++){
//             tt += (ret[i] * base) % mod;
//         }
//         if (hashe[tt] == 0)  ans++;
//         hashe[tt] = 1;
//     }cout << ans;
//     return 0;
// }
// int main(){
//     int t;cin >> t;
//     map<string,int>mp;
//     int ans = 0;
//     while(t--){
//         string ret;cin >> ret;
//         if (mp[ret] == 0)    ans++;
//         mp[ret] = 1;
//     }
//     cout << ans;
//     return 0;
// }
// vector<int>d,e;
// int main(){
//     int n;cin >> n;
//     for (int i = 0;i < n;i++){
//         int a,b;cin >> a >> b;
//         d.push_back(a);
//         e.push_back(b);
//     }sort(d.begin(),d.end());sort(e.begin(),e.end());
//     int ans = 0;
//     for (int i = 0;i < n;i++){
//         ans += e[i] - d[i];
//         if (i < n - 1){
//             if (d[i + 1] < e[i]){
//                 ans -= (e[i] - d[i + 1]);
//             }
//         }
//     }cout << ans;
//     return 0;
// }
// #define int long long
// vector<int>a,b;
// int ans;
// void msort(int l,int r){
//     if (l == r) return;
//     int mid = (l + r) / 2;
//     int i = l,j = mid + 1,k = l;
//     msort(l,mid);msort(mid + 1,r);
//     while(i <= mid && j <= r){
//         if (a[i] <= a[j]){
//             b[k++] = a[i++];
//         }
//         else {
//             b[k++] = a[j++];
//             ans += mid - i + 1;
//         }
//     }
//     while(i <= mid){
//         b[k++] = a[i++];
//     }
//     while(j <= r){
//         b[k++] = a[j++];
//     }
//     for (int i = l;i <= r;i++)
//         a[i] = b[i];
// }
// signed main(){
//     int n;cin >> n;
//     a.assign(n + 1,0);b.assign(n + 1,0);
//     for (int i = 1;i <= n;i++){
//         cin >> a[i];
//     }msort(1,n);
//     cout << ans;
//     return 0;
// }