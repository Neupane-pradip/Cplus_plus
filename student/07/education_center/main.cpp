/*  COMP.CS.110 Project 2: Education center
 *
 *
 * Name: Pradip Neupane
 * Student number: 150426327
 * UserID: nbprne
 * E-Mail: pradip.neupane@tuni.fi
 * Feedback language (fi/en): en
 *
 * This project involves creating a program to manage and search course data from various education centers
 * stored in a CSV file. Initially, the program reads the course data from the input file and stores it usi
 * ng an appropriate data structure, such as a map. It then offers a user interface where users can search
 * for courses based on location, theme, or enrollment status. Commands include listing locations, themes
 * within a location, courses in a specific location and theme, finding available courses, identifying cou
 * rses under a theme across all locations, and determining the favourite theme by enrollments. Error
 * handling is included to manage invalid user input or missing data in the input file.
 *
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Data structure to store course information
// Each course is identified by a pair of strings (location and
// theme) and an integer (enrollments)
using CourseInfo = map<pair<string, pair<string, string>>, int>;

struct Course {
    string name;
    string theme;
    int enrollments;
};

// Function to split a string by a delimiter
// Returns a vector of substrings
vector<string> splitString(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;

    // Split the string by the delimiter and store each substring in the result vector
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}


// Function to read course data from a file
// Returns a CourseInfo map populated with the course data
CourseInfo readFile(const string& fileName) {
    ifstream inputFile(fileName);
    CourseInfo courseData;

    // Check if the file was successfully opened
    if (!inputFile) {
        cout << "Error: the input file cannot be opened" << endl;
        return courseData; // Return an empty map on failure
    }

    string line;
    vector<string> dataRow;

    // Read each line of the file
    while (getline(inputFile, line)) {
        dataRow = splitString(line, ';');
        // Check if the line contains all required fields
        if (dataRow.size() < 4) {
            cout << "Error: empty field" << endl;

            // Return an empty map on failure
            return courseData;
        }

        Course courseEntry;
        courseEntry.name = dataRow[2];
        courseEntry.theme = dataRow[1];
        // Convert enrollments to an integer, defaulting to 50 if "full"
        courseEntry.enrollments = (dataRow[3] == "full") ? 50 : stoi(dataRow[3]);

        // Create a key for the course using location, theme, and name
        pair<string, pair<string, string>> courseKey = {dataRow[0], {courseEntry.theme, courseEntry.name}};
        // Insert or update the course data in the map
        auto it = courseData.find(courseKey);
        if (it == courseData.end()) {
            courseData.insert({courseKey, courseEntry.enrollments});
        } else {
            it->second = courseEntry.enrollments;
        }
    }

    inputFile.close();
    return courseData;
}
