#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e5+10;
typedef long long ll;

ll qmi(ll a,ll b,ll p){

}

ll P[N],M[N];

int main()
{
    int n;cin>>n;
    ll W=1;
    for(int i=1;i<=n;i++)
    {
        cin>>P[i]>>M[i];
        W*=P[i];
    }

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        //ans+=M[i]*(W/P[i  ])
    }





}