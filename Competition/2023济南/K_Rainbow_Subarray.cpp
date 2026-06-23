#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
ll n,m;
int a[N];


void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> a[i], a[i] -= i;
    multiset<int> p1, p2;
    int cnt = 0;
    ll sum = 0;
    auto check = [&](){
        while(p1.size() > p2.size() || (p1.size() && p2.size() && *p1.rbegin() > *p2.begin())){
            int temp = *p1.rbegin();
            p2.insert(temp);
            p1.erase(p1.find(temp));
            sum += (ll)temp * 2;
        }
        while(p1.size() < p2.size()-1){
            int temp = *p2.begin();
            p1.insert(temp);
            p2.erase(p2.begin());
            sum -= (ll)temp * 2;
        }
    };
    auto add = [&](int x){
        p1.insert(x);
        sum -= x;
        check();
    };
    auto del = [&](int x){
        if(p1.find(x) != p1.end()){
            sum += x;
            p1.erase(p1.find(x));
        }
        else {
            sum -= x;
            p2.erase(p2.find(x));
        }
        check();
    };
    int res = 0;
    auto get = [&]() -> ll {
        ll mid = *p2.begin();
        return sum + mid * (p1.size() - p2.size());
    };
    for(int i=1,l=1; i<=n; ++i){
        add(a[i]);
        
        while(l <= i && get() > m){
            del(a[l]);
            ++l;
        }
        // cout << "pre_l" << ' ' << l << ' ';
        while(l - 1 >= 1){
            add(a[l - 1]);
            if(get() <= m)--l;
            else{
                del(a[l - 1]);
                break;
            }
        }
        // cout << get() << ' ' << l << endl;
        // for(auto it : p1)cout << it << ' ';cout << endl;
        // for(auto it : p2)cout << it << ' ';cout << endl;
        if(l <= i)
        res = max(res, i - l + 1);
    }
    cout << res << endl;






}


signed main()
{
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