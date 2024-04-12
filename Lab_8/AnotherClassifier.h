/* ============================================================== */
/**
 * @file AnotherClassifier.h
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#pragma once

#include "classifier.h"

/// @brief Unwritten Classifier Class
///
/// This class will be another Classifier once implemented.
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
class AnotherClassifier : public Classifier {

public:
	AnotherClassifier(const std::vector<DataPoint>& trainingData) {
		this->trainingData = trainingData;
	}

	int predict(const DataPoint& sample) override;
};