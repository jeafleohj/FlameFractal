#include<iostream>
#include <utility>
#include <vector>
#include <GL/glew.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include"fractal.hpp"
#include "point.hpp"
#include <random>
using namespace std;
using pgf = Point<GLfloat>;
pgf f1(pgf p);pgf f2(pgf p);
pgf f3(pgf p);pgf f4(pgf p);
pgf f5(pgf p);pgf f6(pgf p);
pgf f7(pgf p);pgf f8(pgf p);
pgf f9(pgf p);pgf f10(pgf p);
pgf f11(pgf p);pgf f12(pgf p);
pgf f13(pgf p);pgf f14(pgf p);
pgf f15(pgf p);pgf f16(pgf p);
pgf f17(pgf p);pgf f18(pgf p);
pgf f19(pgf p);pgf f20(pgf p);
pgf f21(pgf p);pgf f22(pgf p);
pgf f23(pgf p);pgf f24(pgf p);
pgf f25(pgf p);pgf f26(pgf p);
pgf f27(pgf p);pgf f28(pgf p);
pgf f29(pgf p);pgf f30(pgf p);
pgf v0(pgf p);pgf v1(pgf p);
pgf v2(pgf p);pgf v3(pgf p);

void init();
void render();
GLFWwindow* window;
int main(int argc, char **argv)
{
	init();
	render();
    return 0;
}
void init(){
	glfwInit();
	//each pixel consists of 4 pixels so to speak
	glfwWindowHint(GLFW_SAMPLES, 4);
    window = glfwCreateWindow( 100, 100, "Flame Fractal", NULL, NULL);
	glfwMakeContextCurrent(window);
	glEnable(GL_DEPTH_TEST);
	glfwMakeContextCurrent(window);
}
void render(){
	GLint w,h;
	glfwGetWindowSize(window, &w, &h);
	glViewport(0, 0, w, h);
	//glClearColor(.8, .3, 0.75, .50);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	vector< pgf (*)(pgf)  > fc;
	vector< pgf (*)(pgf)  > var;	
	fc.push_back(&f1);fc.push_back(&f2);
	fc.push_back(&f3);fc.push_back(&f4);
	fc.push_back(&f5);fc.push_back(&f6);
	fc.push_back(&f7);fc.push_back(&f8);
	fc.push_back(&f9);fc.push_back(&f10);
	fc.push_back(&f11);//fc.push_back(&f12);
	//	fc.push_back(&f13);fc.push_back(&f14);
	/*
	fc.push_back(&f15);fc.push_back(&f16);
	fc.push_back(&f17);fc.push_back(&f18);
	fc.push_back(&f19);fc.push_back(&f20);
	fc.push_back(&f21);fc.push_back(&f22);
	fc.push_back(&f23);fc.push_back(&f24);
	fc.push_back(&f25);fc.push_back(&f26);
	fc.push_back(&f27);fc.push_back(&f28);
	fc.push_back(&f29);fc.push_back(&f30);
	*/
	
	//var.push_back( &v0 );
	//var.push_back( &v1 );
	//var.push_back( &v2 );
	var.push_back( &v3 );		

	Fractal fractal(fc,var);
	while(!glfwWindowShouldClose(window)){
        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();
		glPointSize(1);
        //gluPerspective(60, (double) w/ (double)h, 0.1, 100);
        glMatrixMode(GL_MODELVIEW_MATRIX);
        //glTranslatef(0, 0, -5);
        //Debria estar el draw del cubo
		glBegin(GL_POINTS);
		//glColor4f(1,.5,.5,1);
		fractal.render(1000);
		glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();

	}	
}
pgf f1(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(x/2,(y+1)/2,z);
	return r;
}
pgf f2(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((x-1)/2,(y-1)/2,z);
	return r;
}
pgf f3(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((x+1)/2,(y-1)/2,z);
	return r;
}
pgf f4(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((x-2)/2,(y-2)/2,z);
	return r;
}
pgf f5(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((y*3-6)/6,x*0.5+1.5,z);
	return r;
}
pgf f6(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(14.0/18*(x+1)-10/18.0,y,z);
	return r;
}
pgf f7(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}
pgf f8(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((x-4)/5 , (y+8)/9 ,z);
	return r;
}

pgf f9(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((x+y)/2,(x-y)/3,z);
	return r;
}

pgf f10(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((y-x)/2,(y+x*sin(2.5))/2,z);
	return r;
}

pgf f11(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((x+y*cos(-1))/2,(y-x*sin(-1))/2,z);
	return r;
}

pgf f12(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f13(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f14(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f15(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f16(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f17(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}
pgf f18(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}
pgf f19(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f20(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f21(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f22(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f23(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f24(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f25(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f26(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f27(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f28(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f29(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

pgf f30(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(y*cos(2.5),x*sin(2.5),z);
	return r;
}

//variaciones
pgf v0(pgf p){
	GLfloat x,y,z,ra;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	ra=sqrt(x*x+y*y);
	pgf r(ra*cos(y),ra*cos(x),z);
	return r;
};
pgf v1(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(cos(x)*y,sin(y)*cos(y)*y,z);
	return r;
}

pgf v2(pgf p){
	GLfloat x,y,z,r;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	r=x*x+y*y;
	pgf re(x*cos(y)/r,y*cos(x)/r,z);
	return re;
}
pgf v3(pgf p){
	GLfloat x,y,z,r;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	r=x*x+y*y;
	std::random_device rd;//True random
	double theta= float(rd())/rd.max();
	pgf re(x*cos(y),-y*sin(x),z);
	return re;
}



