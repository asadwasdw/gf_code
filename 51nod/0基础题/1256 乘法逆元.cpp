#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
int qmi(int a,int b,int p)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%p;
        a=(ll)a*a%p;
        b>>=1;
    }
    return res;

}

int main()
{
    long long n,m;
    cin>>m>>n;

    cout<<(m*n-(n-m)*m)/m<<endl;

    //cout<<qmi(a,b-2,b);
//     for(int i=0;i<n;i++)
//     {
//         if(i*m%n==1){
//             cout<<i<<endl;
//             return 0;
//         }
//     }
// }
}