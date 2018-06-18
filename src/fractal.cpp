#include "fractal.hpp"
#include <GL/glew.h>
#include <iostream>
#include <random>
#include <utility>
Fractal::Fractal(std::vector< std::pair<Point<GLfloat> (*)(Point<GLfloat>), Point<GLfloat>> > functions, std::vector<Point<GLfloat>> points)
	:functions(functions),points(points)
{}
Fractal::Fractal(std::vector< std::pair<Point<GLfloat> (*)(Point<GLfloat>) , Point<GLfloat>> > functions ){
	
}
//Colores random y puntos iniciales random
Fractal::Fractal(std::vector< Point<GLfloat> (*)(Point<GLfloat>) > functions ){
	int n=functions.size();
	std::default_random_engine generator;
	std::uniform_real_distribution<double> dist(0.0,1.0);
	for(int i=0;i<n;i++){
		Point<GLfloat> color(dist(generator),dist(generator),dist(generator));
		this->functions.push_back(std::make_pair(functions[i], color));
		points.emplace_back(dist(generator),dist(generator),0);
	}
}

void Fractal::nextIteration(){
	int size=functions.size();
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,size-1);
	std::random_device rd;
	Point<GLfloat> m;
	for(int i=0;i<size;i++){
		//int position = distribution(generator);
		int position = rd()%size;
		points[i]=functions[position].first(points[position]);
		Point<GLfloat> c=functions[position].second;
		glColor4f(c.getX(),c.getY(),c.getZ(),.5);
		points[i].render();
	}
}
void Fractal::render(int iteraciones){
	for (int i=0; i < iteraciones; ++i) {
		nextIteration();
		if(i>20){
			//Plotear
		}
	}

}

