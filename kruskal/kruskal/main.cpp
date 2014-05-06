#include <iostream>
#include <cmath>
#include "CKruskal.cpp"

using namespace std;

int main()
{
	CKruskal* k = new CKruskal();
	//int n = 10;
	//double p1 = 3 * log(n) / log(2) / ((double)n);
	//double p2 = pow(n, (-1 / 3.0));
	//k->randomGraph(10, 3 * log(n) / log(2) / ((double)n));
	k->readGraph();
	k->showGraph();
	cout << "----------------------" << endl;
	k->showGraph(k->minTree(0));

	system("pause");
	return 0;
}