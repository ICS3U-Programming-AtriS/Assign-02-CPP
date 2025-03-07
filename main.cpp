// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: March 6, 2025
// The Calculator Calculator

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

// Input validation
int intInput(std::string prompt, int minimum) {
    int res;
    // Keep Looping until input is valid
    while (true) {
        std::cout << "\033[0m" << std::endl;  // WHITE TEXT
        std::cout << prompt;
        std::cin >> res;
        if (res >= minimum) {
            return res;
        } else {
            std::cout << "\033[0;31m";  // RED TEXT
            std::cout << "Value must be a positive integer greater than ";
            std::cout << minimum;
            // Reset cin
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

// Function For Getting the Shape Type
std::string getShapeType() {
    std::string res;
    // Keep Looping until input is valid
    while (true) {
        std::cout << "\033[0m" << std::endl;  // WHITE TEXT
        std::cout << "[CASE-SENSITIVE] Type? (Prism/Pyramid): ";
        std::cin >> res;
        if (res == "Prism" || res == "Pyramid") {
            return res;
        } else {
            std::cout << "\033[0;31m";  // RED TEXT
            std::cout << "Not a valid option!";
        }
    }
}

std::string volumeFormula(std::string shape) {
    // length represents base length
    // height represents height
    std::string fullFormula;
    if (shape == "Prism") {
        fullFormula = "baseArea * height";
    } else if (shape == "Pyramid") {
        fullFormula = "baseArea * height * (1.0/3.0)";
    }
    return fullFormula;
}

std::string surfaceAreaFormula(std::string shape, int sideAmount) {
    // length represents base length
    // height represents height
    // n represents the side amount
    std::string fullFormula;
    std::string n = std::to_string(sideAmount);
    if (shape == "Prism") {
        fullFormula = "(2*baseArea) + (length*" + n + "*height)";
    } else if (shape == "Pyramid") {
        std::string slantFormula = "sqrt(pow(height,2) + pow("
        "length*0.5*"+std::to_string(tan((0.5 - 1.0/sideAmount)*M_PI))+
        ",2))";
        fullFormula = "baseArea + (length*"+n+"*0.5*"+slantFormula+")";
    }
    return fullFormula;
}

// Creates the code
std::string generateCode(int sideAmount, std::string shape, std::string unit) {
    time_t timestamp = time(NULL);
    struct tm datetime;
    localtime_r(&timestamp, &datetime);
    std::string months[] = {"Jan",
                        "Feb",
                        "March",
                        "April",
                        "May",
                        "June",
                        "July",
                        "August",
                        "September",
                        "October",
                        "November",
                        "December",
    };
    std::string month = months[datetime.tm_mon];
    std::string dayInMonth = std::to_string(datetime.tm_mday);
    std::string year = std::to_string(1900 + datetime.tm_year);

    std::string n = std::to_string(sideAmount);
    std::string res =
        "// Generated by https://github.com/"
        "ICS3U-Programming-AtriS/Assign-02-CPP"
        "\n// Date: " +
        month + " " + dayInMonth + ", " + year +
        "\n// Calculator for the Volume and Surface Area of a"
        "\n// Regular " +
        n + "-sided polygonal " + shape +
        "\n"
        "\n#include <iostream>"
        "\n#include <string>"
        "\n#include <cmath>"
        "\n"
        "\n// Function that makes sure input is a positive number"
        "\nfloat validInput(std::string prompt) {"
        "\n    float res;"
        "\n    while (true) {"
        "\n        std::cout << \"\\033[0m\" << std::endl;  // WHITE TEXT"
        "\n        std::cout << prompt;"
        "\n        std::cin >> res;"
        "\n        if (res > 0) {"
        "\n            return res;"
        "\n        } else {"
        "\n        std::cout << \"\\033[0;31m\";  // RED TEXT;"
        "\n        std::cout << \"Value must be a positive integer\";"
        "\n        // Reset cin"
        "\n        std::cin.clear();"
        "\n        std::cin.ignore();"
        "\n        }"
        "\n    }"
        "\n}"
        "\n"
        "\nint main() {"
        "\n    // Introduction"
        "\n    std::cout << \"\\033[0;34m\";  // BLUE TEXT"
        "\n    std::cout << \"This program calculates the Volume"
        " and Surface area\";"
        "\n    std::cout << std::endl;"
        "\n    std::cout << \"Of a Regular " +
        n + "-sided polygonal " + shape +
        "\";"
        "\n    std::cout << std::endl;"
        "\n"
        "\n    // Input"
        "\n    // Get side length (length of the base sides)"
        "\n    float length = validInput(\"Enter base length(" +
        unit +
        "): \");"
        "\n    // Get height"
        "\n    float height = validInput(\"Enter height(" +
        unit +
        "): \");"
        "\n"
        "\n    // Process"
        "\n    // Calculate the Area of the Base"
        " [Used for simplifying calculations]"
        "\n    float baseArea = " +
        std::to_string(sideAmount) +
        " * (1.0/4.0) * pow(length, 2) * " +
        std::to_string(tan((0.5 - 1.0 / sideAmount) * M_PI)) +
        ";"
        "\n    // Calculate the Volume"
        "\n    float volume = " +
        volumeFormula(shape) +
        ";"
        "\n    // Calculate the Surface Area"
        "\n    float surfaceArea = " +
        surfaceAreaFormula(shape, sideAmount) +
        ";"
        "\n"
        "\n    // Output"
        "\n    std::cout << \"\\033[0;32m\";  // GREEN TEXT"
        "\n    std::cout << \"The Volume is \";"
        "\n    std::cout << round(volume * 100) / 100;"
        "\n    std::cout << \"" +
        unit +
        "\u00b3\" << std::endl;"
        "\n    std::cout << \"The Surface Area is \";"
        "\n    std::cout << round(surfaceArea * 100) / 100;"
        "\n    std::cout << \"" +
        unit +
        "\u00b2\" << std::endl;"
        "\n    std::cout << \"\\033[0m\";  // WHITE TEXT"
        "\n}"
        "\n";
    return res;
}

int main() {
    // Welcome Message
    std::cout << "\033[0;34m";  // BLUE TEXT
    std::cout << "Welcome to the ";
    std::cout << "NSRPCPFBWAMNSRPCPTSAPIOOTTVOAPWTSDAABMPCPLTHMTMPCP ";
    std::cout << "(N-Sided Regular Prism Calculator Program Factory ";
    std::cout << "But We Also Make N-Sided Pyramid Calculator Programs Too ";
    std::cout << "Since A Pyramid Is Only One Third The Volume ";
    std::cout << "Of A Prism With The Same Dimensions And Also Because Making ";
    std::cout << "Pyramid Calculator Programs Leads To Higher Margins ";
    std::cout << "Than Making Prism Calculator Programs)! ";
    std::cout << "Let's make a calculator program!";

    // INPUT
    // Ask User for amount of sides in the base
    int sideAmount = intInput("Enter the amount of sides in the base: ", 3);

    // Ask User for type of shape(prism / pyramid)
    std::string shapeType = getShapeType();

    // Ask User for the unit Type [It can be anything]
    std::string unitType;
    std::cout << "Units? (cm,km,mm,etc.): ";
    std::cin >> unitType;

    // Generate the code
    std::string generatedCode = generateCode(sideAmount, shapeType, unitType);

    // OUTPUT
    // Output file stream
    std::fstream ofs;
    std::string outputFilePath =
    "/home/vscode/ICS3U/Assign/Assign-02/Assign-02-CPP/OUTPUT/outputCode.cpp";
    // Open file and make it empty
    ofs.open(outputFilePath, std::ios::out | std::ios::trunc);
    // Write code to file
    ofs << generatedCode;
    // close file
    ofs.close();
}
