#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

bool st[N];
int pri[N];
int cnt;

void qie_p(int n)
{
    st[1] = 1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])pri[cnt++]=i;
        
        for(int j=0;i*pri[j]<=n;j++)
        {
            st[pri[j]*i]=true;
            if(i%pri[j]==0)
            {
                break;
            }
        }
    }
    
}

void solve()
{

    int n, k;
    cin >> n >> k;
    vector<int>a(n + 10), s(n + 10);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    if(2 * k > n) {
        cout << "impossible\n";
        return;
    }


    auto check = [&](int mid) -> bool {
        int last = 0;
        int cur = 0;
        for(int i = 1; i <= k; i ++) {
            // cout << i << endl;
            set<PII> ST;
            ST.insert({s[last], last});

            for(int i = cur + 1; i <= n; i ++) {
                for(auto [w, id] : ST) {
                    if(s[i] - w < mid)break;

                    if(!st[i - id]) {
                        // cout << last << " " << id + 1 << " " << i << endl;
                        cur = i;
                        break;
                    }
                }
                if(cur != last) break;
                ST.insert({s[i], i});
            }

            if(cur == last) return false;
            last = cur;
        }
        return true;
    };


    // for(int i = 0; i <= 10; i ++) {
    //     cout << i << " " << st[i] << endl;
    // }

    // cout << check(-3);
    // cout << check(-2); cout << endl;
    // cout << check(-5);
    // cout << check(-6);
    // cout << check(-7);
    // cout << check(-8); cout << endl;
    // cout << check(-9);

    ll l = -1e4, r = 1e6+1;
    while(l < r) {
        ll mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    if(l == -1e4) cout << "impossible\n";
    else {
        cout << l << endl;
    }
}


signed main()
{
    qie_p(2e5+1);
    // cout << p.size() << endl;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}