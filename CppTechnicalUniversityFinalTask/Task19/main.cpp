//Въвеждане на необходимите библиотеки.
#include <iostream>

using namespace std;

//Основният метод, от който стартира приложението.
int main() 
{
	//Деклариране на променливи.
	int n;
	int m;
	int elementValue;
	int maxElement;
	int maxElelementRowNumber;

	//Четене на данни от конзолата и записването им във вече декларираните променливи.
	cout << "n = " << endl;
	cin >> n;
	cout << "m = " << endl;
	cin >> m;

	//Деклариране на двумерен масив (редове).
	int ** array = new int* [n];

	//Деклариране на кулони в двумерния масив.
	for (size_t i = 0; i < n; i++)
	{
		array[i] = new int[m];
	}

	//Въвеждане на данни в двумерния масив през конзолата за всеки един елемент по отделно.
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << "Array["<<i<<","<<j<<"] = ";
			cin >> elementValue;
			array[i][j] = elementValue;
		}
		//Преминаване на следващ ред.
		cout << endl;
	}

	//Задаване на първоначална стойност на променливата maxElement.
	maxElement = array[0][0];

	//Намиране на елемента с максимална стойност и реда, в който се намира.
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			//Задаване на условие, при което променливата maxElement заема стойността на елемент от масива с по висока стойност.
			if (maxElement < array[i][j])
			{
				maxElement = array[i][j];
				maxElelementRowNumber = i;
			}
		}
	}

	//Деклариране на едномерен масив, който ще пази стойностите на реда с елемент с максимална стойност от двумерния масив.
	int * rowOfMaxElementArr = new int [m];

	//Въвеждане на данни в едномерния масив.
	for (size_t i = 0; i < m; i++)
	{
		rowOfMaxElementArr[i] = array[maxElelementRowNumber][i];
	}

	//Размяна на първи (на нулева позиция) ред и реда с максимален елемент.
	for (size_t i = 0; i < m; i++)
	{
		array[maxElelementRowNumber][i] = array[0][i];
		array[0][i] = rowOfMaxElementArr[i];
	}

	//Печатане на данни на конзолата.
	cout <<"Max element is: "<< maxElement << endl;
	cout <<"Row of max element is: "<< maxElelementRowNumber <<endl;
	cout << endl;

	//Печатане на двумерния масив.
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << array[i][j] << ", ";
		}
		//Преминаване на следващ ред.
		cout << endl;
	}

	//За предотвратяване на автоматичното затваряне на конзолния прозорец след приключване на програмата.
	cin >> n;

	//Връщане на изходна стойност на програмата.
	return 0;
}