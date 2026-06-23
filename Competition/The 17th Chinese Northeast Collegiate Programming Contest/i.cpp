#include<bits/stdc++.h>
using namespace std;

const int N = 2000010;
int f[N][20];
string s;
int g[N];
signed main(){
    int n;cin>> n;
    cin>> s;
    for(int i=0;i<n;i++)cin>> g[i];
    f[0][s[0]-'0'] = s[0]-'0';
    
    for(int i=1;i<n;i++){
        
        for(int j=s[i]-'0';j<19;j++){
            f[i][j] += (f[i-1][(j-s[i]+'0')]*10+s[i]-'0')*g[i-1];
        }
    }
    int ans = 0;
    for(int i=0;i<19;i++)ans += f[n-1][i];
    cout<<ans;
}