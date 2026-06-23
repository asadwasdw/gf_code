#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int l = 1, r = 0, now = 0; //每个位置的数值、每个数值的计数器、左指针、右指针、当前统计结果（总数）

priority_queue<int> q1; // 大
priority_queue<int,vector<int>, greater<int>> q2;

map<int,int> cnt;

void ph() {
    

}

void add(int pos) {//添加一个数

}

void del(int pos) {//删除一个数

}
void work() {//优化2主过程
    for(int i = 1; i <= q; ++i) {//对于每次询问
        int ql, qr;
        scanf("%d%d", &ql, &qr);//输入询问的区间
        while(l < ql) del(l++);//如左指针在查询区间左方，左指针向右移直到与查询区间左端点重合
        while(l > ql) add(--l);//如左指针在查询区间左端点右方，左指针左移
        while(r < qr) add(++r);//右指针在查询区间右端点左方，右指针右移
        while(r > qr) del(r--);//否则左移
        printf("%d\n", now);//输出统计结果
    }
}

void solve()
{







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}