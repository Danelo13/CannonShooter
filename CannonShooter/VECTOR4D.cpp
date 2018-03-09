#include "stdafx.h"
#include "VECTOR4D.h"


VECTOR4D::VECTOR4D()
{
	x = 0; y = 0; z = 0; w = 0;
}

VECTOR4D::VECTOR4D(VECTOR4D& V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	w = V.w;
}

VECTOR4D::VECTOR4D(float fx, float fy, float fz, float fw)
{
	x = fx;
	y = fy;
	z = fz;
	w = fw;
}

VECTOR4D::~VECTOR4D()
{
}


ostream &operator <<(ostream &out, VECTOR4D &V)
{
	out << "[" << V.x << ", " << V.y << ", " << V.z << ", " << V.w << "]";
	return out;
};
istream &operator >> (istream &in, VECTOR4D &V)
{
	in >> V.x >> V.y >> V.z >> V.w;
	return in;
};

VECTOR4D operator* (VECTOR4D &A, VECTOR4D &B)
{
	return VECTOR4D(A.x * B.x, A.y * B.y, A.z * B.z, A.w * B.w);
};
VECTOR4D operator* (float S, VECTOR4D &A)
{
	return VECTOR4D(S * A.x, S * A.y, S * A.z, S * A.w);
};
VECTOR4D operator* (VECTOR4D &A, float S)
{
	return S*A;
};
VECTOR4D operator/ (VECTOR4D &A, float S)
{
	return (1 / S)*A;
};
VECTOR4D operator/ (VECTOR4D &A, VECTOR4D &B) {
	return VECTOR4D(A.x / B.x, A.y / B.y, A.z / B.z, A.w / B.w);
}
VECTOR4D operator+ (VECTOR4D &A, VECTOR4D &B)
{
	return VECTOR4D(A.x + B.x, A.y + B.y, A.z + B.z, A.w + B.w);
};
VECTOR4D operator- (VECTOR4D &A, VECTOR4D &B)
{
	return VECTOR4D(A.x - B.x, A.y - B.y, A.z - B.z, A.w - B.w);
};
float Dot(VECTOR4D &A, VECTOR4D &B)
{
	return A.x*B.x + A.y*B.y + A.z*B.z + A.w * B.w; // |A||B|Cos(x)
}
VECTOR4D Cross3(VECTOR4D &A, VECTOR4D &B)
{
	return VECTOR4D(A.y*B.z - A.z*B.y,
		A.z*B.x - A.x*B.z,
		A.x*B.y - A.y*B.x, 0);  // |AxB| = |A||B|Seno(X)
}
float Magnity(VECTOR4D &A)
{
	return sqrt(Dot(A, A));
}
VECTOR4D Normalize(VECTOR4D &A)
{
	return A / Magnity(A);

}
