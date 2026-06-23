#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N=1e5+10,M=998244353;

ll n,m,k;
ll tr[N];
ll B[N];
ll fact[N], infact[N];

int lowbit(int x)
{
    return x&-x;
}

void add(int x,int c)
{
    for(int i=x;i<=m;i+=lowbit(i))tr[i]+=c;
}

int sum(int x)
{

    int res=0;

    for(int i=x;i;i-=lowbit(i))res+=tr[i];

    return res;

}

ll qmi(ll a,ll b)
{ 
    ll c=998244353;
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%c;
        a*=a;
        a%=c;
        b>>=1;
    }

    return res;
}


ll C(int y,int x)
{
    return (y>=x&&x>=0?  fact[y]*infact[x]%M*infact[y-x]%M :0);
}

void init()
{
    
    fact[0]=infact[0]=1;
    
    for(int i=1;i<N;i++)
    {
        fact[i]=fact[i-1]*i%M;
      // infact[i]=infact[i-1]*qmi(i,M-2,M)%M;

    }

    infact[N-1]=qmi(fact[N-1],M-2)%M;
    for(int i=N-2;i>=0;i--)
    {
        infact[i]=infact[i+1]*(i+1)%M;
    }


}



int main()
{
    cin>>n>>m>>k;
    init();
    int cnt0=0;
    for(int i=1;i<=n;i++)
    {

        int x;cin>>x;
       // cout<<i<<" "<<x<<endl;
        if(x)add(x,1);
        else cnt0++;
    }



    ll cnt=sum(m);
    //cout<<cnt<<endl;
    for(int i=1;i<=m;i++)
    {
        int cnt1=cnt-sum(i-1);
        //cout<<i<<" "<<cnt1<<endl;

        if(n-k+1<=cnt1){
            B[i]=1;
        }
        else 
        {
            if(cnt0<n-k+1-cnt1)
            {

                B[i]=0;
             
            }
            else 
            {
                ll p=((m-i+1)%M*qmi(m,M-2)%M)%M;
                
                ll pn=qmi(p,M-2)%M;

                for(int j=n-k+1-cnt1;j<=cnt0;j++)
                {
                    
                    B[i]+=C(cnt0,j)*qmi(p,j)%M*qmi(1+M-p,cnt0-j)%M;
                    

                    B[i]%=M;

                }
               // if(i==3)cout<<B[i]<<endl;

            }
        }

    }

    ll ans=0;

    cout<<C(1,1)<<endl;


   // cout<<3*qmi(5,M-2)%M<<endl;
    
    for(int i=1;i<=m;i++)
    {
      //  cout<<B[i]<<endl;
        ans=(ans+B[i])%M;
    }

   cout<<ans<<endl;



   
}