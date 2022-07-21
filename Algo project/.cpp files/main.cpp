#include "Utills.h"
#include "KruskalAlgorithm.h"
#include "Graph.h"
#include "PrimAlgorithm.h"
#include "CheckInput.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>


int main(int argc, char* argv[])
{
	ifstream readFile;
	ofstream writeFile;
	readFile.open(argv[1]);
	writeFile.open(argv[2]);
	vector<Edge> tmpEdgeVec;
	bool removedEdgeIsExist = false;
	int numOfVertices, numOfEdges, countEdge = 0, kruskalResult = 0, primResult = 0, deletedU = 0, deletedV = 0;

	// get and check number of vertices
	GetAndCheckFirstNumbersFromFile(readFile, writeFile, numOfVertices);

	// get and check number of edges
	GetAndCheckFirstNumbersFromFile(readFile, writeFile, numOfEdges);

	Graph graph(numOfVertices);
	Kruskal kruskal(numOfVertices, numOfEdges);
	Prim prim(numOfVertices);

	GetAndCheckUVAndWeightFromFile(readFile, writeFile, removedEdgeIsExist, numOfVertices, numOfEdges, countEdge,
		tmpEdgeVec, graph, deletedU, deletedV);
	
	// if removed edge is not exists
	if (!graph.IsAdjacent(deletedU, deletedV))
		InvalidInput(writeFile);

	// graph is not connected
	if (!graph.IsConnectedGraph())
	{
		PrintNoMSTMessageToScreen();
		PrintNoMSTMessageToFile(writeFile);
		exit(1);
	}

	// entered number of edges is higher than edges lines in file
	if (countEdge < numOfEdges)
		InvalidInput(writeFile);

	QuickSort(tmpEdgeVec, 0, int(tmpEdgeVec.size() - 1)); //quick sort
	kruskal.SetEdges(tmpEdgeVec);

	kruskalResult = kruskal.RunKruskalAlgorithm();
	primResult = prim.RunPrimAlgorithm(graph);

	cout << "Kruskal <" << kruskalResult << ">" << endl;
	cout << "Prim <" << primResult << ">" << endl;

	writeFile << "Kruskal " << kruskalResult << "\n";
	writeFile << "Prim " << primResult << "\n";

	if (graph.IsBridgeInGraph(deletedU, deletedV))
	{
		cout << "Kruskal No MST";
		writeFile << "Kruskal2 No MST \n";
	}
	else
	{
		FindEdgeToErase(numOfEdges, tmpEdgeVec, deletedU, deletedV);

		// new Kruskal without deletedU -> deletedV edge
		Kruskal kruskalWithoutEdge(numOfVertices, numOfEdges - 1);
		kruskalWithoutEdge.SetEdges(tmpEdgeVec);
		kruskalResult = kruskalWithoutEdge.RunKruskalAlgorithm();
		cout << "Kruskal <" << kruskalResult << ">" << endl;
		writeFile << "Kruskal2 " << kruskalResult << "\n";
	}
	
	readFile.close();
	writeFile.close();
}