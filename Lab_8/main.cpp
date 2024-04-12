/* ============================================================== */
/**
 * @file main.cpp
 * @author Kyle, Nathan, Ginbot
 * @date 10/04/2024
**/
/* ============================================================== */

#include "FileHandler.h"
#include "NNClassifier.h"
#include "KNNClassifier.h"
#include "AnotherClassifier.h"
#include <string>
#include <iostream>

#define TRAINING_DATA_FILE   "trainingData.txt"
#define TESTING_DATA_FILE   "testingData.txt"
#define UNKNOWN_DATA_FILE   "unknownData.txt"

#define NN    0
#define KNN   1
#define ANOTHER   2

using namespace std;

/// @brief This function takes user input
///
/// This function takes in a data points x, y and z
/// values in order, creates the datapoint, and then
/// returns it.
/// @param void
/// @return DataPoint
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
DataPoint GetDataPoint() {
    
    cout << "Please enter the data points values in order (x, y, z):" << endl;
    float x, y, z;
    cin >> x >> y >> z;
    DataPoint dp(x, y, z);
    return dp; 
}
/// @brief This function takes file name from user.
///
/// It let's user input the file name which contatins the points they want to classify
/// @param void
/// @return string
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
string GetFileName() {
    cout << "Please enter the file name which contains the points:" << endl;
    string fileName;
    cin >> fileName;
    return fileName;
}
/// @brief This function classifis a vector of data points
///
/// This function takes in a classifier pointer, (this can be
/// any class that inherits from the classifier base class),
/// and then predicts the orientation of the data points stored
/// inside of the vector 
/// @param Classifier*, vector<DataPoint>
/// @return void
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
void classify(Classifier* classifier, vector<DataPoint> data) {

    for (int i = 0; i < data.size(); i++) {
        int predictedOrientation = classifier->predict(data[i]);
        //std::cout << "Predicted orientation: " << predictedOrientation << std::endl;
    }
}

/// @brief This function classifis a given data point
///
/// This function takes in a classifier pointer, (this can be
/// any class that inherits from the classifier base class),
/// and then predicts the orientation of the given data point
/// @param DataPoint&
/// @return int
/// @author Kyle, Nathan, Ginbot 
/// @date 10/04/2024
void classify(Classifier* classifier, DataPoint data) {

    int predictedOrientation = classifier->predict(data);
    std::cout << "Predicted orientation: " << predictedOrientation << std::endl;
}

int main() {
    //Init file reader
    FileHandler reader;
    
    string test = TRAINING_DATA_FILE;
    auto trainingData = reader.readData(test);

    Classifier* models[3];
    KNNClassifier knn(trainingData);
    models[0] = new NNClassifier(trainingData);
    models[1] = new KNNClassifier(trainingData);
    models[2] = new AnotherClassifier(trainingData);


    cout << "Please select which Classifier you would like to use:" << endl;
    cout << "A) NNClassifier\nB) KNNClassifier\nC) AnotherClassifier" << endl;

    char classifierChoice;

    cin >> classifierChoice;
    
    switch (classifierChoice) {
    case('a'):
    case('A'):{
        cout << "Would you like to:" << endl;
        cout << "A) Input data point\nB) Enter file name" << endl;

        char inputChoice;
        cin >> inputChoice;

        if (inputChoice == 'A' || inputChoice == 'a') {
            DataPoint dp = GetDataPoint();
            classify(models[NN], dp);
        }
        else if (inputChoice == 'B' || inputChoice == 'b') {
            string fileName = GetFileName();
            vector<DataPoint> dp = reader.readData(fileName);
            classify(models[NN], dp);
            fileName = "result.txt";
            reader.writeData(dp, fileName);
        }
        else {
            cout << "ERROR: Incorrect input choice." << endl;
            return 1;
        }

        break;
    }
    case('b'):
    case('B'):{
        classify(models[KNN], DataPoint());
        cout << "This models is coming soon!!" << endl;
        break;
    }
    case('c'):
    case('C'): {
        classify(models[ANOTHER], DataPoint());
        cout << "This models is coming soon!!" << endl;
        break;
    }
    default:
        cout << "ERROR: Incorrect Classifier choice." << endl;
        return 1;
    }     

    return 0;
}
