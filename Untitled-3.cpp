#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (st.count(a[i])) {
            cout << a[i] << " ";
            st.erase(a[i]);
        } else {
            cout << *st.begin() << " ";
            st.erase(st.begin());
        }
    }
    cout << "\n";
    }
    return 0;
}