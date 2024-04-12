/* ============================================================== */
/**
 * @file Classifier.h
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#pragma once

#include "DataPoint.h"
#include <vector>

/// @brief Classifier base abstract class
///
/// This class is used as the base class to be
/// inherited by all of the different kinds of
/// Classifiers
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
class Classifier {
protected:
    std::vector<DataPoint> trainingData;

public:

    virtual int predict(const DataPoint& sample) = 0;

};