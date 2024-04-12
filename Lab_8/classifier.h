#pragma once

#include "DataPoint.h"
#include <vector>

class classifier {
protected:
    std::vector<datapoint> trainingData;

public:

    virtual int predict(const datapoint& sample) = 0;

};