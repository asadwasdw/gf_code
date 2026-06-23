#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

const int N=6e6+10;
int M=998244353;
int num[N];

typedef long long ll;

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



void solve()
{

   // cout<<qmi(3,2,M)<<endl;
    ll l=0;
    ll r=0;
    num[0]=1;
    ll a=1;
    int n;cin>>n;
    while(n--)
    {
        ll op,x;
        cin>>op;
        if(op==1){
            cin>>x;
            a=a*10+x;
            a%=M;
            r++;
           num[r]=x; 
          
        }
        else if (op==2) {
         
         ll t=qmi(10,r-l,M);
         //cout<<t<<endl;
         t*=num[l];
         l++;
         t%=M;
         a-=t;
         a=(a%M+M)%M;
        }
        else {
            cout<<a<<endl;
        }
       // cout<<a<<endl;
    }



}


int main()
{
   // int t;cin>>t;while(t--)
    solve();
}