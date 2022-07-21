#ifndef UTILLS_H
#define UTILLS_H

using namespace std;
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "Edge.h"

// quick sort functions
void QuickSort(vector<Edge>& i_Edges, int i_Start, int i_End);

int  Partition(vector<Edge>& i_Edges, int i_Start, int i_End);

// print message to screen or file functions
void InvalidInput(ofstream& i_WriteFile);

void PrintNoMSTMessageToScreen();

void PrintNoMSTMessageToFile(ofstream& i_WriteFile);

#endif