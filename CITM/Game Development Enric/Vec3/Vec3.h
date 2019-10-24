#pragma once
#include <iostream>

class Vec3 {
private:
	float x;
	float y;
	float z;

public:
	Vec3()
	{
		x = y = z = 0;
	}
	Vec3(float n)
	{
		x = y = z = n;
	}
	Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	Vec3 operator + (Vec3 &v) const
	{
		Vec3 v1(x + v.x, y + v.y, z + v.z);
		return v1;
	}
	Vec3 operator - (Vec3 &v) const
	{
		Vec3 v1(x - v.x, y - v.y, z - v.z);
		return v1;
	}
	void operator += (Vec3 &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}
	void operator -= (Vec3 &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
	void operator = (Vec3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	bool operator == (Vec3 &v) const
	{
		if (x == v.x && y == v.y && z == v.z)
			return true;
		else
			return false;
	}
	Vec3 operator * (float n) const
	{
		Vec3 v1(x*n, y*n, z*n);
		return v1;
	}

	bool is_zero() const
	{
		if (x == 0 && y == 0 && z == 0)
			return true;
		else
			return false;
	}
	void zero()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	void normalize()
	{
		float x1 = x; float y1 = y; float z1 = z;
		x = x1 / (sqrt(x1*x1 + y1 * y1 + z1 * z1));
		y = y1 / (sqrt(x1*x1 + y1 * y1 + z1 * z1));
		z = z1 / (sqrt(x1*x1 + y1 * y1 + z1 * z1));
	}
	float distance_to(Vec3 &v) const
	{
		return sqrt((v.x - x)*(v.x - x) + (v.y - y)*(v.y - y) + (v.z - z)*(v.z - z));
	}
};
