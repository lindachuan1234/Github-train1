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
    for (int i = k - 1;i >= 0;i--){
        string rr,r;
        for (int j = 0;j < b[i].size();j++) r += b[i][j];
        for (int z = i - 1;z >= 0;z--){
            r = "";rr = "";
            for (int j = 0;j < b[i].size();j++) r += b[i][j];
            for (int j = 0;j < b[z].size();j++) rr += b[z][j];
            if (r == rr){
                string z1,z2;//z1在后面
                bool flag = true;
                for (int j = 0;j < a[z].size();j++){
                    if (flag == false) {
                        z1 += b[i][j];
                        z2 += b[z][j];
                    }
                    else if (a[i][j] == a[z][j]){
                        z1 += a[i][j];
                        z2 += a[z][j];
                        b[i][j] = a[i][j];
                        b[z][j] = a[z][j];
                    }
                    else if (a[i][j] != a[z][j]) 
                    {
                        z1 += a[i][j];
                        z2 += a[z][j];
                        b[i][j] = a[i][j];
                        b[z][j] = a[z][j];
                        flag = false;
                    }
                }
                r = z1;rr = z2;
            }
        }
        ans.push_back(r);
    }
    for (int i = ans.size() - 1;i >= 0;i--) {
        cout << ans[i] << '\n';
    }
    return 0;
}