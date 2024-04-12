#include "datapoint.h"

datapoint::datapoint()
	: x(0), y(0), z(0), orientation(0) {}

datapoint::datapoint(float X, float Y, float Z, int Orientation)
	: x(X), y(Y), z(Z), orientation(Orientation) {}

float datapoint::getX() const{
	return x;
}

float datapoint::getY() const{
	return y;
}

float datapoint::getZ() const{
	return z;
}

int datapoint::getOrientation() const{
	return orientation;
}
