#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template<class T>
void SortPointers(vector<T*> &integer)
{
	sort(integer.begin(), integer.end(), [](T *a, T *b) {return *a < *b; });
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a{ 22 };
	int *Aptr{ &a };
	int b{ 57 };
	int *Bptr{ &b };
	int c{ 24 };
	int *Cptr{ &c };
	int d{ 45 };
	int *Dptr{ &d };
	int e{ 11 };
	int *Eptr{ &e };
	cout << "Вектор до сортировки: ";
	vector<int*> integer = { Aptr, Bptr, Cptr, Dptr, Eptr };
	for (const auto &i : integer)
	{
		cout << *i << " ";
	}
	cout << endl;
	SortPointers(integer);
	cout << "Вектор после сортировки: ";
	for (const auto &i : integer)
	{
		cout << *i << " ";
	}
	return 0;
}