/* ============================================================== */
/**
 * @file FileHandler.h
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#pragma once

#include <vector>
#include <string>
#include "DataPoint.h"

using namespace std;

/// @brief Class made to handle file I/O
///
/// This class is in charge of handling all of the
/// file input and output operations.
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
class FileHandler {
public:
    vector<DataPoint> readData(string fileName);
    bool writeData(vector<DataPoint> dp, string fileName);
};