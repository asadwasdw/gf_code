#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p = 998244353;
int qmi(int a,int b,int p){
    int res = 1;
    while(b){
        if(b&1)res = res*a%p;
        a = a*a%p;
        b>>=1;
    }
    return res;
}
const int N = 2000010;

int g[N];
int f[2][20];

signed main(){
    int n;cin>> n;
    string s;cin>> s;
    for(int i=1;i<n;i++){
        cin>> g[i];
    }
    f[0][s[0]-'0'] = s[0]-'0';
    int t = qmi(100,p-2,p);
    for(int i=1;i<n;i++){
        int k = 0;
        for(int j=s[i]-'0';j<19;j++){
            if(f[i-1&1][j-s[i]+'0'])
            f[i&1][j] += (j+f[i-1&1][0]*10) * g[i]*t%p;
        }
        for(int j=0;j<19;j++)k+=f[i-1&1][j]*(100- g[i])*t%p;
        f[i&1][s[i]-'0'] += k*10%p+s[i]-'0';
        f[i&1][s[i]-'0']%=p;
    }
    int ans = 0;
    for(int i=0;i<19;i++){
        ans+=f[n-1&1][i];
        ans %=p;
    }
    cout<<ans;

}