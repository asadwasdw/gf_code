#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n;
int f[N][3];
string t = "AEIOUY";
void solve()
{
    memset(f, 0x3f, sizeof f);
    cin >> n;
    string s;
    f[0][0] = 0;
    for(int i=1; i<=n; ++i){
        cin >> s;
        int pos = -1;
        for(int j=0; j<s.size()&&j<3; ++j){
            if(t.find(s[j]) != string::npos){
                pos = j;break;
            }
        }
        if(pos == -1){
            f[i][1] = f[i-1][0]+1;
            if(s.size() >= 2)
            f[i][2] = min({f[i-1][0]+2, f[i][2]});
            f[i][2] = min({f[i-1][1]+1, f[i][2]});
        }
        else{
            if(pos == 0){
                f[i][0] = min({f[i-1][0], f[i-1][1], f[i-1][2]}) + 1;
            }
            if(pos == 1){
                f[i][0] = min(f[i-1][0], f[i-1][1])+2;
                f[i][1] = (f[i-1][0] + 1);
                f[i][2] = f[i-1][1] + 1;
            }
            if(pos == 2){
                f[i][0] = f[i-1][0]+3;
                f[i][1] = f[i-1][0] + 1;
                f[i][2] = min(f[i-1][1] + 1, f[i-1][0] + 2);
            }
        }
        // cout << f[i][0] << ' ' << f[i][1] << ' '<< f[i][2] << endl;
        // cout << min({f[i][0], f[i][1], f[i][2]}) << endl;
    }
    int res = min({f[n][0], f[n][1], f[n][2]});
    if(res >= INF)cout << '*';
    else
    cout << res << endl;






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