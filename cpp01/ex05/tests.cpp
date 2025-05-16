#include <iostream>
#include "Harl.hpp"

void printDivider() {
    std::cout << "\n---------------------------------------------------\n";
}

void runTest(const std::string& testName, void (*testFunc)()) {
    printDivider();
    std::cout << "TEST: " << testName << std::endl;
    printDivider();
    testFunc();
}

void testIndividualLevels() {
    Harl harl;
    
    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\nTesting INFO level:" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\nTesting WARNING level:" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\nTesting ERROR level:" << std::endl;
    harl.complain("ERROR");
}

void testInvalidLevel() {
    Harl harl;
    
    std::cout << "Testing invalid level 'CRITICAL':" << std::endl;
    harl.complain("CRITICAL");
    
    std::cout << "\nTesting empty level:" << std::endl;
    harl.complain("");
}

void testComplaintSequence() {
    Harl harl;
    
    std::cout << "Simulating a typical customer complaint sequence:" << std::endl;
    harl.complain("INFO");    
    harl.complain("WARNING"); 
    harl.complain("ERROR");
    harl.complain("DEBUG");
}

void testRepetitiveComplaints() {
    Harl harl;
    
    std::cout << "Harl complaining with the same level multiple times:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "\nComplaint #" << (i + 1) << ": ";
        harl.complain("WARNING");
    }
}

void testMultipleInstances() {
    std::cout << "Different Harl instances complaining:" << std::endl;
    
    std::cout << "\nHarl #1:" << std::endl;
    Harl harl1;
    harl1.complain("DEBUG");
    
    std::cout << "\nHarl #2:" << std::endl;
    Harl harl2;
    harl2.complain("ERROR");
}

int main() {
    std::cout << "===== HARL COMPLAINT TESTS =====" << std::endl;
    
    runTest("Individual Complaint Levels", testIndividualLevels);
    runTest("Invalid Complaint Levels", testInvalidLevel);
    runTest("Complaint Sequence", testComplaintSequence);
    runTest("Repetitive Complaints", testRepetitiveComplaints);
    runTest("Multiple Harl Instances", testMultipleInstances);
    
    printDivider();
    std::cout << "All tests completed. Harl certainly complains a lot!" << std::endl;
    
    return 0;
}
