#pragma once
 
#include <iostream>

using namespace std;

class VECTOR4D
{
public:
	union {
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			float r, g, b, a;
		};
		struct
		{
			unsigned long ulx, uly, ulz, ulw;
		};
		struct
		{
			long lx, ly, lz, lw;
		};
		float v[4];
		unsigned long ul[4];
		long l[4];
	};
	VECTOR4D();
	VECTOR4D(VECTOR4D &V);
	VECTOR4D(float fx, float fy, float fz, float fw);
	~VECTOR4D();
};

ostream& operator << (ostream &out, VECTOR4D &V);
istream& operator >> (istream &in, VECTOR4D &V);
VECTOR4D operator* (VECTOR4D &A, VECTOR4D &B);
VECTOR4D operator*(float s, VECTOR4D &A);
VECTOR4D operator* (VECTOR4D &A, float s);
VECTOR4D operator/ (VECTOR4D &A, float s);
VECTOR4D operator/ (VECTOR4D &A, VECTOR4D &B);
VECTOR4D operator+ (VECTOR4D &A, VECTOR4D &B);
VECTOR4D operator- (VECTOR4D &A, VECTOR4D &B);
float Dot(VECTOR4D &A, VECTOR4D &B);
VECTOR4D Cross3(VECTOR4D &A, VECTOR4D &B);
float Magnity(VECTOR4D &A);
VECTOR4D Normalize(VECTOR4D &A);

