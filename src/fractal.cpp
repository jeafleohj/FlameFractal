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
Fractal::Fractal(std::vector< Point<GLfloat> (*)(Point<GLfloat>) > functions,
				 std::vector< Point<GLfloat> (*)(Point<GLfloat>) > variaciones ){
	int n=functions.size();
	std::default_random_engine generator;
	std::random_device rd;//True random
	std::uniform_real_distribution<double> dist(0,1.);
	for(int i=0;i<n;i++){
		//Point<GLfloat> color(float(rd())/rd.max(),float(rd())/rd.max(),float(rd())/rd.max());
		Point<GLfloat> color(dist(generator),dist(generator),dist(generator));		
		this->functions.push_back(std::make_pair(functions[i], color));
		//points.emplace_back(dist(generator),dist(generator),0);
		points.emplace_back(rd()*1.0/rd.max(),rd()*1.0/rd.max(),0);
	}
	for(auto v : variaciones){
		variations.push_back(v);
	}
}

void Fractal::nextIteration(Point<GLfloat>& color){
	int size=functions.size();
	int vsize=variations.size();
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,size-1);
	std::random_device rd;
	Point<GLfloat> m;
	for(int i=0;i<size;i++){
		//int position = distribution(generator);
		int position = rd()%size;
		int vpos = rd()%vsize;
		points[i]=functions[position].first(points[position]);
		points[i]=variations[vpos](points[i]);
		
		Point<GLfloat> c=functions[position].second;
		color = (color+c)/2;
		glColor3f(color.getX(),color.getY(),color.getZ());
		points[i].render();
	}
}
void Fractal::render(int iteraciones){
	std::default_random_engine generator;
	std::uniform_real_distribution<double> dist(0.0,1.0);	
	Point<GLfloat> color(dist(generator),dist(generator),dist(generator));
	for (int i=0; i < iteraciones; ++i) {
		nextIteration(color);
		if(i>20){
			//Plotear
		}
	}

}

