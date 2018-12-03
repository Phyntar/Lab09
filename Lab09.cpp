//Lab09.cpp
//Brandon Endsley

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

void ReadData(vector<string>& theData, ifstream& in)
{
	if (in.is_open())
	{
		string temp;
		in >> temp;
		do
		{
			theData.push_back(temp);
			in >> temp;

		} while (!(in.eof()));
	}
}

void insertToMap(map<string, int>& map, vector<string> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (map.find(input.at(i)) != map.end())
		{
			map.find(input.at(i))->second++;
		}
		else
		{
			map.insert({input.at(i), 1});
		}
	}
}

void writeFile(map<string, int> myMap)
{
	ofstream outfile;
	outfile.open("output.txt");
	
	map<string,int>::iterator it = myMap.begin();

	while (it != myMap.end())
	{
		for (int i = 0; i < it->second; i++)
		{
			outfile << it->first<<" ";
		}
		++it;
	}

	outfile.close();
}



int main()
{
	string filename;
	vector<string> theData;
	map<string, int> theMap;
	cout << "please input a file name: ";
	cin >> filename;

	ifstream infile;
	infile.open(filename);
	ReadData(theData, infile);
	insertToMap(theMap, theData);
	writeFile(theMap);

	cout << "\nDone!\n\n";

	infile.close();
	return 0;
}