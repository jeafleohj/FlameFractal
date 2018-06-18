#include<iostream>
#include <utility>
#include <vector>
#include <GL/glew.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include"fractal.hpp"
#include "point.hpp"
using namespace std;
using pgf = Point<GLfloat>;
pgf f1(pgf p);
pgf f2(pgf p);
pgf f3(pgf p);
pgf f4(pgf p);
pgf f5(pgf p);
pgf f6(pgf p);
pgf f7(pgf p);
pgf v0(pgf p);
pgf v1(pgf p);
pgf v2(pgf p);
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
	fc.push_back( &f1  );
	fc.push_back( &f2  );
	fc.push_back( &f1  );
	fc.push_back( &f1  );
	fc.push_back( &f3  );
	fc.push_back( &f4  );
		fc.push_back( &f3  );
	fc.push_back( &f4  );

	fc.push_back( &f5  );
	fc.push_back( &f5  );
	fc.push_back( &f5  );
	fc.push_back( &f6  );
	fc.push_back( &f7  );
	fc.push_back( &f4  );
	fc.push_back(&v0);
	fc.push_back(&v1);
	fc.push_back( &f5  );
	fc.push_back( &f5  );
	fc.push_back( &f5  );
	fc.push_back( &f6  );
	fc.push_back( &f7  );
	fc.push_back(&v0);
	fc.push_back(&v1);
	fc.push_back(&v2);
	Fractal fractal(fc);
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
	pgf r((sin(x)+1)/2,(y-1)*x*sin(x),z);
	return r;
}
pgf f5(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((x*y+cos(x))/2,sin(y*y-1+cos(x))/2,z);
	return r;
}
pgf f6(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r((sin(y)+1)/2,y,z);
	return r;
}
pgf f7(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(cos(x),sin(x+y)+1,z);
	return r;
}
//variaciones
pgf v0(pgf p){
	GLfloat x,y,z;
	x=p.getX();
	y=p.getY();
	z=p.getZ();
	pgf r(x,y,z);
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
	pgf re(x*cos(y)/r,y*cos(y)/r,z);
	return re;
}
