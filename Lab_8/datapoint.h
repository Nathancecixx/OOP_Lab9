#pragma once

class datapoint
{
public:
	datapoint();
	datapoint(float X, float Y, float Z, int Orientation = 0);

	float getX() const;
	float getY() const;
	float getZ() const;
	int getOrientation() const;

private:
	float x, y, z;
	int orientation;
};
