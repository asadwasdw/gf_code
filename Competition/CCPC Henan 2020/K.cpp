#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int P=131,MOD=20000311,N=5e5+10;
int n;
char S[N];

long long p[N],hq[N],hh[N];
 long long get1(int l,int r)
{
    return (((hq[r]-(hq[l-1]*p[r-l+1])%MOD)%MOD+MOD)%MOD);
}

long long get2(int L,int R)
{
   // cout<<n<<endl;
    int l=n-R+1;
    int r=n-L+1;
   // cout<<l<<" "<<r<<endl;
    return  (((hh[r]-(hh[l-1]*p[r-l+1])%MOD)%MOD+MOD)%MOD);
}



void solve()
{
    
    scanf("%s",S+1);

    int r=strlen(S+1);
    int l=1;


    while(1)
    {
        if(l<=r&&S[l]==S[r])
        {
            l++;
            r--;
        }
        else break;
    }
  

    if(l>=r){
         printf("Yes\n");
        return;
    }
    n=r-l+1;

    for(int i=1;i<=n;i++)
    {
        hq[i]=hq[i-1]*P%MOD+S[l+i-1];
        hq[i]%=MOD;
    }

    for(int i=1;i<=n;i++)
    {
        hh[i]=hh[i-1]*P%MOD+S[r-i+1];
        hh[i]%=MOD;
    }



    for(int i=2;i<n;i++)
    {
       long long t1=get2(1,i)*p[n-i]%MOD+get1(i+1,n);

        long long t2=get2(i+1,n)*p[i]%MOD+get1(1,i);
        
         t1%=MOD;
        t2%=MOD;

        if(t1==t2)
        {
             printf("Yes\n");
            return;
        }
    }



    for(int j=n-1;j>1;j--)
    {
        long long t1=get1(1,j-1)*p[n-j+1]%MOD+get2(j,n);

        long long t2=get1(j,n)*p[j-1]%MOD+get2(1,j-1);

        t1%=MOD;
        t2%=MOD;
        if(t1==t2)
        {
          printf("Yes\n");
            return;
        }
    }
     printf("No\n");

}
int main()
{

    
    p[0]=1;
    for(int i=1;i<=N;i++)p[i]=(p[i-1]*P)%MOD;
    int t;scanf("%d\n",&t);while(t--)
    solve();
}