#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int,int>PII;
const int N=1e6+10;
const int M=2*N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
int qpow(int a,int k,int p){int res = 1;while(k){if(k&1)res = res*a%p;a = a*a%p;k>>=1;}return res;}
int C(int a,int b,int p){if(b>a)return 0;int res = 1;for(int i=1,j=a;i<=b;i++,j--){res = res*j%p;res = res*qpow(i,p-2,p)%p;}return res;}
//优先对列
//priority_queue <int,vector<int>,less<int> > q;//递减
//priority_queue <PII,vector<PII>,greater<PII> > q;//递增


void solve()
{
    int n;cin>>n;
    int ans=0;
    int g=0;
    int m=0;
    int wz=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x==1){
        wz++;
        }else{
            if(wz==0){}
            else if(wz%2==1)
            {
                if(g%2==0)
                {
                    g+=wz;
                }
                else if(m%2==0)
                {
                    m+=wz;           
                }
                else 
                {
                    m++;
                    g+=wz-1;
                    
                }
                
            }
            else{
                if(g%2==0)
                {
                    g++;
                    m+=wz-1;
                }
                else if(m%2==0)
                {
                    m++;
                    g+=wz-1;
                }
                else{
                    g+=wz;  
                }
               
            }
            wz=0;
        }
       // cout<<i<<" "<<ans<<endl;
        ans=max(ans,(g+1)/2+(m+1)/2+wz);

    }

    cout<<ans<<endl;

}

signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
  int t;cin>>t;while(t--)
    solve();
}