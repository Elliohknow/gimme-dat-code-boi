#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//This program reads numerical data from a file, calculates and prints the average, calculates the deviation from the
//average for each number and prints them.

int GetAverage(int, int); 

int main()
{
	int count = 0, total = 0, data = 0, average = 0, deviation = 0;
	vector<int> numbers(count);			//initialize variables and input file stream
	ifstream input;

	cout << "Deviation Calculator: Engaged!" << endl << endl;

	input.open("devcalcdatafile.txt");
	while (input>>data)					//loop to get the count of the file
		count++;
	input.close();

	input.open("devcalcdatafile.txt");
	
	for (int i = 0; i < count; i++) //loop to read data into vector/array 
	{
		input >> data;
		numbers.push_back(data);
		total += numbers[i];		//add new element to the total
	}

	average = GetAverage(count, total);		//get and print the average
	cout << "Average: " << average << endl << endl;

	for (int i = 0; i < count; i++) //loop to print each element and its deviation from the average
	{
		if (numbers[i] > average)
		{
			deviation = numbers[i] - average;
		}
		else if (numbers[i] < average)
		{
			deviation = average - numbers[i];
		}
		else
		{
			deviation = 0;
		}
		cout << "Element #"<< (i+1) << ": "<< numbers[i] << endl;
		cout << "Deviation: " << deviation << endl << endl;
	}
	input.close();

	cout << "Deviation Calculator: Disengaged!" << endl << endl;

	system("PAUSE");
	return 0;
}

int GetAverage(int count, int total)
{
	int avg = 0;

	avg = (total / count);

	return avg;
}