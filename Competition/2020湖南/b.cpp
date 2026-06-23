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
string s[N];

void solve()
{
    int n,m;
    while(cin >> n >> m){
        for(int i=1; i<=n; ++i)cin >> s[i], s[i] = " " + s[i];
        int res = 0;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i][j] == 'o'){
                    int k = j, f = 1;
                    while(k <= m && s[i][k] == 'o'){
                        if((i-1 < 1 || s[i-1][k] == '.') && (i+1 > n || s[i+1][k] =='.')){
                            ++k;
                        }
                        else{
                            ++k;
                            f = false;break;
                        }
                        
                    }
                    if(f && (j-1 < 1 || s[i][j-1] == '.') && (k > m || s[i][k] == '.')){
                        res = 1;break;
                    }
                    j = k;
                }
            }
            if(res)break;
        }
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(s[j][i] == 'o'){
                    int k = j, f = 1;
                    while(k <= n && s[k][i] == 'o'){
                        if((i-1 < 1 || s[k][i-1] == '.') && (i+1 > m || s[k][i+1] =='.')){
                            ++k;
                        }
                        else{
                            ++k;
                            f = false;break;
                        }
                        
                    }
                    if(f && (j-1 < 1 || s[j-1][i] == '.') && (k > n || s[k][i] == '.')){
                        res = 1;break;
                    }
                    j = k;
                }
            }
        }
        if(res){
            cout << "2018\n";
        }
        else cout << "2020\n";
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