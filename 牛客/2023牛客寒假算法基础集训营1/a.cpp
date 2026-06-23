#include<iostream>
#include<algorithm>

using namespace std;
void solve()
{
    string s;
    cin>>s;
    int fsA=0,fsB=0;
    int A=5,B=5;
    for(int i=0;i<10;i++)
    {

        if(i%2==0)A--;
        else B--;

        if(s[i]=='1')
        if(i%2==0)fsA++;
        else fsB++;

        if(A+fsA<fsB||B+fsB<fsA){
            cout<<i+1<<endl;
            return;
        }

    }

    cout<<"-1"<<endl;
}
int main()
{
    int t;cin>>t;while(t--)
    solve();

}