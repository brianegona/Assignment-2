#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};


int main() {
    // Create a vector to hold student data
    std::vector<STUDENT_DATA> students;

    // Open the file
    std::ifstream inputFile("StudentData.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file StudentData.txt";
        return 1; // Return an error code
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Create a string stream to parse the line
        std::istringstream ss(line);
        std::string firstName, lastName;

        // Get the first and last names, separated by a comma
        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName)) {
            // Create a STUDENT_DATA object and add it to the vector
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
    }

    // Close the file
    inputFile.close();

    // this was used for debugging; Print student information for verification (can be removed later)
    /*for (const auto& student : students) {
        std::cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << std::endl;
    }*/

    return 0; // Successful completion
}
