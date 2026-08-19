#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    vector<string>a[25];
    vector<string>b[25];
    vector<string>ans;
    int t;cin >> t;
    int k = t;
    getchar();
    int cnt = 0;
    while(t--){
        string ret;
        while(1){
            char c = getchar();
        if (c == '\n')  {
            a[cnt].push_back(ret);
            string r = ret.substr(0,1);
            b[cnt].push_back(r);
            cnt++;
            break;
        }
        if (c == ' ')   {
            a[cnt].push_back(ret);
            string r = ret.substr(0,1);
            b[cnt].push_back(r);
            ret = "";
            continue;
        }
        ret += c;
        }
    }
    vector<bool>one(k + 1,false);
    for (int i = 0;i < 20;i++) {
        for (int j = 0;j < k;j++) {
            if (one[j]) continue;
            if (a[j].size() - 1 >= i) {
                bool flag = false;
                for (int z = j + 1;z < k;z++){
                    if (a[z].size() - 1 < i)    continue;
                    if (a[z].size() != a[j].size()) continue;
                    string reg,regg;
                    for (int jjj = 0;jjj < a[z].size();jjj++){
                        regg += b[j][jjj];
                        reg += b[z][jjj];
                    }
                    if (regg != reg)    continue;
                    if (b[z][i] == b[j][i]) {
                        b[z][i] = a[z][i];
                        flag = true;
                    }
                }
                if (flag)   {
                    b[j][i] = a[j][i];
                }
                bool ff = false;
                for (int z = j + 1;z < k;z++) {
                    if (a[z].size() - 1 < i)    continue;
                    if (b[j][i] == b[z][i]) {
                        ff = true;
                        break;
                    }
                }
                if (ff == false)    one[j] = true;
            }
        }
    }
    for (int i = 0;i < k;i++) {
        string r = "";
        for (int j = 0;j < b[i].size();j++) {
            r += b[i][j];
        }
        cout << r << '\n';
    }
    return 0;
}