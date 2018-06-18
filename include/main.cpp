#include"point.hpp"
#include<iostream>
using namespace std;
int main(){
	Point<double> m(4,1,2);
	cout<<m<<endl;
	m=0.5*m;
	cout<<m<<endl;
}
