#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];

priority_queue<int> q[N];
int prime[N], idx;
int st[N];
void init(){
    for(int i=2; i<N; ++i){
        if(!st[i])prime[++idx] = i, st[i] = i;
        for(int j=1; j<=idx && 1ll*i*prime[j]<N; ++j){
            st[i*prime[j]] = prime[j];
            if(i % prime[j] == 0)break;
        }
    }
}

void solve()
{
    cin >> n;
    set<int> p;
    ll res = 0;
    int cnt = 0;
    for(int i=1,x; i<=n; ++i){
        cin >> x;
        if(x == 1)res++;
        else{
            ++cnt;
            map<int, ll> mp;
            while(st[x]){
                if(!mp.count(st[x]))mp[st[x]] = st[x];
                else (mp[st[x]] *= st[x]) %= mod;
                x /= st[x];
            }
            for(auto &[x, y] : mp)q[x].push(y),p.insert(x);
        }
    }
    // for(auto it : p){
    //     cout << it << ' ';
    //     while(q[it].size()){
    //         cout << q[it].top() << ' ';
    //         q[it].pop();
    //     }cout << endl;
    // }
    vector<int> pp;
    while(p.size()){
        ll cur = 1ll;
        for(auto it : p){
            (cur *= q[it].top()) %= mod;
            q[it].pop();
            if(q[it].empty())pp.push_back(it);
        }
        while(pp.size())p.erase(pp.back()), pp.pop_back();
        (res += cur) %= mod;
        --cnt;
    }
    cout << (res + cnt) % mod << endl;
    






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    init();
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}