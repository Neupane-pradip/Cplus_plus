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
#include <set>
#include <algorithm>

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

// Function to compare strings for sorting
// Returns true if the first string is lexicographically less than the second
bool compareStrings(const string& a, const string& b) {
    return a < b;
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

// Function to display all locations
void displayLocations(const CourseInfo& courseData) {
    vector<string> locations;
    // Extract all unique locations from the course data
    for (const auto& entry : courseData) {
        if (find(locations.begin(), locations.end(), entry.first.first) == locations.end()) {
            locations.push_back(entry.first.first);
        }
    }
    // Sort and display the locations in alphabetical order
    sort(locations.begin(), locations.end(), compareStrings);
    for (const auto& location : locations) {
        cout << location << endl;
    }
}

// Function to display courses in a specific location and theme
void displayCourses(const CourseInfo& courseData, const string& location, const string& theme) {
    bool found = false;
    bool locationFound = false;
    bool themeFound = false;

    // Iterate through the course data to find matching courses
    for (const auto& entry : courseData) {
        if (entry.first.first == location) {
            locationFound = true;
            if (entry.first.second.first == theme) {
                found = true;
                // Display the course name and enrollment status
                cout << entry.first.second.second << " --- ";
                if (entry.second == 50) {
                    cout << "full" << endl;
                } else {
                    cout << entry.second << " enrollments" << endl;
                }
            }
        } else if (!locationFound) {
            themeFound = (entry.first.second.first == theme);
        }
    }

    // Provide feedback based on the search results
    if (!locationFound) {
        cout << "Error: unknown location name" << endl;
    } else if (!found && !themeFound) {
        cout << "Error: unknown theme" << endl;
    }
}

// Function to display available courses
void displayAvailableCourses(const CourseInfo& courseData) {
    // Iterate through the course data and display courses with less than 50 enrollments
    for (const auto& entry : courseData) {
        if (entry.second < 50) {
            cout << entry.first.first << " : " << entry.first.second.first << " : " << entry.first.second.second << endl;
        }
    }
}

// Function to display the favorite theme based on enrollments
void displayFavoriteTheme(const CourseInfo& courseData) {
    map<string, int> themeEnrollments;
    int maxEnrollments = 0;

    // Calculate the total enrollments for each theme
    for (const auto& entry : courseData) {
        themeEnrollments[entry.first.second.first] += entry.second;
        if (themeEnrollments[entry.first.second.first] > maxEnrollments) {
            maxEnrollments = themeEnrollments[entry.first.second.first];
        }
    }

    // Display the favorite theme(s)
    if (themeEnrollments.empty()) {
        cout << "No enrollments" << endl;
    } else {
        cout << maxEnrollments << " enrollments in themes" << endl;
        for (const auto& theme : themeEnrollments) {
            if (theme.second == maxEnrollments) {
                cout << "--- " << theme.first << endl;
            }
        }
    }
}

// Function to display courses in a specific theme
void displayCoursesInTheme(const CourseInfo& courseData, const string& theme) {
    set<string> uniqueCourses;

    // Extract all unique courses in the specified theme
    for (const auto& entry : courseData) {
        if (entry.first.second.first == theme) {
            uniqueCourses.insert(entry.first.second.second);
        }
    }

    // Display the courses or provide feedback if none are found
    if (uniqueCourses.empty()) {
        cout << "Error: unknown theme" << endl;
    } else {
        for (const auto& course : uniqueCourses) {
            cout << course << endl;
        }
    }
}


int main() {
    string inputFileName;
    cout << "Input file: ";
    getline(cin, inputFileName);

    CourseInfo courseData = readFile(inputFileName);

    while (true) {
        cout << "> ";
        string command;
        getline(cin, command);
        vector<string> commandParams = splitString(command, ' ');

        if (commandParams[0] == "quit") {
            break;
        }
        else if (commandParams[0] == "locations") {
                 displayLocations(courseData);
                }
                else if (commandParams[0] == "themes_in_location") {
            if (commandParams.size() != 2) {
                cout << "Error: error in command themes_in_location" << endl;
                continue;
            }

            string location = commandParams[1];
            set<string> uniqueThemes;

            // Extract all unique themes for the specified location
            for (const auto& entry : courseData) {
                if (entry.first.first == location) {
                    uniqueThemes.insert(entry.first.second.first);
                }
            }

            // Display the themes or provide feedback if none are found
            if (uniqueThemes.empty()) {
                cout << "Error: unknown location" << endl;
            } else {
                for (const auto& theme : uniqueThemes) {
                    cout << theme << endl;
                }
            }

                }

                else if (commandParams[0] == "courses") {
            if (commandParams.size() < 3) {
                cout << "Error: error in command courses" << endl;
                continue;
            }

            string location = commandParams[1];
            // Assuming the theme is always the third parameter
            string theme = commandParams[2];

            // Remove quotes if present
            if (theme.front() == '\"' && theme.back() == '\"') {
                theme = theme.substr(1, theme.size() - 2);
            }

            displayCourses(courseData, location, theme);
        }

        else if (commandParams[0] == "courses_in_theme") {
            if (commandParams.size() != 2) {
                cout << "Error: error in command courses_in_theme" << endl;
                continue;
            }

            string theme = commandParams[1];
            displayCoursesInTheme(courseData, theme);

                }

                else if (commandParams[0] == "favorite_theme") {
                displayFavoriteTheme(courseData);

                }

                else if (commandParams[0] == "available") {
                 displayAvailableCourses(courseData);
                }
                else {
                    cout << "Error: Unknown command: " << commandParams[0] << endl;
                }

    }

    return 0;
}
