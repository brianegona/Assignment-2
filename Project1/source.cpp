#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
#ifdef PRE_RELEASE
    std::string email;
#endif
};

int main() {
    std::vector<STUDENT_DATA> students;

    // Print the mode (standard or pre-release)
#ifdef PRE_RELEASE
    std::cout << "Running Pre-Release version" << std::endl;
#else
    std::cout << "Running Standard version" << std::endl;
#endif

    // Open the StudentData.txt file
    std::ifstream inputFile("StudentData.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file StudentData.txt";
        return 1; // Return an error code
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string firstName, lastName;
        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName)) {
            STUDENT_DATA student = { firstName, lastName };
            students.push_back(student);
        }
    }
    inputFile.close();

    // Print student info in debug mode
#ifdef _DEBUG
    for (const auto& student : students) {
        std::cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << std::endl;
    }
#endif

    // Pre-release functionality to read StudentData_Emails.txt
#ifdef PRE_RELEASE
    // Open the StudentData_Emails.txt file
    std::ifstream emailFile("StudentData_Emails.txt");
    if (!emailFile) {
        std::cerr << "Unable to open file StudentData_Emails.txt";
        return 1; // Return an error code
    }

    size_t index = 0;
    while (std::getline(emailFile, line) && index < students.size()) {
        std::istringstream ss(line);
        std::string email;
        if (std::getline(ss, students[index].firstName, ',') && std::getline(ss, students[index].lastName, ',') && std::getline(ss, email)) {
            students[index].email = email;
        }
        index++;
    }
    emailFile.close();

    // Print student info with emails
    for (const auto& student : students) {
        std::cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << ", Email: " << student.email << std::endl;
    }
#endif

    return 0; // Successful completion
}
