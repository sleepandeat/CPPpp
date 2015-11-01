
#include<iostream.h>
#include<stdlib.h>
double fuc(double x,double y)
{
	if(y==0)
	{
		throw y;
	}
	return x/y;
}
int main()
{
	double res;
	try
	{
		res=fuc(235,46);
		cout<<"the result of x/y is:"<<res<<endl;
		res=fuc(19,0);
	}
	catch(double)
	{
		cerr<<"被除数不能为0，请修改输入值！.\n";
		exit(1);
	}
	return 0;
}