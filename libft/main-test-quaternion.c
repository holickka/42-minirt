#include "ft_vector.h"
#include <stdio.h>

int main()
{
	mQuaternion q1;
	Vector3D axis;
	Vector3D point;
	Vector3D newpoint;

	axis = newVector3D(0, 0, 1);
	point = newVector3D(0.7, 0.5, 0);
	q1 = newQuaternion(axis, 30);
	newpoint = mQuaternionRotate(q1, point);
	printf("%f, %f, %f\n", newpoint.x, newpoint.y, newpoint.z);
}