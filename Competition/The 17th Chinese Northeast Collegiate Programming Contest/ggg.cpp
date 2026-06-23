#include<bits/stdc++.h>
using namespace std;

#define int long long

const int P = 998244353;

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
int a[N];
int E[N];
int p[N];

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int n;cin>> n;

    string s;cin >> s;s = ' ' + s;

    int t = qmi(100,P-2,P);

    for(int i=1;i<=n;i++)
    {
        a[i]=s[i]-'0';
    }

for(int i = 1; i < n; i++) cin >> p[i];

    p[n]=100;

    //cout<<300*t%P<<endl;

    int ans=0;

    int tp=1;
///  tmp = (q[p[i]] + 10 * q[100 - p[i]] % mod * tmp % mod) % mod;
    for(int i=n;i>=1;i--)
    {
        tp=(p[i]*t+10*(100-p[i])%P*t %P* tp%P)%P  ;
        ans+=a[i]*tp%P;
        ans%=P;
    }

    cout <<ans << '\n';



}
