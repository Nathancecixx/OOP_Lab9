/* ============================================================== */
/**
 * @file KNNClassifier.h
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#pragma once

#include "classifier.h"


/// @brief Unwritten Classifier Class
///
/// This class will be another classifier once implemented.
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
class KNNClassifier : public Classifier {

public:
	KNNClassifier(const std::vector<DataPoint>& trainingData) {
		this->trainingData = trainingData;
	}

	int predict(const DataPoint& sample) override;
};