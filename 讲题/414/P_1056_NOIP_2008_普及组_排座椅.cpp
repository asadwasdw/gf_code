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
#define x first
#define y second
PII a[N];
PII b[N];

bool cmp(PII a, PII b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void solve()
{
    int M,N,K,L,D;
    cin >> M >> N >> K >> L >> D;

    for(int i = 1; i <= N; i ++) a[i].y = i;
    for(int i = 1; i <= M; i ++) b[i].y = i;

    for(int i = 1; i <= D; i ++) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) {
            a[min(y1,y2)].x++;
        }
        else if(y1 == y2) {
            b[min(x1,x2)].x++;
        }
    }


    sort(a + 1, a + N + 1,cmp);
    sort(b + 1, b + M + 1,cmp);
    vector<int>ansa,ansb;


    for(int i = 1; i <= M; i ++) {
        if(ansb.size() < K) {
            ansb.push_back(b[i].y);
        }
    }

    for(int i = 1; i <= N; i ++) {
        if(ansa.size() < L) {
            ansa.push_back(a[i].y);
        }
    }

    sort(ansb.begin(),ansb.end());
    sort(ansa.begin(),ansa.end());
    
    for(auto t : ansb) cout << t << ' ';cout << endl;
    for(auto t : ansa) cout << t << ' ';cout << endl;
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