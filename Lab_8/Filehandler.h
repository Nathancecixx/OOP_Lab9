#pragma once

#include <vector>
#include <string>
#include "datapoint.h"

using namespace std;

class FileHandler {
public:
    vector<datapoint> readData(string fileName);
    bool writeData(vector<datapoint> dp, string fileName);
};