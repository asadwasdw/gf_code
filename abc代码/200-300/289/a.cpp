#include<iostream>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;

const int N=15;
int a[N];
long long n,m;

void solve()
{

    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        int tt=0;

        set<int>s;
        s.clear();
        for(int j=1;j<=num;j++)
        {
            int t;
            cin>>t;      
            int z=s.size();
            s.insert(t);
            if(s.size()==z)continue;
            tt+=(1<<(t-1));
        }

        a[i]=tt;
    //   cout<<i<<" "<<a[i]<<endl;

    }
    int ans=0;
    for(int i=0;i<(1<<m);i++)
    {
        int t=0;
        for(int j=0;j<m;j++){
            if(i>>j&1){
                t|=a[j];
            }
        }
        if(t==pow(2,n)-1){

         //  cout<<i<<" "<<pow(2,n)-1<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;


 
    
}


int main()
{
    //int t;cin>>t;while(t--)
    solve();
}