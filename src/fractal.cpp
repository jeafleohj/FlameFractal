#include "fractal.hpp"
#include <GL/glew.h>
#include <iostream>
#include <random>
Fractal::Fractal(std::vector< std::pair<Point<GLfloat> (*)(Point<GLfloat>), Point<GLfloat>> > functions, std::vector<Point<GLfloat>> points)
	:functions(functions),points(points)
{
	
}

void Fractal::nextIteration(){
	int size=functions.size();
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,size-1);
	Point<GLfloat> m;
	for(int i=0;i<size;i++){
		int position = distribution(generator);
		points[position]=functions[position].first(points[position]);
	}
}
void Fractal::render(int iteraciones){
// 	1 	glDrawArrays(GL_POINTS, 0, 12);
// We also need to enable GL_PROGRAM_POINT_SIZE in the initialize function:
// 1 	glEnable(GL_PROGRAM_POINT_SIZE);
// With the above changes we can control the point size in pixels in the vertex shader with:
// 1 	gl_PointSize = 10.0;
	for (int i=0; i < iteraciones; ++i) {
		nextIteration();
		if(i>20){
			//Plotear
		}
	}

}

