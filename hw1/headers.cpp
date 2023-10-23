#include <string>
#include <fstream>
#include <iostream>
#include "headers.h"


void EnterDataToFile() {

	std::ofstream outputStream("time.txt", std::ios::app);
	
	if (!outputStream.is_open()) {
		std::cout << "File isn't open";
		return;
	}
	
	std::cout << "Enter youre time for every loop, please!" << std::endl;

	for (int i = 1; i < 6; i++) {
		float loopTime = 0.0;
		std::cin >> loopTime;
		while (!std::cin.good()) {
			std::cout << "Your input is of wrong type, please enter a number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> loopTime;
		}
		outputStream << std::endl << loopTime;
	}
	
	std::string yourNote = "";
	std::getline(std::cin >> std::ws, yourNote);
	outputStream << std::endl << yourNote;
}

void ShowResults() {
	std::ifstream inputStream("time.txt");
	
	if (!inputStream.is_open()) {
		std::cout << "File isn't open";
		return;
	}

	while (!inputStream.eof()) {
		for (int i = 1; i < 6; i++) {
			float loopTime = 0.0;
			inputStream >> loopTime;
			if (!inputStream.good()) { 
				std::cout << "Don't change my file!!! >:(";
				return;
			}
			std::cout << loopTime << std::endl;
		}
		inputStream >> std::ws;
		std::string yourNote = "";
		std::getline(inputStream, yourNote);
		std::cout << yourNote << std::endl;
	}
}