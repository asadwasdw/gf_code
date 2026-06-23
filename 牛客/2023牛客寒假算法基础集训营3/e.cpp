#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

#define int long long

typedef pair <int,int> PII;

void solve()
{
    PII a,b;

    int A,B,C,D;
    cin>>A>>B>>C>>D;

    a={A,B};
    b={C,D};

    if(A>C)swap(a,b);
    PII ans;
    int h,l;
    if(a.second>=b.second){
        h=b.first-a.first;
        l=a.second-b.second;

       ans={a.first- l,a.second - h };
    }
    else 
    {
        h=b.first-a.first;
        l=b.second-a.second;
        ans={a.first+l,a.second-h};
    }



    if((ans.first+b.first)%2==0&&(ans.second+b.second)%2==0){
    cout<<(ans.first+b.first)/2<<" "<<(ans.second+b.second)/2<<endl;
    return ;
    }
    

   if(a.second>=b.second){
        h=b.first-a.first;
        l=a.second-b.second;

       ans={a.first + l,a.second + h };
    }
    else 
    {
        h=b.first-a.first;
        l=b.second-a.second;
        ans={a.first-l,a.second+h};
    }

    
    if((ans.first+b.first)%2==0&&(ans.second+b.second)%2==0){
    cout<<(ans.first+b.first)/2<<" "<<(ans.second+b.second)/2<<endl;
    return ;
    }

    cout<<"No Answer!"<<endl;
    



    
}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}