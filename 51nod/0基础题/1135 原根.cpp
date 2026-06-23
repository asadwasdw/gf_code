#include<iostream>
#include<algorithm>
using namespace std;

typedef long long  ll;
const int N=5e5+10;
int P;
int yz[N];
int cnt=0;
void qyz(ll n)
{
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            yz[cnt]=i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1)yz[++cnt]=n;
}

ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}

bool check(int x)
{
    for(int i=1;i<=cnt;i++)
    {
        if(qmi(x,(P-1)/yz[i],P)==1)return false;
    }
    return true;
}

int solve()
{
    for(int i=2;i<=P;i++)
    {
        if(check(i))return i;
    }
    return 0;
}



int main()
{
    cin>>P;
    qyz(P-1);
    cout<<solve();
    return 0;
}