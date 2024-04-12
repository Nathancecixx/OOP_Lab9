#pragma once

#include "classifier.h"
#include "datapoint.h"

class NNClassifier : public classifier {

public:
	NNClassifier(const std::vector<datapoint>& trainingData) {
		this->trainingData = trainingData;
	}

	int predict(const datapoint& sample) override;

private:
	static float euclideanDistance(const datapoint& a, const datapoint& b);
};
