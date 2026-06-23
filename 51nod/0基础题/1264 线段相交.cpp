#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


struct Point{ //点 
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	Point operator -(const Point &a)const //定义向量减 
	{
		return Point(x-a.x,y-a.y);
	}
	double operator ^(const Point &a)const//定义向量叉积 
	{
		return x*a.y-y*a.x;
	}
};
 
//判断直线p1p2与直线p3p4是否相交 
bool cross(const Point &p1,const Point &p2,const Point &p3,const Point &p4) 
{
	//判断向量p1p2是否跨立向量p3p4 
	double a1=(p2-p1)^(p3-p2);//计算向量p1p2与向量p2p3的叉积 
	double a2=(p2-p1)^(p4-p2);//计算向量p1p2与向量p2p3的叉积 
	if(a1*a2>0)
	  return false;
	return true;
}


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
         double x1,y1,x2,y2,x3,y3,x4,y4;
         cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    Point A={x1,y1};
    Point B={x2,y2};
    Point C={x3,y3};
    Point D={x4,y4};

    if(cross(A,B,C,D)&&cross(C,D,A,B))
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    }
   

}