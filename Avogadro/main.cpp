//
//  main.cpp
//  Avogadro
//
//  Created by Moshe Berman on 12/3/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//

#include <iostream>

//
//  Data Arrays
//

const int MAX_NUMBER = 130;

std::string atomicSymbol[MAX_NUMBER];
int atomicNumber[MAX_NUMBER];
double atomicWeight[MAX_NUMBER];

//
//  Function Prototypes
//

void bubbleSort(std::string[], int, double, int);
void printTable(std::string[], int, double, int);
double numberOfGramsPerMole(std::string molecularFormula);
double calculateNumberOfParticles(double, double);
double massNumberForElement(std::string);

//
//
//

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

