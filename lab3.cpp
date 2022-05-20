#include <math.h>
#include <bits/stdc++.h>

using namespace std ;
class Polar{ // class declare here
private:
double x ; // real 
double y ; // imaginary
double r ;
double theta ;
public:
// only one constructor
Polar(double radius = 0, double degree = 0){
 r = radius ; theta = degree ;
  double radian=(degree*3.14)/180;  
  x = radius*(cos(radian));
  y = radius*(sin(radian)); 
}
// display funtion to display polar representation
void display(){
    
    cout<<"Polar representation :"<<'\t';
  
   cout<<r<<"( cos"<<"("<<theta<<")"<<"+ i*sin("<<theta<<") )"<<endl;
}
// operator *
Polar operator*(Polar &obj1); // prototype declared here its not a friend function
friend Polar operator-(Polar &obj1 , Polar &obj2) ; // prototype of friend function to implement - overator for two polar number
~Polar(){/* destructor is declared here */ }
};
// outside class represention of operator overloading
Polar Polar::operator*(Polar &obj1){
double xx = x*obj1.x ;
double yy = y*obj1.y ;
double fx = -yy+xx ;
double ixx = x*obj1.y;
double iyy = y*obj1.x ;
double fy = ixx+iyy ;
double radius2 = (fx*fx + fy*fy) ;
double radius = pow(radius2 , 0.5) ;
double thet = atan(fy/fx) ;
thet*=180 ;
thet/=3.14 ;
Polar crazyxyz(radius , thet) ;
return crazyxyz ;

}
Polar operator -(Polar &obj1 , Polar &obj2){
    
    double xx = obj1.x - obj2.x ;
    double yy = obj1.y - obj2.y ;
    cout<<xx<<" "<<yy<<endl;
    double radius2 = (xx*xx + yy*yy) ;
double radius = pow(radius2 , 0.5) ;
double thet = atan(yy/xx) ;
thet*=180 ;
thet/=3.14 ;
Polar xyz(radius , thet) ;
return xyz;
}
int main(){
  Polar one(2,90) ;
  one.display() ;
Polar two(5 , 90) ;
two.display();
Polar three = one-two;
three.display() ;
    return 0 ;
}