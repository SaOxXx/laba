#ifndef _POINT_H_
#define _POINT_H_
#include <iostream>

typedef struct point_s {
	int x;
	int y;
	int z;
	int operator=(int b) {
		x = b;
		y = b;
		z = b;
		return b;
	}

} point_t;

std::istream& operator>>(std::istream& in, point_t& a) {
	in >> a.x;
	in >> a.y;
	in >> a.z;
	return in;
}
std::ostream& operator<<(std::ostream& out, point_t& a) {
	out << a.x;
	out << ' ';
	out << a.y;
	out << ' ';
	out << a.z;
	return out;
}
point_t& operator*(point_t& a, point_t& b) {
	point_t c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;
	return c;
}
point_t& operator+(point_t& a, point_t& b) {
	b.x = a.x + b.x;
	b.y = a.y + b.y;
	b.z = a.z + b.z;
	return b;
}
#endif