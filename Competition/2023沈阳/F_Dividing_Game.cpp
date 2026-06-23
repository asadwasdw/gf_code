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

bool st[N];
int pri[N];
int cnt;

void qie_p(int n)
{
    st[1] = false;
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

set<int> s[N];
int sg[N];

void init() {
    for(int i = 1; i <= 1e5; i ++) {

        int cnt = 0;
        while(s[i].find(cnt) != s[i].end()) cnt++;
        sg[i] = cnt;


        for(int k = 1; k * i <= 1e5; k ++) {
            s[k * i].insert(sg[i]);
        }
    
    }
}



void solve()
{
    qie_p(2e5 + 10);
    init();
    // for(int i = 1; i <= 100; i ++) {
    //     cout << st[i] << " " << i << endl;
    // }

    int ans = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        ans ^= sg[x];
    }
    if(ans) cout << "Anna";
    else cout << "Bruno";






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