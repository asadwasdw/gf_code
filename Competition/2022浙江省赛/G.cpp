#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;
#define int long long
typedef pair<double, int>PII;
const int N = 1e4 + 10;
const int M = 2 * N;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
int qpow(int a, int k, int p) { int res = 1; while (k) { if (k & 1)res = res * a % p; a = a * a % p; k >>= 1; }return res; }
int C(int a, int b, int p) { if (b > a)return 0; int res = 1; for (int i = 1, j = a; i <= b; i++, j--) { res = res * j % p; res = res * qpow(i, p - 2, p) % p; }return res; }
//优先对列
//priority_queue <int,vector<int>,less<int> > q;//递减


PII a[N];
bool st[N];
double v1, v2;
int tx, ty, sx, sy;
int n;
double jl(double x1, double y1, double x2, double y2)
{
    double t = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
    // cout<<t<<endl;
    t = sqrt(t);
    // cout<<t<<endl;
    return t;
}

double djs()
{
    priority_queue <PII, vector<PII>, greater<PII> > q;

    for (int i = 0; i <= n; i++)
    {
        auto T = a[i];
        double t = jl(T.first, T.second, tx, ty) / v1;

        q.push({ t,i });
    }

    while (q.size())
    {
        auto T = q.top();
        q.pop();
        if (st[T.second])continue;
        st[T.second] = true;
        if (T.second == 0)
        {
            return T.first;
        }

        for (int i = 0; i <= n; i++)
        {

            if (st[i])continue;
            double D = jl(a[i].first, a[i].second, a[T.second].first, a[T.second].second);

            double t;
            if (D <= 3 * v2)
            {
                t = D / v2;
            }
            else t = 3 + (D - 3 * v2) / v1;

            q.push({ T.first+t,i });

        }

    }
    return -1;



}



void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y; cin >> x >> y;
        a[i] = { x,y };

    }

    cin >> tx >> ty >> sx >> sy;
    a[0] = { sx,sy };
    cin >> v1 >> v2;

    printf("%.12lf",djs());

}

signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
   // int t;cin>>t;while(t--)
    solve();
}