#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;

    for(int i=1;i<=n;i++)
    {
        char A,B;
        cin>>A>>B;

        if(A=='Y'){
            cout<<"Y";
            a--;b++;
        }
        else if(b==0){
            cout<<"Y";
            a--;b++;
        }
        else cout<<"N";

        cout<<" ";

        if(B=='Y'){
          cout<<"Y";
          b--;a++;
        }
        else if(a==0){
            cout<<"Y";
            b--;a++;
        }
        else cout<<"N";

        cout<<endl;

    }
}