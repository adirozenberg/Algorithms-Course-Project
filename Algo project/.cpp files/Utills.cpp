#include "Utills.h"

void InvalidInput(ofstream& i_WriteFile) {

    cout << "invalid input" << endl;
    i_WriteFile << "invalid input";
    exit(1);
}

void PrintNoMSTMessageToScreen() {
    cout << "Kruskal No MST" << endl;
    cout << "Prim No MST" << endl;
    cout << "Kruskal No MST" << endl;
}

void PrintNoMSTMessageToFile(ofstream& i_WriteFile) {
    i_WriteFile << "Kruskal No MST\n";
    i_WriteFile << "Prim No MST\n";
    i_WriteFile << "Kruskal No MST\n";
}

void QuickSort(vector<Edge>& i_Edges, int i_Start, int i_End)
{
    if (i_Start >= i_End)
        return;

    int pivot = Partition(i_Edges, i_Start, i_End);
    QuickSort(i_Edges, i_Start, pivot - 1);
    QuickSort(i_Edges, pivot + 1, i_End);
}

int Partition(vector<Edge>& i_Edges, int i_Start, int i_End)
{
    int pivot, count = 0, pivotIndex = 0, i, j;
    pivot = i_Edges[i_Start].GetWeight();

    for (int i = i_Start + 1; i <= i_End; i++)
        if (i_Edges[i].GetWeight() <= pivot)
            count++;
   
    pivotIndex = i_Start + count;
    swap(i_Edges[pivotIndex], i_Edges[i_Start]);

    i = i_Start;
    j = i_End;

    while (i < pivotIndex && j > pivotIndex) {

        while (i_Edges[i].GetWeight() <= pivot) {
            i++;
        }

        while (i_Edges[j].GetWeight() > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(i_Edges[i++], i_Edges[j--]);
        }
    }

    return pivotIndex;
}