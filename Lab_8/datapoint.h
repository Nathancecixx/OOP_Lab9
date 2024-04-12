/* ============================================================== */
/**
 * @file DataPoint.h 
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#pragma once

/// @brief DataPoint
///
/// This class is used to represent a single point of data.
/// a data point is represented by (x, y, z, orientation)
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
class DataPoint
{
public:
	DataPoint();
	DataPoint(float X, float Y, float Z, int Orientation = 0);

	float getX() const;
	float getY() const;
	float getZ() const;
	int getOrientation() const;

private:
	float x, y, z;
	int orientation;
};
