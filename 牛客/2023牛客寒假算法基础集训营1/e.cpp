#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

typedef pair <double,double>PII;

double len(PII x)
{
    return sqrt(x.first*x.first+x.second*x.second);
}

PII js(double x1,double y1,double x2,double y2){
    return {x2-x1,y2-y1};
}

void sc(PII x){
    cout<<x.first<<" "<<x.second<<endl;
}

double XC(PII x,PII y)
{
   // sc(x);sc(y);
    return (x.first*y.second)-(y.first*x.second);
}



void solve()
{
    double xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    double xd,yd,xe,ye,xf,yf;

    cin>>xd>>yd>>xe>>ye>>xf>>yf;

    PII BA,BC,ED,EF;

    BA=js(xb,yb,xa,ya);
    BC=js(xb,yb,xc,yc);
    ED=js(xe,ye,xd,yd);
    EF=js(xe,ye,xf,yf);

  //  sc(ED);

    double ba,bc,ed,ef;
    ba=len(BA);
    bc=len(BC);
    ed=len(ED);
    ef=len(EF);
    if(bc==ba){
        cout<<"NO"<<endl;
        return;
    }

   // printf("%lf %lf %lf %lf\n",ba,bc,ed,ef);

    double fx1,fx2;
    if(ba<bc)fx1=XC(BA,BC);
    else fx1=XC(BC,BA);

    if(ed<ef){
        fx2=XC(ED,EF);
    }
    else fx2=XC(EF,ED);

   // cout<<fx1<<" "<<fx2<<endl;
    if(fx1*fx2<0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

   // XC(EF,ED);

    
}


int main()
{
    int n;cin>>n;while(n--)
    solve();
}