#include <iostream>
using namespace std;
template<class T>
void Swap(T *first, T *second)
{
	T temp = *first;
	*first = *second;
	*second = temp;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a{ 2 };
	int *Aptr{ &a };
	int b = 4;
	int *Bptr{ &b };
	cout << "Изначальное значение a = " << *Aptr << ". Изначальное значение b = " << *Bptr << endl;
	Swap(Aptr, Bptr);
	cout << "После обмена значениями: a = " << *Aptr << ", b = " << *Bptr << endl;
	return 0;
}