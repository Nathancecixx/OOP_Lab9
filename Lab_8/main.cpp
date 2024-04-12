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

datapoint GetDataPoint() {
    
    cout << "Please enter the data points values in order (x, y, z):" << endl;
    float x, y, z;
    cin >> x >> y >> z;
    datapoint dp(x, y, z);
    return dp; 
}

string GetFileName() {
    cout << "Please enter the file name which contains the points:" << endl;
    string fileName;
    cin >> fileName;
    return fileName;
}

void classify(classifier* classifier, vector<datapoint> data) {

    for (int i = 0; i < data.size(); i++) {
        int predictedOrientation = classifier->predict(data[i]);
        //std::cout << "Predicted orientation: " << predictedOrientation << std::endl;
    }
}

void classify(classifier* classifier, datapoint data) {

    int predictedOrientation = classifier->predict(data);
    std::cout << "Predicted orientation: " << predictedOrientation << std::endl;
}

int main() {
    //Init file reader
    FileHandler reader;
    
    string test = TRAINING_DATA_FILE;
    auto trainingData = reader.readData(test);

    classifier* models[3];
    KNNClassifier knn(trainingData);
    models[0] = new NNClassifier(trainingData);
    models[1] = new KNNClassifier(trainingData);
    models[2] = new AnotherClassifier(trainingData);


    cout << "Please select which classifier you would like to use:" << endl;
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
            datapoint dp = GetDataPoint();
            classify(models[NN], dp);
        }
        else if (inputChoice == 'B' || inputChoice == 'b') {
            string fileName = GetFileName();
            vector<datapoint> dp = reader.readData(fileName);
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
        classify(models[KNN], datapoint());
        cout << "This models is coming soon!!" << endl;
        break;
    }
    case('c'):
    case('C'): {
        classify(models[ANOTHER], datapoint());
        cout << "This models is coming soon!!" << endl;
        break;
    }
    default:
        cout << "ERROR: Incorrect classifier choice." << endl;
        return 1;
    }     

    return 0;
}
