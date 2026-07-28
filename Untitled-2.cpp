#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int mx = 0;
        vector<int>a(n,0),mp(n + 1,0);
        for (int i = 0;i < n;i++)   {
            cin >> a[i];
            if (mp[a[i]] == 0)  mx++;
            mp[a[i]] = 1;
        }
        for (int i = 0;i < n;i+=mx){
            vector<int>aa(n + 1,1);
            aa = mp;
            for (int j = i;j < min(n,i + mx);j++){
                if (aa[a[j]] == 1) cout << a[j] << ' ',aa[a[j]] = 0;
            }
            for (int j = 1;j <= min(n,n - i + 1);j++) if (aa[j] == 1) cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}