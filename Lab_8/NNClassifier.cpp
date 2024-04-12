#include "NNClassifier.h"
#include <cmath>

int NNClassifier::predict(const datapoint& sample) {
    float minDistance = std::numeric_limits<float>::max();
    int nearestOrientation = 0;

    for (const datapoint& data : trainingData) {
        float distance = euclideanDistance(sample, data);
        if (distance < minDistance) {
            minDistance = distance;
            nearestOrientation = data.getOrientation();
        }
    }

    return nearestOrientation;
}

float NNClassifier::euclideanDistance(const datapoint& a, const datapoint& b) {
    return std::sqrt((a.getX() - b.getX()) * (a.getX() - b.getX()) +
        (a.getY() - b.getY()) * (a.getY() - b.getY()) +
        (a.getZ() - b.getZ()) * (a.getZ() - b.getZ()));
}