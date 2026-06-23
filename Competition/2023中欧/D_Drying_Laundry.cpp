#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

bitset<N>f;

struct sheet{
    ll d, s, f;

}a[N];
bool operator < (sheet a,sheet b){
    return a.s < b.s; 
}

int cnt, t[N],l[N];

// bool cmp(sheet a,sheet b) {
//     return a.s < b.s;
// }
ll mxf[N],sumd[N];
map<int,int>mp;
void update(int f,int d) {
    if(mp[f] != 0) mp[f] = min(mp[f],d);
    else mp[f] = d;
}

void solve()

{
    int n,q ;
    cin >> n >> q;

    for(int i = 1; i <= n ;i ++) {
        cin >> a[i].d >> a[i].f >> a[i].s;
    } 
    sort(a+1,a+n+1);// 按单根绳子 从小到大排序，

    for(int i = n; i ; i --) {
        mxf[i] = max(mxf[i + 1], a[i].f);// 计算第i个床单到最后一个床单晒双绳的最大时间
        sumd[i] = sumd[i + 1] + a[i].d;  // 计算双绳长度和
        // cout << i << ' ' << mxf[i] << ' ' << sumd[i] << endl;
    }

    update(mxf[1],sumd[1]);// 所有床单都上双绳
    // [x,y] 记录花费x时间的最小长度y

    f.set(0); // 和为0的组合一定存在
    // f(x) 如果此位为1,代表此时存在一个组合，他们的d的和为x
    int tot = 0;

    for(int i = 1; i <= n; i++) {
        tot += a[i].d;// 目前位置，用单绳的总长度
        f |= (f << a[i].d);
        int st = (tot+1)/2;
        while(f.test(st) == 0) st ++;// 找到最小满足条件的x
        update(max(a[i].s,mxf[i+1]),st + sumd[i + 1]);// 更新[x,y]
    }

    for(auto [_t,_l] : mp) {
        ++cnt;
        t[cnt] = _t;
        l[cnt] = _l;
    }

    l[++cnt] = INF;
    reverse(t+1,t+cnt+1);
    reverse(l+1,l+cnt+1);
    // for (int i=1;i<=cnt;++i) cout<<t[i]<<' '<<l[i]<<endl;
    t[0] = -1;
    while(q --) {
        int x;
        cin >> x;
        int L = 1, R = cnt;
        int ans = -1;
        // if(x >= l[1]) {
            int T = upper_bound(l+1,l+cnt+1,x) - l - 1;
            ans = t[T];
        // }
        cout << ans << endl;
    }
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