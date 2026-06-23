#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

map<long long,bool>st;
map<long long,long long>ans;

long long cz(long long x)
{
    if(ans[x]==0)ans[x]=x;

    long long t=ans[x];

    while(1)
    {
        if(!st[t]){
            break;
        }
        t+=x;
    }
    ans[x]=t;
    return t;
}

int main()
{
    int n;cin>>n;
    while(n--)
    {
        char c;
        long long x;
        cin>>c>>x;
        if(c=='+'){
            st[x]=true;
        }
        else{
            cout<<cz(x)<<endl;
        }
    }

}