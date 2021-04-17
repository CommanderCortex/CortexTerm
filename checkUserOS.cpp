#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main(){

	std::string userInput;
	printf("Input Your Current OS For Configuration:\n");
	std::cin>>userInput;

	if(userInput == "MacOS"){
		std::string str  = "./";
		std::string OS   = "/Unix/MacTerm";
		str = str + OS;
		const char *command = str.c_str();
		system(command);
	}else if(userInput == "Ubuntu"){
		std::string str  = "./";
		std::string OS   = "/Unix/UbuntuTerm";
		str = str + OS;
		const char *command = str.c_str();
		system(command);
	}else if(userInput == "Windows"){
		std::string str = "./";
		std::string OS = "./Windows/CortexTermNT";
		str = str + OS;
		const char *command = str.c_str();
		system(command);
	}else{
		printf("Error, Operating System not supported!\n");
		return 1;
	}
	
	return 0;
}
