#include "Timer.h"
#include <string>
#include <fstream>
#include <algorithm>
int main()
{
	setlocale(LC_ALL, "Russian");
	Timer t;
	string vowels = "aeiouyAEIOUY";
	ifstream book1("Tolstoy_Leo._War_and_Peace.txt");
	if (book1.is_open())
	{
		t.start("Способ 1");
		size_t count = count_if(istreambuf_iterator<char>(book1), istreambuf_iterator<char>(), [=](char s)
			{return vowels.find(s) != string::npos;});
		t.print();
		cout << "Гласных: " << count << endl;
	}
	else
	{
		cout << "Не удалось открыть файл";
	}
	book1.close();
	ifstream book2("Tolstoy_Leo._War_and_Peace.txt");
	if (book2.is_open())
	{
		t.start("Способ 2");
		size_t count = count_if(istreambuf_iterator<char>(book2), istreambuf_iterator<char>(), [vowels](char s)
			{for (const auto &v : vowels)
				{
					if (v == s)
					{return true;}
				}
				return false;
			});
		t.print();
		cout << "Гласных: " << count << endl;
	}
	else
	{
		cout << "Не удалось открыть файл";
	}
	book2.close();
	ifstream book3("Tolstoy_Leo._War_and_Peace.txt");
	if (book3.is_open())
	{
		size_t counter = 0;
		string str;
		t.start("Способ 3");
		while (getline(book3, str))
		{
			for (size_t i = 0; i < str.size(); i++)
			{
				if (vowels.find(str[i]) != string::npos)
				{
					counter++;
				}
			}
		}
		t.print();
		cout << "Гласных: " << counter << endl;
	}
	else
	{
		cout << "Не удалось открыть файл";
	}
	book3.close();
	ifstream book4("Tolstoy_Leo._War_and_Peace.txt");
	if (book4.is_open())
	{
		size_t counter = 0;
		string str;
		t.start("Способ 4");
		while (getline(book4, str))
		{
			for (size_t i = 0; i < str.size(); i++)
			{
				for (size_t j = 0; j < vowels.size(); j++)
				{
					if (str[i] == vowels[j])
					{
						counter++;
					}
				}
			}
		}
		t.print();
		cout << "Гласных: " << counter << endl;
	}
	else
	{
		cout << "Не удалось открыть файл";
	}
	book4.close();
	return 0;
}