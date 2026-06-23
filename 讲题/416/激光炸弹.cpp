#include <iostream>
using namespace std;

const int N=5009;
int a[N][N],s[N][N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y,v;
        cin>>x>>y>>v;
        a[x][y]+=v;
    }
    for(int i=1;i<=5000;i++){
        for(int j=1;j<=5000;j++){
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    int mx=-1e8;
    for(int i=m;i<=5000;i++){
        for(int j=m;j<=5000;j++){
            if(mx<s[i][j]-s[i-m][j]-s[i][j-m]+s[i-m][j-m])mx=s[i][j]-s[i-m][j]-s[i][j-m]+s[i-m][j-m];
        }
    }
    cout<<mx;
    return 0;
}