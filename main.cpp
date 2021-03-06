#include "Vector3D.h"
#include <iostream>

using namespace std;

//For operations + or -
void sum_or_subtr_vec(unsigned int &n, char operation, Vector3D* &vectors) 
{
	Vector3D v = vectors[0]; //Vector to be added to or subtracted from

	for (unsigned int i = 1; i < n; i++)
	{
		switch (operation) 
		{
		case '+':
			v = v + vectors[i];
			break;
		case '-':
			v = v - vectors[i];
			break;
		default:
			break;
		}
	}

	delete[] vectors; //Clean up the other vectors that we don't need anymore
	vectors = new Vector3D[1]; //New array with only one vector as a result of the operation
	vectors[0] = v;
	n = 1; //Change the size of the array passed to the print function
}

//For operations *NUM/NUM*/NEG
void neg_or_mult_vec(unsigned int n, char* operation, Vector3D* &vectors) 
{
	for (unsigned int i = 0; i < n; i++)
	{
		if (!strcmp(operation, "NEG"))
			vectors[i] = -vectors[i]; //Negate all n vectors
		else if (operation[0] == '*')
			vectors[i] = vectors[i]*atof(&operation[1]); //Multiply all n vectors by a num
		else if (operation[1] == '*' //Example: 2*
			|| operation[2] == '*' //Example: 20*
			|| operation[3] == '*' //Example: 200*
			|| operation[4] == '*') //Example: 1000*
			vectors[i] = vectors[i]*atof(operation); //Myltiply a num [0,1000] by all n vectors
	}
}

void input_vectors(unsigned int n, Vector3D* &vectors) 
{
	for (unsigned int i = 0; i < n; i++)
		cin >> vectors[i];
}

void print_vectors(unsigned int n, Vector3D* &vectors) 
{
	for (unsigned int i = 0; i < n; i++) 
		cout << vectors[i] << " ";

	cout << endl;
}

int main()
{
	char operation[6]; //Assume 1000* as max length for operation
	unsigned int n; //Number of vectors

	cin >> operation;
	cin >> n;

	if (n != 0) //If n=0, then the output would be empty
	{
		Vector3D* vectors = new Vector3D[n]; //Container for vectors
		input_vectors(n, vectors);

		if (operation[0] != '+' && operation[0] != '-')
			neg_or_mult_vec(n, operation, vectors);
		else
			sum_or_subtr_vec(n, operation[0], vectors); //In this case only one char '+'/'-' contains the operation info

		print_vectors(n, vectors);

		delete[] vectors; //Program execution complete, clean up memory
	}

	system("pause");
    return 0;
}

