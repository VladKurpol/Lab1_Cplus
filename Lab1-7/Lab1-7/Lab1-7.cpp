// Lab1-7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>

struct robotnik
{
	std::string first_name;
	std::string second_name;
	std::string surname;
	std::string position;
	std::string sex;

	int exp;
	int date[3];
	
	void print()
	{
		std::cout << "Information about worker:\n";
		std::cout << "Data:\n";
		std::cout << "Name - " << first_name << "\nLast Name - " << surname << "\nPatronymic - "
			<< second_name << "\nPosition - " << position << "\nSex - " << sex << "\nDate - " << date[0] << "." << date[1] << "." << date[2] << "\n";
		std::cout << "\n";
	}
};

void data_input(robotnik *worker, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter firstname " << "\n";
		std::cin >> worker[i].first_name;

		std::cout << "Enter second name " << "\n";
		std::cin >> worker[i].second_name;

		std::cout << "Enter surname " << "\n";
		std::cin >> worker[i].surname;

		std::cout << "Enter position " << "\n";
		std::cin >> worker[i].position;

		std::cout << "Enter sex " << "\n";
		std::cin >> worker[i].sex;

		std::cout << "Enter date " << "\n";
		std::cin >> worker[i].date[0];
		std::cin >> worker[i].date[1];
		std::cin >> worker[i].date[2];
	}
}

int personal_expr(robotnik *worker, int i, int days4)
{

	int days1 = 0;
	int days2 = 0;
	int days3 = 0;

	days1 += 31 - worker[i].date[1];

	days2 += 12 - worker[i].date[2];
	days2 = days2 * 31;

	days3 += 2019 - worker[i].date[3];
	days3 = days3 * 12;
	days3 = days3 * 31;
	days4 = days1 + days2 + days3;

	return days4;
}

int everage_expr(robotnik *worker, int n, int average)
{
	int days1 = 0;
	int days2 = 0;
	int days3 = 0;
	int days4 = 0;

	for (size_t i = 0; i < n; i++)
	{
		days1 += 31 - worker[i].date[1];

		days2 += 12 - worker[i].date[2];
		days2 = days2 * 31;

		days3 += 2019 - worker[i].date[3];
		days3 = days3 * 12;
		days3 = days3 * 31;
	}
	days4 = days1 + days2 + days3;
	average = days4 / n;
	return average;
}

int main()
{
	int days4 = 0;
	int exp = 0;
	int n = 0;
	int average = 0;

	std::cout << "Enter the number of workers" << "\n";
	std::cin >> n;

	robotnik *worker = new robotnik[n];

	data_input(worker, n);

	for (size_t i = 0; i < n; i++)
	{
		if (personal_expr(worker, i, days4) > everage_expr(worker, n, exp))
		{
			worker[i].print();
		}
	}

	delete[] worker;
	system("Pause");
	return 0;
}
