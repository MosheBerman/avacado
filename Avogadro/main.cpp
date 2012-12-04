//
//  main.cpp
//  Avogadro
//
//  Created by Moshe Berman on 12/3/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include <iostream>
#include <fstream>

//
//  The max number of elements we support.
//

const int MAX_NUMBER = 130;

//
//  Function Prototypes
//

int readPeriodicTable(std::string[], int[], double[], int);
void bubbleSort(std::string[], int[], double[], int);
void printTable(std::string[], int[], double[], int);
double numberOfGramsPerMole(std::string molecularFormula);
double calculateNumberOfParticles(double, double);
double massNumberForElement(std::string);

//
//  Filestreams
//

std::ifstream inputFile;
std::ofstream outputFile;

//
//  Implementation
//

int main(int argc, const char * argv[])
{
    
    //
    //  Open file streams
    //
    
    inputFile.open("input.txt");
    outputFile.open("results.txt");
    
    if (!inputFile.is_open()) {
        std::cout << "Can't open input.txt, aborting. Take a nap and try again." << '\n';
        return 1;
    }
    
    if (!outputFile.is_open()) {
        std::cout << "Can't open output.txt, aborting. Good luck with that." << '\n';
        return 2;
    }
    
    //
    //  Declare our data Arrays...
    //
    
    std::string atomicSymbol[MAX_NUMBER];
    int atomicNumber[MAX_NUMBER];
    double atomicMass[MAX_NUMBER];
    
    //  ...and another variable to
    //  track the number of used elements.
    
    int numberOfElements = 0;
    
    //
    //  Read in the number of elements,
    //  sort them by Element, and
    //  print them out.
    //
    
    numberOfElements = readPeriodicTable(atomicSymbol, atomicNumber, atomicMass, numberOfElements);
    
    bubbleSort(atomicSymbol, atomicNumber, atomicMass, numberOfElements);
    printTable(atomicSymbol, atomicNumber, atomicMass, numberOfElements);
    
    //
    //  Declare the variables necessary for the
    //  calculation we want to prepare.
    //
    
    std::string molecularFormula = "";
    
    double weight = 0.0;
    double gramsPerMole = 0.0;
    double numberOfParticles = 0.0;
    
    //
    //  Prompt the user for a molecular formula
    //  and do stuff do it. Then take a nice nap.
    //
    
    std::cout << std::endl;
    std::cout << "Enter a molecular formula that you'd like to convert to moles. (Example: H2O)" << '\n';
    std::cin >> molecularFormula;
    std::cout << "Enter the weight in grams." << '\n';
    std::cin >> weight;
    
    //
    //  Run some complex calculations.
    //  Reticulate splines.
    //
    
    gramsPerMole = numberOfGramsPerMole(molecularFormula);
    numberOfParticles = calculateNumberOfParticles(weight, gramsPerMole);
    
    //
    //  Output the results and rejoice.
    //
    
    std::cout << "The number of molecules in ";
    std::cout << weight;
    std::cout << " grams of ";
    std::cout << molecularFormula;
    std::cout << " is ";
    std::cout << numberOfParticles;
    std::cout << "." << std::endl;
    
    outputFile << "The number of molecules in ";
    outputFile << weight;
    outputFile << " grams of ";
    outputFile << molecularFormula;
    outputFile << " is ";
    outputFile << numberOfParticles;
    outputFile << "." << std::endl;
    
    //
    //  Remember to close our files.
    //
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}

//
//  Reads in the file and splits
//  it into the appropriate arrays
//

int readPeriodicTable(std::string atomicSymbol[], int atomicNumber[], double atomicMass[], int numberOfElements){
    
    int currentElement = 0;
    
    while(!inputFile.eof()) {
        
        inputFile >> atomicSymbol[currentElement];
        inputFile >> atomicNumber[currentElement];
        inputFile >> atomicMass[currentElement];
        
        currentElement++;
    }
    
    inputFile.close();
    
    return currentElement;
}

//
//  Sort the three arrays, using the alphabetical
//  order of the array.
//

void bubbleSort(std::string atomicSymbol[], int atomicNumber[], double atomicMass[], int numberOfElements){
    
    //  A flag for optimizing the bubble sort
    bool switched = true;
    
    for(int outerPass = 0; outerPass < numberOfElements - 1 && switched == true; outerPass++){
        switched = false;
        for (int innerPass = 0; innerPass < numberOfElements - outerPass - 1; innerPass++) {
            if(atomicSymbol[innerPass] > atomicSymbol[innerPass+1]){
                
                //If we get this far, we're making a switch.
                switched = true;
                
                //  Declare some buffers
                double tempNumber;
                std::string tempSymbol;
                
                //  Switch the symbols
                tempSymbol = atomicSymbol[innerPass];
                atomicSymbol[innerPass] = atomicSymbol[innerPass+1];
                atomicSymbol[innerPass +1] = tempSymbol;
                
                //  Switch the atomic mass
                tempNumber = atomicMass[innerPass];
                atomicMass[innerPass] = atomicMass[innerPass+1];
                atomicMass[innerPass+1] = tempNumber;
                
                //  Switch the atomic number
                tempNumber = atomicNumber[innerPass];
                atomicNumber[innerPass] = atomicNumber[innerPass + 1];
                atomicNumber[innerPass+1] = tempNumber;
            }
        }
    }
}

//
//  Prints out a table of the elements in the input file.
//

void printTable(std::string atomicSymbol[], int atomicNumber[], double atomicMass[], int numberOfElements){
    
    //
    //  Print out the headers to the console
    //
    
    std::cout.width(20);
    std::cout << "Atomic Symbol";
    
    std::cout.width(20);
    std::cout << "Atomic Number";
    
    std::cout.width(20);
    std::cout << "Atomic Mass";
    
    std::cout << '\n';
    
    //
    //  Print out the headers to the output file
    //
    
    outputFile << "Atomic Symbol";
    outputFile << "Atomic Number";
    outputFile << "Atomic Mass";
    outputFile << '\n';
    
    //
    //  Loop through the file to output it.
    //
    
    for(int i = 0; i < numberOfElements; i++) {
        
        std::cout.width(20);
        std::cout << atomicSymbol[i];
        
        std::cout.width(20);
        std::cout << atomicNumber[i];
        
        std::cout.width(20);
        std::cout << atomicMass[i];
        std::cout << '\n';
        
        outputFile << atomicSymbol[i];
        outputFile << atomicNumber[i];
        outputFile << atomicMass[i] << '\n';
    }
}

//
//  Calculates the number of grams per
//  mole of a given molecule.
//

double numberOfGramsPerMole(std::string molecularFormula){
    
    //
    //  Parse the string
    //
    
    
    
    //
    //  Do the math
    //
    
    
}

//
//  Calculates the number of particles per gram
//

double calculateNumberOfParticles(double weight, double gramsPerMole){
    double particles;
    const double avogadroNumber = 6.02E23;
    
    particles = (weight/gramsPerMole) * avogadroNumber;
    
    return particles;
}

//
//  Returns the mass number given an element
//

double massNumberForElement(std::string element, std::string atomicSymbol[], double atomicMass[], int numberOfElements){
    int pos;
    bool found = false;
    for(int i = 0; i < MAX_NUMBER; i++)
        if(atomicSymbol[i] == element){
            found = true;
            pos = i;
        }
    
    if(!found){
        std::cout << "Element wasn't found in table."<< std::endl;
        return -1;
    }
    
    return atomicMass[pos];
}