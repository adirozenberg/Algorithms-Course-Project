#include "CheckInput.h"

// this function get and check vertices and edges numbers from readFile
void GetAndCheckFirstNumbersFromFile(ifstream& i_ReadFile, ofstream& i_WriteFile, int& i_InputFromFile)
{
	string tmpLine;

	getline(i_ReadFile, tmpLine);
	// if empty line
	if (tmpLine == "")
		InvalidInput(i_WriteFile);

	stringstream tmpStrOfInput(tmpLine);
	tmpStrOfInput >> i_InputFromFile;

	if (i_InputFromFile <= 0 || !tmpStrOfInput.eof()) // negative or decimal number
		InvalidInput(i_WriteFile);
}

// this function get and check lines of edges (edge u->v with weight) from readFile
void GetAndCheckUVAndWeightFromFile(ifstream& i_ReadFile, ofstream& i_WriteFile, bool& i_RemovedEdgeIsExist,
	int i_NumOfVertices, int i_NumOfEdges, int& i_CountEdge, vector<Edge>& i_TmpEdgeVec, Graph& i_Graph, int& i_DeletedU, int& i_DeletedV) {

	string tmpLine;

	while (getline(i_ReadFile, tmpLine))
	{
		// if there are empty line in file
		if (tmpLine == "")
			InvalidInput(i_WriteFile);

		// if there are more lines than expected
		if (i_RemovedEdgeIsExist)
			InvalidInput(i_WriteFile);

		int u, v, weight;
		string weightString;
		stringstream tmpStr(tmpLine);

		tmpStr >> u;

		// if u is negative or higher than range of vertices
		if (u <= 0 || u > i_NumOfVertices)
			InvalidInput(i_WriteFile);

		if (tmpStr.eof()) // if no more data in line
			InvalidInput(i_WriteFile);
		tmpStr >> v;
		
		// if v is negative or higher than range of vertices
		if (v <= 0 || v > i_NumOfVertices)
			InvalidInput(i_WriteFile);

		//reduce u and v in one because of the arrays starts by index 0, 
		//and the entered vertices starts by index 1
		u = u - 1;
		v = v - 1;

		if (i_CountEdge == i_NumOfEdges)
		{
			i_DeletedU = u;
			i_DeletedV = v;
			i_RemovedEdgeIsExist = true; // last line we need to get from file
		}
		else
		{
			tmpStr >> weightString;
			if(weightString.empty()) // no weight in line
				InvalidInput(i_WriteFile);

			CheckIfStringCanConvertToInt(weightString, i_WriteFile);
			weight = stoi(weightString);

			// if there are a decimal number detail in file
			if (!tmpStr.eof())
				InvalidInput(i_WriteFile);

			i_TmpEdgeVec.push_back(Edge(u, v, weight)); // vector of edges for KRUSKAL algorithm
			i_Graph.AddEdge(u, v, weight); // adjacency list for PRIM algorithm
			i_CountEdge++;

			if (i_CountEdge > i_NumOfEdges)
				InvalidInput(i_WriteFile);
		}
	}
}

void CheckIfStringCanConvertToInt(string i_Str, ofstream& i_WriteFile)
{
	if (!CheckIfStrContainsDigitsOnly(i_Str) || i_Str.empty())
		InvalidInput(i_WriteFile);
}

bool CheckIfStrContainsDigitsOnly(string i_Str)
{
	int lengthOfStr = i_Str.length();
	for (int i = 0; i < lengthOfStr; i++)
	{
		if (!isdigit(i_Str[i]))
			return false;
	}

	return true;
}

// this function search for the right edge to erase from tmpEdgeVec vector
void FindEdgeToErase(int i_NumOfEdges, vector<Edge>& i_TmpEdgeVec, int i_DeletedU, int i_DeletedV)
{
	for (int i = 0; i < i_NumOfEdges; i++)
	{
		if ((i_TmpEdgeVec[i].GetVertexU() == i_DeletedU && i_TmpEdgeVec[i].GetVertexV() == i_DeletedV) || (i_TmpEdgeVec[i].GetVertexU() == i_DeletedV && i_TmpEdgeVec[i].GetVertexV() == i_DeletedU))
		{
			// delete edge from vector of edges
			i_TmpEdgeVec.erase(i_TmpEdgeVec.begin() + i);
			break;
		}
	}
}