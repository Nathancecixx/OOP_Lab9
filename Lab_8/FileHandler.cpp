/* ============================================================== */
/**
 * @file FileHandler.cpp
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

/// @brief This function reads data from a given filename.
///
/// After receiving a filename, the function will read the data and then
/// put that data into DataPoint objects.
/// @param string
/// @return vector<DataPoint>
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
vector<DataPoint> FileHandler::readData(string fileName) {
    vector<DataPoint> data;
    ifstream file;
    file.open(fileName);

    if (file.is_open()) {
        while (!file.eof()) {
            string line;
            getline(file, line);
            istringstream issLine(line);

            int commaCount = 0;
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ',')
                    commaCount++;
            }

            string x, y, z, orientation;
            getline(issLine, x, ',');
            getline(issLine, y, ',');
            getline(issLine, z, ',');
            if(commaCount == 3)
                getline(issLine, orientation);

            float X, Y, Z;
            int Orientation;

            X = stof(x);
            Y = stof(y);
            Z = stof(z);

            if (commaCount == 3)
                Orientation = stoi(orientation);
            else
                Orientation = 0;

            data.push_back(DataPoint(X, Y, Z, Orientation));
        }
    }


    return data;
}

/// @brief Writes data to file
///
/// Given a filename, the function opens a file and writes the vector
/// DataPoint to the file.
/// @param vector<DataPoint>, string
/// @return bool
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
bool FileHandler::writeData(vector<DataPoint> dp, string fileName) {
	ofstream fout;
	int label;
	string orientation;
	fout.open(fileName);
	if (fout.is_open()) {
		for (auto& points : dp) {
			label = points.getOrientation();
			switch (label) {
			case 1:
				orientation = "Face up";
				break;
			case 2:
				orientation = "Face down";
				break;
			case 3:
				orientation = "Portrait";
				break;
			case 4:
				orientation = "Portrait upside down";
				break;
			case 5:
				orientation = "Landscape Right";
				break;
			case 6:
				orientation = "Landscape Left";
				break;
			default:
				cout << "Unknown Orientation" << endl;
				break;
			}
			fout << points.getX() << ", " << points.getY() << ", " << points.getZ() << ", " << points.getOrientation() << ", " << orientation << endl;

		}
		fout.close();
	}
	else {
		cout << "Could not write to " << fileName << endl;
		return false;
	}
	return true;
}