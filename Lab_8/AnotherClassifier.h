#pragma once

#include "classifier.h"
#include "datapoint.h"

class AnotherClassifier : public classifier {

public:
	AnotherClassifier(const std::vector<datapoint>& trainingData) {
		this->trainingData = trainingData;
	}

	int predict(const datapoint& sample) override;
};