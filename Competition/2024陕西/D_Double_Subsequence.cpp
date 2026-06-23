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
string s,s1,s2;
ll f[2][30][30];

void solve()
{
    cin >> s >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    s = " " + s;
    int t = 0;
    // if(s1[1] == s[0] && s2[1] == s[0])f[t][1][1] ++;
    // else if(s1[1] == s[0])f[t][1][0] ++;
    // else if(s2[1] == s[0])f[t][0][1] ++;
    ll ans = 0;
    for(int i=1; i<s.size(); ++i){
        t ^= 1;
        for(int i=0; i<s1.size(); ++i)for(int j=0; j<s2.size(); ++j)f[t][i][j] = f[t^1][i][j];
        for(int j=1; j<s1.size(); ++j){
            for(int k=1; k<s2.size(); ++k){
                
            }
        }
        
        
        
        
        for(int j=1; j<s1.size(); ++j){
            if(s[i] == s1[j]){
                for(int k=0; k<s2.size(); ++k){
                    if(k == 0 && j == 1)f[t][j][k] += i;
                    else
                    f[t][j][k] += f[t^1][j-1][k];
                }
            }
        }
        for(int j=1; j<s2.size(); ++j){
            if(s[i] == s2[j]){
                for(int k=0; k<s1.size(); ++k){
                    if(k == 0 && j == 1)f[t][k][j] += i;
                    else
                    f[t][k][j] += f[t^1][k][j-1];
                }
            }
        }
        for(int j=1; j<s1.size(); ++j){
            for(int k=1; k<s2.size(); ++k){
                if(s1[j] == s2[k] && s1[j] == s[i]){
                    f[t][j][k] += f[t^1][j-1][k-1];
                }
            }
        }
        // for(int j=0; j<s1.size(); ++j){
        //     for(int k=0; k<s2.size(); ++k){
        //         cout << f[t][j][k] << ' ';
        //     }cout << endl;
        // }cout << endl;
        cerr << f[t][s1.size()-1][s2.size()-1] << ' ';
        ans += f[t][s1.size()-1][s2.size()-1] * (s.size()-1 - i + 1);
    }
    cout << ans << endl;






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