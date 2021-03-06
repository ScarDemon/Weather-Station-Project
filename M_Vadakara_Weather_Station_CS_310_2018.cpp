// M_Vadakara_Weather_Station_CS_310_2018.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Martin Vadakara
// Professor Tepfenhart
// September 28, 2018

#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "valid_input.h"
#include "WeatherMeasurement.h"
using namespace std;


int getCommand() { // command prompt for user
	bool correct4 = true; // bool variable c set to true
	string re5 = "[1-4]{1}"; // limit for command input 
	int input;
	string output;


	// while loop 
	while (correct4) {
		// command prompt commands for the user
		cout << endl;
		cout << "1 to input a complete weather reading." << endl;
		cout << "2 to print current weather." << endl;
		cout << "3 to get weather history entries." << endl;
		cout << "Any key to exit the program" << endl;
		getline(cin, output);
		correct4 = valid_input(output, re5); // c set to valid function calling x put and 
		stringstream(output) >> input; // regex expression for command prompt

		correct4 = false; // c is set to false to break out of the loop
	}
	return input;
} // end of function

// function to give the user the input for the amount of the size of
// weather station entries in its history
int HistorySize(int count) {
	int size = 0;

	bool correct = true;
	string re = "[1-9 /]{1,4}";
	string sizes;
	while (correct) {
		cout << endl;
		cout << "History Size of the weatherStation" << endl;
		getline(cin, sizes);
		correct = valid_input(sizes, re);
		stringstream(sizes) >> size;
		correct = false;
	} // end of while loop
	// error message when size is equal or less than zero.
	if (size <= 0) {
		cout << "Error!";
	} // end of if loop
	if (count > size) {
		count = size;
	}
	return size;
} // end of function




int main()  // main 
{ // start bracket
	// call of getResult

	//weather_t weatherMeasure;
	//getResult();


	weather_t weatherMeasure;

	int * arrTemp; // int pointer for temperature for weather history
	int * arrWindSpeed; // int pointer for wind speed for weather history
	string  * arrWindDirection; // string pointer for windDirection for weather history

	string weather; // weather station input
	int input;// variable used for command input
	int count = 0;  // counts the user inputs for history size
	int history = 0; // int to be used to store HistorySize



	weather = weatherMeasure.getWeatherStation(); // calling of weatherstaion
	history = HistorySize(count); // calling of HistorySize

	// while loop to repeat the HistorySize if user inputs 0 or less than 0
	while (history <= 0) {
		history = HistorySize(count);
	}

	// string and int points that carry the history size in history int type.
	arrTemp = new int[history];
	arrWindDirection = new string[history];
	arrWindSpeed = new int[history];

	input = getCommand(); // call of getcommand

	// various inputs to choose from getCommand
	while (input == 1 || input == 2 || input == 3 || input == 4) {

		// if statment to input a complete weather reading
		if (input == 1) {
			// calling of various functions

			weatherMeasure.wind.miles = weatherMeasure.wind.getWindMiles();
			weatherMeasure.temperature.temperature = weatherMeasure.temperature.getTemperature();
			weatherMeasure.wind.direction = weatherMeasure.wind.getWindDirection();
			input = getCommand();
			count++;
			// variable to return to user weather command prompt
		} // end of if loop

		// if statement to print weather reading
		if (input == 2) {
			weatherMeasure.getResult(weather, weatherMeasure.temperature.temperature, weatherMeasure.wind.miles,
				weatherMeasure.wind.direction);
			input = getCommand();

		} // end of if

		// if statement to call upon weather station history 
		if (input == 3) {
			count++;
			weatherMeasure.StoreArray(arrTemp, arrWindSpeed, arrWindDirection, weatherMeasure.temperature.temperature,
				weatherMeasure.wind.direction, weatherMeasure.wind.miles, history);
			weatherMeasure.PrintArray(weather, arrTemp, arrWindSpeed, arrWindDirection, count, history);
			input = getCommand();

		}
		// if statement to break out of the program
		if (input == 4) {
			break;
		} // end of if

	} // end of while
	return 0; // end program



} // end of main
