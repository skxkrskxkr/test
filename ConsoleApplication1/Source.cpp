#include "matrix4x4.h"


int main()
{
	vector4D v0(1, 2, 3, 4);
	vector4D v1(5, 6, 7, 8);
	vector4D v2(9, 10, 11, 12);
	vector4D v3(13, 14, 15, 16);

	

	matrix4x4 m(v0, v1, v2, v3);

	vector4D y = m*v0;
	std::cout << y << std::endl;
	return 0;
}