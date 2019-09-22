#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "food.hpp"
 
/*
 * A class to read data from a csv file.
 */

using namespace std;

class CSVReader
{
	std::string foodDatabase;
	std::string delimeter;
	std::vector<Food> my_foods;
 
public:
	CSVReader(std::string foodDatabase, std::string delm = ",") :
			foodDatabase(foodDatabase), delimeter(delm)
	{ }
 
	// Function to fetch data from a CSV File
	std::vector<Food> getData();
	void writeData(std::vector<Food> my_Foods);
};
 
/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
std::vector<Food> CSVReader::getData()
{
	std::ifstream file(foodDatabase);
	std::string str;
 
	std::vector<Food> my_records;
	// std::vector<std::vector<std::string> > dataList;
	//skip first line
	getline(file, str);

	while(std::getline(file,str))
    {

		Food food;
		istringstream iss(str);
		string token;

		getline(iss, token, ',');
		food.setName(token);

		getline(iss, token, ',');
		food.setCalories(std::stoi(token));

		getline(iss, token, ',');
		food.setCarbs(std::stoi(token));

		getline(iss, token, ',');
		food.setFat(std::stoi(token));

		getline(iss, token, ',');
		food.setProtein(std::stoi(token));

		getline(iss, token, ',');
		food.setMeal(token);

		getline(iss, token, ',');
		food.setTimesMade(std::stoi(token));

		getline(iss, token, ',');
		food.setRating(std::stof(token));

		my_records.push_back(food);

    }
	return my_records;

}

void CSVReader::writeData(std::vector<Food> my_Foods)
{
	// create an ofstream for the file output (see the link on streams for
	// more info)
	ofstream outputFile;
	ofstream fs;

	// create and open the .csv file
	outputFile.open(foodDatabase);
    
    // write the file headers
    outputFile << "Food," << "Calories," << "Carbs," << "Fat," << "Protein,"<<"Meal," << "Times_Made," << "Rating" << std::endl;

	//write to the file
	for(int i = 0; i < my_Foods.size(); i++){
		// write the data to the output file
		string name = my_Foods[i].getName();
		string calories = to_string(my_Foods[i].getCalories());
		string carbs = to_string(my_Foods[i].getCarbs());
		string fat = to_string(my_Foods[i].getFat());
		string protein = to_string(my_Foods[i].getProtein());
		string meal = my_Foods[i].getMeal();
		string timesMade = to_string(my_Foods[i].getTimesMade());
		string rating = to_string(my_Foods[i].getRating());
        outputFile << name << "," << calories << "," << carbs << "," << fat << ",";
		outputFile << protein << "," << meal << "," << timesMade << "," << rating << std::endl;
	}
  
    // close the output file
    outputFile.close();

}