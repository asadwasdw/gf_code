#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;


int getol(int n)
{
    ll res=n;
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            res=res*(i-1)/i;
            while(n%i==0)n/=i;
        }
    }

    if(n>1){
        res=res*(n-1)/n;
    }

    return res;
}



int main()
{
    int n;cin>>n;
    cout<<getol(n);

}
