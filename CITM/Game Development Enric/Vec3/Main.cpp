#include "Vec3.h"
#include <iostream>

int main()
{
	Vec3 v1;
	Vec3 v2(3);
	Vec3 v3(4, 5, 6);
	v2 + v3;
	v2 - v3;
	v2 * 3;
	v1 = v3;
	if (!(v1 == v2))
		v1.zero();
	if (v1.is_zero())
		v1 += v2;
	v3.normalize();
	v3.distance_to(v1);
}