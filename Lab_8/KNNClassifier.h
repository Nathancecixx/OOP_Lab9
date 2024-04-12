#pragma once

#include "classifier.h"
#include "datapoint.h"

class KNNClassifier : public classifier {

public:
	KNNClassifier(const std::vector<datapoint>& trainingData) {
		this->trainingData = trainingData;
	}

	int predict(const datapoint& sample) override;
};