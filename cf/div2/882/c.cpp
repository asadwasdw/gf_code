#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3100010;

int n, m;
int tr[N][2], cnt[N], idx;
int s[N];

void insert(int x, int v)
{
    int p = 0;
    for (int i = 10; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (!tr[p][u]) tr[p][u] = ++ idx;
        p = tr[p][u];
        cnt[p] += v;
    }
}

int query(int x)  // 查询Trie中与x异或和的最大值
{
    int res = 0, p = 0;
    for (int i = 10; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (cnt[tr[p][!u]]) p = tr[p][!u], res = res * 2 + 1;
        else p = tr[p][u], res *= 2;
    }
    return res;
}

void solve()
{
    scanf("%d", &n);
    m=n;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;
    }

    int res = 0;  // 空数组
    insert(s[0], 1);
    for (int i = 1; i <= n; i ++ )
    {
        if (i - m - 1 >= 0) insert(s[i - m - 1], -1);
        res = max(res, query(s[i]));
        insert(s[i], 1);
    }

    for(int i=0;i<=n*30;i++)
    {
        for(int j=0;j<2;j++)
        {
            tr[i][j]=0;
        }
        cnt[i]=0;
        //s[i]=0;
    }
    cout<<res<<endl;
    res=0;
      idx=0;


}

signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        solve();
    }
}

