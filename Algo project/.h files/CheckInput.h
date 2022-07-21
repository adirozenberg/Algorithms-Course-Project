#ifndef CHECKINPUT_H
#define CHECKINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Utills.h"
#include "Graph.h"
using namespace std;

// this header file contains functions that get and check data from readFile

void GetAndCheckFirstNumbersFromFile(ifstream& i_ReadFile, ofstream& i_WriteFile, int& i_InputFromFile);

void GetAndCheckUVAndWeightFromFile(ifstream& i_ReadFile, ofstream& i_WriteFile, bool& i_RemovedEdgeIsExist,
	int i_NumOfVertices, int i_NumOfEdges, int& i_CountEdge, vector<Edge>& i_TmpEdgeVec, Graph& i_Graph, int& i_DeletedU, int& i_DeletedV);

void FindEdgeToErase(int i_NumOfEdges, vector<Edge>& i_TmpEdgeVec, int i_DeletedU, int i_DeletedV);

void CheckIfStringCanConvertToInt(string i_Str, ofstream& i_WriteFile);

bool CheckIfStrContainsDigitsOnly(string i_Str);

#endif