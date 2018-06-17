#include<iostream>
#include <utility>
#include <vector>
#include"fractal.hpp"
#include "point.hpp"
using namespace std;
using pgf = Point<GLfloat>;
pgf f1(pgf p);
int main(int argc, char **argv)
{
	pgf m[3];
	vector< pair<pgf (*)(pgf) , pgf > > fc;
	vector<pgf> puntos;
	m[0].setPoint(1,2,3);
	m[1].setPoint(2,1,2);
	m[2].setPoint(0.3,1.4,1.9);
	puntos.push_back(m[0]);
	fc.push_back( make_pair( &f1 , m[0] ) );
	cout << m[0]  << "\n";
	cout << m[1]  << "\n";
	cout << m[2]  << "\n";
	Fractal fractal(fc,puntos);
	puntos.push_back(m[0]);
	puntos.push_back(m[1]);
	puntos.push_back(m[2]);
	fractal.render(100);
    return 0;
}
pgf f1(pgf p){
	pgf r;
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	r.setX(x*x);
	r.setY(y+y);
	r.setZ(z*z);
	return r;
}
