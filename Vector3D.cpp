#include "Vector3D.h"

Vector3D::Vector3D() : x(0), y(0), z(0) {}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3D::~Vector3D() {}

double Vector3D::getX() const
{
	return x;
}

double Vector3D::getY() const
{
	return y;
}

double Vector3D::getZ() const
{
	return z;
}

Vector3D Vector3D::operator+(const Vector3D & v3) const
{
	return Vector3D(x+ v3.x, y+ v3.y, z+ v3.z);
}

Vector3D Vector3D::operator-(const Vector3D & v3) const
{
	return Vector3D(x-v3.x, y-v3.y, z-v3.z);
}

Vector3D Vector3D::operator-() const
{
	return Vector3D(-1*x, -1*y, -1*z);
}

Vector3D Vector3D::operator*(double n) const
{
	return Vector3D(x*n, y*n, z*n);
}

Vector3D operator*(double n, const Vector3D & v3)
{
	return Vector3D(v3.x*n, v3.y*n, v3.z*n);
}

std::istream & operator>>(std::istream & is, Vector3D & v3)
{
	/*Allocate enough memory for a potentially long vector string.
	If the coordinate numbers are very long.*/
	char input[100];

	is >> input;

	char** nums = Vector3D::parse_input(input);

	//Parse coordinates from string
	v3.x = atof(nums[0]);
	v3.y = atof(nums[1]);
	v3.z = atof(nums[2]);

	delete[] nums; //Delete the pointer array that we created in parse_input

	return is;
}

/*Parse second and third coordinates, by splitting input string.
This program uses ',' as a delimiter,
without using any external functions.
We assume that the first coordinate always starts at position 1
of the input string.*/
char** Vector3D::parse_input(char* input)
{
	char** nums = new char*[3]{&input[1], 0, 0};

	for (size_t i = 0; i < strlen(input); i++)
	{
		char &c = input[i];

		if (c == ',' && nums[1] == 0)
			nums[1] = (&c) + 1;
		else if (c == ',' && nums[1] != 0)
			nums[2] = (&c) + 1;
	}

	return nums;
}

std::ostream & operator<<(std::ostream & os, Vector3D & v3)
{
	os << "(" << v3.x << ",";
	os << v3.y << ",";
	os << v3.z << ")";

	return os;
}
