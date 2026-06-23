#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int f[N][N];

int main()
{
    string a;
    cin >> a;
    int n = a.size(); 
    int m = n;
    string b = a;
    reverse(a.begin(), a.end());
    a = " " + a;
    b = " " + b;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    
    cout<<f[n][m];
}