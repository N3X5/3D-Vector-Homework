#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D
{
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	~Vector3D();

	double getX() const;
	double getY() const;
	double getZ() const;

	Vector3D operator+(const Vector3D& secondVector) const;
	Vector3D operator-(const Vector3D& secondVector) const;
	Vector3D operator-() const;
	Vector3D operator*(double number) const;

	friend Vector3D operator*(double number, const Vector3D& vector);
	friend std::istream& operator>>(std::istream& iStream, Vector3D& vector);
	friend std::ostream& operator<<(std::ostream& oStream, Vector3D& vector);

private:
	static char** parse_input(char* input);

	double x, y, z;
};

#endif