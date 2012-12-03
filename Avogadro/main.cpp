//
//  main.cpp
//  Avogadro
//
//  Created by Moshe Berman on 12/3/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include <iostream>

//
//  Function Prototypes
//

void bubbleSort(std::string[], int[], double[], int);
void printTable(std::string[], int[], double[], int);
double numberOfGramsPerMole(std::string molecularFormula);
double calculateNumberOfParticles(double, double);
double massNumberForElement(std::string);

//
//  Implementation
//

int main(int argc, const char * argv[])
{

    //
    //  Data Arrays
    //
    
    const int MAX_NUMBER = 130;
    
    std::string atomicSymbol[MAX_NUMBER];
    int atomicNumber[MAX_NUMBER];
    double atomicWeight[MAX_NUMBER];
    
    // insert code here...
    
    return 0;
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

void printTable(std::string atomicSymbol[], int atomicNumber[], double atomicMass[], int numberOfElements){
    
}

double numberOfGramsPerMole(std::string molecularFormula){
    
}

double calculateNumberOfParticles(double, double){
    
}

double massNumberForElement(std::string element, std::string atomicSymbol[], double atomicMass[], int numberOfElements){
    
}