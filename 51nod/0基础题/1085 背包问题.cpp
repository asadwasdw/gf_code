#include<iostream>
#include<algorithm>

using namespace std;

const int N=10000;
long long f[N];
int w[N],v[N];


int main(){
    int n,W;
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=W;j>=v[i];j--)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }

    cout<<f[W]<<endl;

}