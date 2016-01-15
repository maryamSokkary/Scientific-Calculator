#include <iostream>
#include <windows.h>
#include <sstream>
 
using namespace std;
 
double M;
bool flag = 0;
 
double abs(double x){
	if(x<=0)
	    x=0-x;
	return x;
}
 
long long factorial(int x){
	long long fact=1;
    while(x>=1){
    	fact=fact*x;
    	x=x-1;
    }
    return fact;
}
 
double pow(double base,double power){
	double z=1;
	for(int i=0;i<power;i++)
		z=z*base;
	return z;
}
 
double exp (double x){
	double sum=0;
	for(int i=0;i<15;i++)
		sum+=pow(x,i)/factorial(i);
	return sum;
}
 
double sin (double x){ //take in angle
	while (x>360)
		x-=360;
	bool negative =0;
	if (x<0){
		x=abs(x);
		negative=1;
	}
	if (x>90 && x<=180)
		x=180-x;
	else if (x>180 && x<=270){
		x-=180;
		negative =1;
	}
	else if (x>270 && x<=360){
		x=360-x;
		negative=1;
	}
 
	x=x*3.14159/180;
	double sum=0;
	for (int i=0; i<15; i++)
		sum+=pow(-1,i)*pow(x,2*i+1)/factorial(2*i+1);
	if (negative)
	return sum*-1;
	else return sum;
}
 
double cos (double x){ //take in angle
	while (x>360)
		x-=360;
	if (x<0)
		x= abs (x);
	if (x>90 && x<=180)
		return (sin(90-x));
	else if (x>180 && x<=270)
		return (sin(x-270));
	else if (x>270 && x<=360)
		x=360-x;
	x=x*3.14159/180;
	double sum=0;
	for (int i=0; i<15; i++)
		sum+=pow(-1,i)*pow(x,2*i)/factorial(2*i);
	return sum;
 
}
 
double tan (double x){
	if (x==90 || x== 270)
		flag =1;
 
	return sin(x)/cos(x);
}
 
double asin (double x){
    double sum=0;
    if(x<-1||x>1){//Math error
             flag=1;
    }
    if(x==1)
        return 90;
    else if (x==-1)
        return -90;
    else
        for(int i=0;i<10;i++){
            sum+=(factorial(2*i)*pow(x,2*i+1))/(pow(4,i)*pow(factorial(i),2)*(2*i+1));
	}
	sum = (sum*180)/3.141592654;
return sum;
}
 
double acos (double x){
    if(x<-1||x>1){ //Math error
    	flag =1;
        return 0;
    }
    else{
        double cosinverse;
        cosinverse = 90-asin(x);
        return cosinverse;
    }
 
}
 
double atan (double x){
    double sum =0;
    if(x==1){
    	return 45;
    }
    else if(x==-1){
    	return -45;
    }
    else{
    	for(int i=0;i<50;i++){
        sum+=(pow(-1,i)*pow(x,2*i+1))/(2*i+1);
    }
    }
    sum=(sum*180)/3.141592654;
    return sum;
 
 
}
 
double sinh (double x){ //take in angle turn it into radian
	x=x*3.141592654/180;
	return (exp(x)-exp(x*-1))/2;
}
 
double cosh (double x){ //take in angle
	x=x*3.141592654/180;
	return (exp(x) + exp(x*-1))/2;
}
 
double tanh (double x){ //take in angle
	return sinh(x)/cosh(x);
}
 
double ln (double x){
	if (x<=0)
		flag =1;
	double sum=0.00000;
	for (int i=0; i<15; i++)
		sum+=  pow(((x-1)/(x+1)),2*i +1)/(2*i+1);
	sum*=2;
	return sum;
}
 
double log (double base, double x){
	return (ln(x)/ln (base));
}
 
double sqrt (double x){
	if (x<0)
		return 2; //meval math error
	else return exp (ln(x)/2);
 
}
 
double root (double base,int power){
	if (power%2==0 && base<0)
		return 2; //meval math error
 
	return exp(ln(base)/power);
 
}
 
double x10(double  power ){
    double y=1;
    for(int i=0;i<power;i++){
        y*=10;
    }
    return y;
 
}
 
