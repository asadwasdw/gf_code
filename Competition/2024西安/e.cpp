#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[5010][5010];
int cd[N], cd2[N], cd3[N];



void solve()
{
    int n;
    cin >> n;
    int t1 = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            char t; cin >> t;
            a[i][j] = t - '0';
            cd[i] += a[i][j];
            if(cd[i] > cd[t1]) t1 = i;
        }
    }

    vector<int> S, T, S1;
    for(int i = 1; i <= n; i ++) {
        if(a[t1][i]) S.push_back(i);
        if(a[i][t1]) T.push_back(i);
    }

    if(T.size() == 0) {
        cout << "NOT FOUND\n";
        return;
    }

    int t2 = T[0];
    for(int i = 0; i < T.size(); i ++) {
        for(int j = 0; j < T.size(); j ++) {
            int x = T[i], y = T[j]; 
            cd2[x] += a[x][y];
            if(cd2[x] > cd2[t2]) t2 = x;
        }
    }
    

    for(auto t : S) {
        if(a[t][t2]) S1.push_back(t);
    }


    int t3 = S1[0];
    for(int i = 0; i < S1.size(); i ++) {
        for(int j = 0; j < S1.size(); j ++) {
            int x = S1[i], y = S1[j];
            cd3[x] += a[x][y];
            if(cd3[x] > cd3[t3]) t3 = x;
        }
    }

    cout <<  t1 << " " << t2  << " " << t3 << endl;

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