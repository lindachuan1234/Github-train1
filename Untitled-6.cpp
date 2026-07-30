#include<iostream>
#include<vector>
using namespace std;
// #define int long long
// int n,m;
// vector<int>a;
// vector<bool>vis;
// int t,ans;
// void dfs(int x){
//     t += a[x];
//     if (t > m)  {
//         t -= a[x];
//         return;
//     }
//     else{
//         ans++;
//     }
//     for (int i = 1;i <= n;i++){
//         if (!vis[i]){
//             vis[i] = true;
//             dfs(i);
//             vis[i] = false;
//         }
//     }
//     t -= a[x];
// }
// signed main(){
//     cin >> n >> m;
//     a.assign(n + 1,0);vis.assign(n + 1,false);
//     for (int i = 1;i <= n;i++)  cin >> a[i];
//     for (int i = 1;i <= n;i++){
//         vis[i] = true;
//         dfs(i);
//         vis[i] = false;
//     }
//     cout << ans + 1;
//     return 0;
// }
// int dx[4] = {-1,0,0,1};
// int dy[4] = {0,1,-1,0};
// int cnt;
// struct node{
//     int x,y,k;
// };
// bool cmp(const pair<int,int>& x,const pair<int,int>& y){
//     if (x.first != y.first)
//         return x.first < y.first;
//     else   
//         return x.second < y.second;
// }
// auto enc = [](int x, int y, int k) -> long long {
//       return ((1LL * x) << 42) | ((1LL * y) << 22) | (1LL * k);
//   };
// int main(){
//     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     int t;cin >> t;
//     while(t--){
//         int flag = 0;
//         cnt = 0;
//         int n,m;cin >> n >> m;
//         vector<string>mp(n + 1," ");
//         vector<vector<int>>dog(n + 1,vector<int>(m + 1,0));
//         vector<pair<int,int>>dogg,ans;dogg.push_back({0,0});
//         int sx = 0,sy = 0;
//         for (int i = 1;i <= n;i++)  {
//             string ret;cin >> ret;
//             mp[i] += ret;
//             for (int j = 1;j <= m;j++)
//                 if (mp[i][j] == 'S')
//                     sx = i,sy = j;
//         }
//         for (int i = 1;i <= n;i++){
//             for (int j = 1;j <= m;j++){
//                 if (mp[i][j] == 'U'){
//                     cnt++;
//                     dogg.push_back({i,j});
//                     for (int k = 1;i - k > 0;k++){
//                         if (mp[i - k][j] == '#' || mp[i - k][j] == 'D' || mp[i - k][j] == 'L' || mp[i - k][j] == 'R' || mp[i - k][j] == 'U'){
//                             break;
//                         }
//                         if (dog[i - k][j] == 0)  dog[i - k][j] = cnt;
//                         else dog[i - k][j] = -1;
//                     }
//                 }
//                 else if (mp[i][j] == 'D'){
//                     cnt++;
//                     dogg.push_back({i,j});
//                     for (int k = 1;i + k <= n;k++){
//                         if (mp[i + k][j] == '#' || mp[i + k][j] == 'D' || mp[i + k][j] == 'L' || mp[i + k][j] == 'R' || mp[i + k][j] == 'U'){
//                             break;
//                         }
//                         if (dog[i + k][j] ==  0)  dog[i + k][j] = cnt;
//                         else dog[i + k][j] = -1;
//                     }
//                 }
//                 else if (mp[i][j] == 'L'){
//                     cnt++;
//                     dogg.push_back({i,j});
//                     for (int k = 1;j - k > 0;k++){
//                         if (mp[i][j - k] == '#' || mp[i][j - k] == 'D' || mp[i][j - k] == 'L' || mp[i][j - k] == 'R' || mp[i][j - k] == 'U'){
//                             break;
//                         }
//                         if (dog[i][j - k] == 0) dog[i][j - k] = cnt;
//                         else dog[i][j - k] = -1;
//                     }
//                 }
//                 else if (mp[i][j] == 'R'){
//                     cnt++;
//                     dogg.push_back({i,j});
//                     for (int k = 1;j + k <= m;k++){
//                         if (mp[i][j + k] == '#' || mp[i][j + k] == 'D' || mp[i][j + k] == 'L' || mp[i][j + k] == 'R' || mp[i][j + k] == 'U'){
//                             break;
//                         }
//                         if (dog[i][j + k] == 0) dog[i][j + k] = cnt;
//                         else dog[i][j + k] = -1;
//                     }
//                 }
//             }
//         }
//         unordered_set<long long>vis;
//         queue<node>q;q.push({sx,sy,0});
//         vis.insert(enc(sx,sy,0));
//         while(!q.empty()){
//             int x = q.front().x;
//             int y = q.front().y;
//             int k = q.front().k;
//             q.pop();
//             for (int i = 0;i < 4;i++){
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if (nx < 1 || nx > n || ny < 1 || ny > m)   continue;
//                 if (vis.count(enc(nx,ny,k)) && mp[nx][ny] != 'E') continue;
//                 if (dog[nx][ny] == -1 && mp[nx][ny] != 'E')  continue;
//                 if (mp[nx][ny] == '.' && dog[nx][ny] == 0){
//                     q.push({nx,ny,k});
//                     vis.insert(enc(nx,ny,k));
//                 }
//                 else if (mp[nx][ny] == '.' && dog[nx][ny] != 0 && dog[nx][ny] == k){
//                     q.push({nx,ny,k});
//                     vis.insert(enc(nx,ny,k));
//                 }
//                 else if (mp[nx][ny] == '.' && dog[nx][ny] != 0 && k == 0){
//                     q.push({nx,ny,dog[nx][ny]});
//                     vis.insert(enc(nx,ny,dog[nx][ny]));
//                 }
//                 else if (mp[nx][ny] == 'E'){
//                     flag = 1;
//                     ans.push_back(dogg[k]);
//                 }
//             }
//         }
//         if (flag){
//             sort(ans.begin(),ans.end(),cmp);
//             if (ans[0].first != 0 && ans[0].second != 0)    cout << ans[0].first << ' ' << ans[0].second << '\n';
//             else  cout << dogg[1].first << ' ' << dogg[1].second << '\n';
//         }
//         else   cout << -1 << ' ' << -1 << '\n';
//     }
//     return 0;
// }
// //差分树状数组
// #define int long long
// vector<int>a,tr;
// int n,m;
// int lowbit(int x){
//     return x & (-x);
// }
// void init(){
//     for (int i = 1;i <= n;i++)
//         for (int j = i - lowbit(i) + 1;j <= i;j++)
//             tr[i] += a[j] - a[j - 1];
// }
// void add(int x,int k){
//     for (int i = x;i <= n;i+=lowbit(i)){
//         tr[i] += k;
//     }
// }
// int ask(int x){
//     int ans = 0;
//     for (int i = x;i > 0;i-=lowbit(i)){
//         ans += tr[i];
//     }
//     return ans;
// }
// signed main(){
//     cin >> n >> m;
//     a.assign(n + 1,0);tr.assign(n + 1,0);
//     for (int i = 1;i <= n;i++)  cin >> a[i];
//     init();
//     for (int i = 0;i < m;i++){
//         int b;cin >> b;
//         if (b == 1){
//             int x,y,k;cin >> x >> y >> k;
//             add(x,k);add(y + 1,-k);
//         }
//         else if (b == 2){
//             int x;cin >> x;
//             cout << ask(x) << '\n';
//         }
//     }
//     return 0;
// }
// int n,m;
// vector<int>a,tr;
// int lowbit(int x) // t[x]节点的长度  t[x]父节点为t[x + lowbit(x)]  t[x - lowbit(x)]为左上
// {
//     return x & (~x + 1);
// }
// void add(int x,int k){
//     a[x] += k;
//     for (int i = x;i <= n;i+=lowbit(i)){
//         tr[i] += k;
//     }
// }
// int sum(int x){
//     int ans = 0;
//     for (int i = x;i > 0;i-=lowbit(i)){
//         ans += tr[i];
//     }
//     return ans;
// }
// void init(){
//     for (int i = 1;i <= n;i++)
//         for (int j = i - lowbit(i) + 1;j <= i;j++)
//             tr[i] += a[j];
// }
// int main(){
//     cin >> n >> m;
//     a.assign(n + 1,0);tr.assign(n + 1,0);
//     for (int i = 1;i <= n;i++)  cin >> a[i];
//     init();
//     for (int i = 0;i < m;i++){
//         int b,x,y;cin >> b >> x >> y;
//         if (b == 1){
//             add(x,y);
//         }
//         else if (b == 2){
//             cout << sum(y) - sum(x - 1) << '\n';
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int n,i,h,r;cin >> n >> i >> h >> r;
//     vector<int>a(n + 1,h),b(n + 2,0);
//     vector<vector<bool>>vis(n + 1,vector<bool>(n + 1,false));
//     for (int i = 0;i < r;i++){
//         int x,y;cin >> x >> y;
//         if (x > y)  swap(x,y);
//         if (vis[x][y] == false)
//             b[x + 1]--,b[y]++;
//         vis[x][y] = true;
//     }
//     for (int i = 1;i <= n;i++)  b[i] += b[i - 1];
//     for (int i = 1;i <= n;i++){
//         a[i] += b[i];
//         cout << a[i] << '\n';
//     }
//     return 0;
// }
// int main(){
//     int n,p;cin >> n >> p;
//     vector<int>a(n + 1,0),b(n + 2,0);
//     for (int i = 1;i <= n;i++)  cin >> a[i];
//     for (int i = 1;i <= p;i++){
//         int x,y,z;cin >> x >> y >> z;
//         b[x] += z;
//         b[y + 1] -= z;
//     }
//     for (int i = 1;i <= n;i++)  b[i] += b[i - 1];
//     int ans = 1e9;
//     for (int i = 1;i <= n;i++)  {
//         a[i] += b[i];
//         ans = min(ans,a[i]);
//     }
//     cout << ans;
//     return 0;
// }