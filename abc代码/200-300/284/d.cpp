#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N =3e7+10;

typedef long long ll;

ll p[N];
bool st[N];
int cnt;

void prime()
{
    for(int i=2;i<N;i++)
    {
        if(!st[i])
        {
            p[cnt++]=i;
        }

        for(int j=0;p[j]*i<N;j++)
        {
            st[p[j]*i]=true;
            if(i%p[j]==0)break;
        }
    }
}



void solve()
{
    ll n;
    cin>>n;

    for(int j=0;j<=cnt;j++)
    {
        if(n%(p[j])==0)
        {
            n/=p[j];

            if(n%p[j]==0)
            {
                n/=p[j];
                cout<<p[j]<<" "<<n<<endl;
            }
            else 
            {
                cout<<(ll)sqrt(n)<<" "<<p[j]<<endl;
            }

            return ;

        }
    }

    return;

}

int main()
{

    prime();
    int t;cin>>t;while(t--)
    {
        solve();
    }


}