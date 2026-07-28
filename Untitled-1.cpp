#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n),mp(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]] = 1;
        }
        for (int i = 0; i < n; ++i) {
            if (mp[a[i]] == 1) {
                 cout << a[i] << " ";
                 mp[a[i]] = 2;
            } 
        }
        for (int i = 1;i <= n;i++){
            if (mp[i] == 0) {
                cout << i << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}