void MS (double val){
	M=val;
}
 
void Mp (double val){
	M+=val;
}
 
void Mm (double val){
	M-=val;
}
 
void MC  (){
	M=0;
}
 
double MR (){
	return M;
}
 
int main() {
cout<<"0"<<endl;
string whatever;
double x,val=0;
bool radians =1;
stringstream ss;
 
while (1){
	flag =0;
	cin>>whatever;
	system("cls");
	if (whatever=="sin"){
           if(radians){
             val=val*(180/3.141592654);
            }
		val=sin(val);
		cout<<val;
	}
	else if (whatever=="cos"){
	    if(radians){
            val=val*(180/3.141592654);
	    }
		val=cos(val);
		cout<<val;
	}
	else if (whatever=="tan"){
           if(radians){
            val=val*(180/3.141592654);
	    }
		val=tan(val);
		if (flag){
			cout<<"Math error";
			val=0;
		}
		else
		cout<<val;
	}
	else if (whatever=="asin"){
	    if(radians){
           val=val*(180/3.141592654);
	    }
		val=asin(val);
		if (flag){
			cout<<"Math error";
			val=0;
		}
		else
		cout<<val;
	}
	else if(whatever=="acos"){
	    if(radians){
            val=val*(180/3.141592654);
	    }
		val=acos(val);
		if (flag){
			cout<<"Math error";
			val=0;
		}
		else
			cout<<val;
	}
	else if(whatever=="atan"){
	    if(radians){
            val=val*(180/3.141592654);
	    }
		val=atan(val);
		cout<<val;
	}
	else if(whatever=="sinh"){
	    if(radians){
           val=val*(180/3.141592654);
	    }
		val=sinh(val);
		cout<<val;
	}
	else if(whatever=="cosh"){
	    if(radians){
           val=val*(180/3.141592654);
	    }
		val=cosh(val);
		cout<<val;
	}
	else if (whatever=="tanh"){
	    if(radians){
           val=val*(180/3.141592654);
	    }
		val=tanh(val);
		cout<<val;
	}
	else if(whatever=="abs"){
		val=abs(val);
		cout<<val;
	}
	else if (whatever=="exp"){
		val=exp(val);
		cout<<val;
	}
	else if(whatever=="ln"){
		val=ln(val);
		if (flag){
			cout<<"Math error";
			val=0;
		}
		else
		cout<<val;
	}
	else if(whatever=="sqrt"){
		val=sqrt(val);
		cout<<val;
	}
	else if(whatever=="factorial"){
		val=factorial(val);
		cout<<val;
	}
	else if (whatever=="x10"){
		val=x10(val);
		cout<<val;
	}
	else if (whatever=="pow"){
		cin>>x;
		system("cls");
		val=pow(val,x);
		cout<<val;
	}
	else if(whatever=="root"){
		cin>>x;
		system("cls");
		val=root(val,x);
		cout<<val;
 
}
	else if(whatever=="log"){
		cin>>x;
		system("cls");
		val=log(val,x);
		cout<<val;
 
	}
	else if (whatever == "MS")
		MS(val);
	else if (whatever=="M+"){
		cin>>x;
		system("cls");
		Mp(x);
	}
	else if (whatever =="M-"){
		cin>>x;
		system("cls");
		Mm(x);
	}
	else if (whatever == "MR")
		cout<<MR();
	else if (whatever == "MC")
		MC();
	else if (whatever == "+"){
		cin>>x;
        system("cls");
 
		val+=x;
		cout<<val;
	}
	else if (whatever == "-"){
		cin>>x;
        system("cls");
 
		val-=x;
		cout<<val;
	}
	else if (whatever == "*"){
		cin>>x;
        system("cls");
 
		val*=x;
		cout<<val;
	}
	else if (whatever == "/"){
		cin>>x;
        system("cls");
 
		val/=x;
		cout<<val;
	}
	else if (whatever == "radians")
		radians =1;
	else if (whatever == "degree")
		radians=0;
 
	else {
		ss<<whatever;
		ss>>val;
		ss.clear();
 
	}
 
 
}
}
 
