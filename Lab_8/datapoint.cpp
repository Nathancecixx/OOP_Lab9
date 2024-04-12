/* ============================================================== */
/**
 * @file DataPoint.cpp
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#include "DataPoint.h"

/// @brief DataPoint constructor, unparameterized
///
/// This constructor will default all values to 0
/// @param void
/// @return DataPoint
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
DataPoint::DataPoint()
	: x(0), y(0), z(0), orientation(0) {}

/// @brief DataPoint constructor, parameterized
///
/// This constructor will set the values in the DataPoint
/// to what is passed to them.
/// @param void
/// @return DataPoint
/// @author Kyle, Nathan, Ginbot
/// @date 10/04/2024
DataPoint::DataPoint(float X, float Y, float Z, int Orientation)
	: x(X), y(Y), z(Z), orientation(Orientation) {}

/// @brief This function will return value of x
///
/// This function returns the current instance of this objects x-field.
/// @param void 
/// @return float
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
float DataPoint::getX() const{
	return x;
}

/// @brief Returns DataPoint y value
///
/// This function returns the current instance of this objects y-field.
/// @param void
/// @return float
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
float DataPoint::getY() const{
	return y;
}

/// @brief Returns DataPoint z value
///
/// This function returns the current instance of this objects z-field.
/// @param void
/// @return float
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
float DataPoint::getZ() const{
	return z;
}

/// @brief  This function return the orientation 
///
/// 
/// @param void
/// @return int
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
int DataPoint::getOrientation() const{
	return orientation;
}
