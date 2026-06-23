#include<iostream>
#include<algorithm>
#define int long long 
using namespace std;

int gcd(int a,int b)
{
    return (b?gcd(b,a%b):a);
}

const int N=5e6+10;

int phi[N];
int p[N];
int cnt;
bool st[N];
int ans[N];
void qie(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i]){
            p[cnt++]=i;
            phi[i]=i-1;
        }

        for(int j=0;p[j]*i<=n;j++){
            st[p[j]*i]=true;

            if(i%p[j]==0)
            {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
}

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j*i<=n;j++)
        {
            ans[i*j]+=i*phi[j];
        }
    }

    for(int i=1;i<=n;i++){
        ans[i]+=ans[i-1];
    }

}





signed main()
{
    qie(N-1);
    init(N-1);

    int n;cin>>n;

  

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        cout<<ans[x]<<endl;
    }

}