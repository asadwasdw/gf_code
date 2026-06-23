#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
namespace AC {
    int tr[N][26], tot;
    int e[N], fail[N];

    void insert(char *s) {
        int u = 0;
        for (int i = 1; s[i]; i++) {
            if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;  // 如果没有则插入新节点
            u = tr[u][s[i] - 'a'];                              // 搜索下一个节点
        }
        e[u]++;  // 尾为节点 u 的串的个数
    }

    queue<int> q;

    void build() {
        for (int i = 0; i < 26; i++)
            if (tr[0][i]) q.push(tr[0][i]);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (tr[u][i]) {
                    fail[tr[u][i]] =
                        tr[fail[u]][i];  // fail数组：同一字符可以匹配的其他位置
                    q.push(tr[u][i]);
                } else
                    tr[u][i] = tr[fail[u]][i];
                }
        }
    }
    int query(char *t) {
        int u = 0, res = 0, r = 1, len = strlen(t + 1);
        for (int l = 1; t[l]; l++) {
            r = l;
            u = tr[u][t[l] - 'a'];  // 转移
            for (int j = u; j; j = fail[j]) {
                if (e[j]) {
                    res += l * (len - r + 1); 
                }
                r++;
            }
            
        }
        return res;
    }
}
char s[N], t[N];
void solve()
{

    int n, m;cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s + 1;
        AC::insert(s);
    }
    AC::build();
    for (int i = 1; i <= m; i++) {
        cin >> t + 1;
        cout << AC::query(t) << '\n';
    }




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}