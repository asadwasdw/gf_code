#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N=1e6+10,MOD=1e9+7;

int ans[N];

int qmi(int a,int b,int p)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}

int p[N];
bool st[N];
int cnt;

void qie(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i]){
            p[cnt++]=i;
        }

        for(int j=0;i*p[j]<=n;j++)
        {
            st[i*p[j]]=true;
            if(i%p[j]==0)
            {
                break;
            }
        }
    }
}

int C[N];

void zys(int n)
{

    for(int j=0;j<cnt&&p[j]<=n;j++)
    {
        while(n%p[j]==0)
        {
           //cout<<n<<" "<<p[j]<<" "<<n%p[j]<<endl;
            C[p[j]]++;
            n/=p[j];
            C[p[j]]%=MOD;
        }
    }

    if(n>1)C[n]++;
}

signed main()
{
    //cout<<qmi(3,4,MOD)<<endl;

    int n;cin>>n;
    qie(n);

   // for(int i=1;i<=n;i++)zys(i);
   // cout<<p[0]<<endl;
    //cout<<C[2]<<endl;


    for(int i=0;i<cnt;i++)
    {
        int k=n;
        while(k)
        {
            C[p[i]]+=k/p[i];
            k/=p[i];
        }
    }






    int res=1;

    for(int i=2;i<=n;i++)
    {
        
            res*=2*C[i]+1;
            //cout<<C[i]<<" "<<p[i]<<endl;
        
        res%=MOD;
    }
  //  cout<<res<<endl;

    res=(res+1)*qmi(2,MOD-2,MOD)%MOD;
    cout<<res<<endl;

}