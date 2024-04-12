/* ============================================================== */
/**
 * @file NNClassifier.h
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#pragma once

#include "classifier.h"

/// @brief Nearest neighbour classifier
///
/// This class contains the protected trainingData from the inherited
/// Classifier class. This class contains the public predict function
/// to determine what orientation a DataPoint is in.
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
class NNClassifier : public Classifier {

public:
	NNClassifier(const std::vector<DataPoint>& trainingData) {
		this->trainingData = trainingData;
	}

	int predict(const DataPoint& sample) override;

private:
	static float euclideanDistance(const DataPoint& a, const DataPoint& b);
};
