#ifndef POINT_H
#define POINT_H
#include <GL/glew.h>
#include <ostream>
template<typename T>
class Point{
	T x,y,z;
 public:
	Point();
	Point(T,T,T);
	void setX(T);
	void setY(T);
	void setZ(T);
	void setPoint(T,T,T);
	T getX();
	T getY();
	T getZ();
	Point<T> operator+(const Point<T>&)const;
	Point<T> operator-(const Point<T>&)const;
	bool operator!=(const Point<T> &)const;
	Point<T>& operator=(const Point<T>&);
	friend std::ostream &operator<<(std::ostream& os, const Point<T>&p){
		os<<p.x<<" "<<p.y<<" "<<p.z;
		return os;  
	};
};
template<typename T>
Point<T>::Point(){
	x=y=z=0;
}

template<typename T>
Point<T>::Point(T _x,T _y,T _z)
	:x(_x),y(_y),z(_z)
{};

template<typename T>
void Point<T>::setX(T _x){x=_x;}

template<typename T>
void Point<T>::setY(T _y){y=_y;}

template<typename T>
void Point<T>::setZ(T _z){z=_z;}

template<typename T>
void Point<T>::setPoint(T x,T y,T z){
	setX(x);
	setY(y);
	setZ(z);
}

template<typename T>
T Point<T>::getX(){return x;}

template<typename T>
T Point<T>::getY(){return y;}

template<typename T>
T Point<T>::getZ(){return z;}

template<typename T>
Point<T> Point<T>::operator+(const Point<T>& b)const{
	Point<T> r(x+b.x,y+b.y,z+b.z);
	return r;
}

template<typename T>
Point<T> Point<T>::operator-(const Point<T>& b)const{
	Point<T> r(x-b.x,y-b.y,z-b.z);
	return r;
}

template<typename T>
bool Point<T>::operator!=(const Point<T> &b) const{
	return (x!=b.x)&&(y!=b.y)&&(z!=b.z);
}

template<typename T>
Point<T>& Point<T>::operator=(const Point<T> &b){
	setPoint(b.x, b.y, b.z);
	return *this;
}

#endif
