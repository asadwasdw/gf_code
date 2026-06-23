// #include<iostream>
// #include<algorithm>
// #include<cmath>
// using namespace std;
// typedef pair<int,int>PII;
// const int N=1e6+10;
// const int mod=998244353;
// const int INF  = 0x3f3f3f3f;
// long long f[N];

// void init()
// {
//     f[1]=1;
//     long long zj=1;
//     for(int i=2;i;i++)
//     {
//         if(i%2==1)
//         {
//             f[i]=f[i-1]+zj;
//         }
//         else 
//         {
//             f[i]=f[i-1]+zj;
//             zj+=2;
//         }
//         if(f[i]>3e9)
//         {
//           //  cout<<i<<endl;
//             break;
//         }
//     }
// }

// int Zl(int k,int l,int r)
// {
//     while(l<r)
//     {
//         int mid=l+r>>1;
//         if(f[mid]>=k)r=mid;
//         else l=mid+1;
//     }
//     return l;
// }

// void solve()
// { 
//     int a, b;
//     cin>>a>>b;
//     if(a<b)swap(a,b);

//     long long l=Zl(a,0,77459);
//     //cout<<b<<endl;

    
//     while(1)
//     {
//         if(l*l>=b+a){
//             break;
//         }
//         l++;
//     }
//     cout<<l<<endl;

//   //for(int i=1;i<=20;i++)cout<<i<<" "<<f[i]<<endl;



// }



// signed main()
// {
//     init();
//     ios::sync_with_stdio(false);
//     /*多组案例初始化*/
//     int t;cin>>t;while(t--)
//     solve();
// }

////////////////////////////////////////

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int mx=max(a,b);
        int sum=mx*2;
        if(a!=b)sum--;
        int T=sqrt(sum);
        if(T*T==sum)
        {
            cout<<T<<endl;
        }
        else{
           cout<<T+1<<endl;;
        }

    }
}