#include<iostream>
#include<algorithm>

using namespace std;
#define int long long

const int N =3e6+10;
int s[N];
int num;
int gs[N];

signed main()
{
    int n,m,k;cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
    {
        char t;
        cin>>t;
        if(t=='o')s[i]=0;
        else {
            s[i]=1;
            num++;
        }
        gs[num]=i;
    }

    int ans=0;

    if(k==m*num)
    {
        cout<<m*n<<endl;
        return 0;

    }
    int tt=0;

   // for(int i=1;i<=num;i++)cout<<gs[i]<<" ";cout<<endl;

    int g=k/num;
    //cout<<g*n<<endl;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==1)
        {
            int t = k%num;
            
            int anst=g*n;
            tt++;

            if(tt+t>=num)
            {
                anst+=(n-i);
                if(g+1==m){

                }
                else {
                t-=num-tt;
                anst+=gs[t];
                }
            }
            else 
            {
                
                anst += gs[tt+t]-i;
               //cout<<gs[tt]<<" "<<i<<endl;
            }
            ans=max(anst,ans);
           // cout<<i<<" "<<anst<<endl;
        }
    }

    int anst = g * n;
    int t=k%num;
    ans=max(ans,anst+gs[k%num]);
    for(int i=n;i;i--)
    {
        if(s[i]==1)t--;
        if(t==-1)
        {
            ans=max(ans,n-i+anst);
            break;
        }
    }

    cout<<min(ans,n*m)<<endl;


}