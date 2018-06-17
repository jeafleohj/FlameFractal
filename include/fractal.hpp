#ifndef FRACTAL_H
#define FRACTAL_H
#include <vector>
#include <utility>
#include "point.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Fractal{
	//IFS funciones
	//Cada funcion tendra un color asociado
	std::vector< std::pair<Point<GLfloat> (*)(Point<GLfloat>), Point<GLfloat>> > functions;
	//Initial points
	std::vector<Point<GLfloat>> points;
	void nextIteration();

public:
	Fractal(std::vector< std::pair<Point<GLfloat> (*)(Point<GLfloat>) , Point<GLfloat>> > funciones, std::vector<Point<GLfloat>> points);
	void render(int iteraciones);
};
#endif
