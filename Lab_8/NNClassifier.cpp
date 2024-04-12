/* ============================================================== */
/**
 * @file NNClassifier.cpp
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#include "NNClassifier.h"
#include <cmath>

/// @brief This function predicts what a point is based on nearest neighbour.
///
/// This function will calculate the orientation of a point based on the neighbours
/// around it. It uses euclidian distance to determine which point is the closest
/// to the unclassified point, and sets them to the same orientation.
/// @param DataPoint&
/// @return int
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
int NNClassifier::predict(const DataPoint& sample) {
    float minDistance = std::numeric_limits<float>::max();
    int nearestOrientation = 0;

    for (const DataPoint& data : trainingData) {
        float distance = euclideanDistance(sample, data);
        if (distance < minDistance) {
            minDistance = distance;
            nearestOrientation = data.getOrientation();
        }
    }

    return nearestOrientation;
}

/// @brief This function returns the distance between 2 data points
///
/// This function will calculate the euclidean distance between 2 data points.
/// The formula is d = √[ (x2 – x1)2 + (y2 – y1)2].
/// @param DataPoint&, DataPoint&
/// @return float
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
float NNClassifier::euclideanDistance(const DataPoint& a, const DataPoint& b) {
    return std::sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) +
        (a.getY() - b.getY()) * (a.getY() - b.getY()) +
        (a.getZ() - b.getZ()) * (a.getZ() - b.getZ()));
}