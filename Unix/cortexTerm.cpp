#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

//Using a class to manage our startup.
class startUp{

//Define our starting string values.
std::string input;
std::string prefix = "Cortex~ ";

//Define our public on load function to manage input & output.
public: void onload (){
	std::cout<<prefix; std::cin>>input; runFunctions();
	
}	
//Collect all functions for execution.
	void runFunctions(){
		if(input == "exit"){
			exitFunction();
		}else if(input == "help"){
			helpFunction();
		}else if(input == "clear"){
			clearScreenFunction();
		}else if(input == "vim"){
			vimFunction();
		}else if(input == "c++"){
			cppFunction();
		}else if(input == "mkfile"){
			createFile();
		}else if(input == "ls"){
			listDir();	
		}else if(input == "run"){
			biRun();
		}else{
			printf("Error, Command Not Found\n");
			resetFunction();
		}
	}
//All Terminal Functions:

	//Help Function:
	void helpFunction(){
		std::cout<<"<Cortex Help>\n";
	    std::cout<<"/help  : Prints the help menu\n";
	    std::cout<<"/echo  : Echos Input Value\n";
	    std::cout<<"/exit  : Exits The Cortex Term\n";
	    std::cout<<"/clear : Clears The Current Term\n";
	    std::cout<<"/print : Adds 2 Values\n";
	    std::cout<<"/ls    : Lists Current Directory\n";
	    std::cout<<"/vim   : Runs Vim From Within Cortex\n";
	    std::cout<<"/top   : Displays All Current Process\n";
	    std::cout<<"/rand  : Displays a Random Int Value\n";
	    std::cout<<"/c++   : Compiles C++ Code\n";
	    std::cout<<"/run   : Runs A Terminal Program\n";
	    std::cout<<"/col   : Change Color Via tput Command\n";
	    onload();
	}
	//Reset the Term.
	void resetFunction(){
		onload();
	}
	//Exit Function
	void exitFunction(){
		system("exit");
	}
	//Clears the Users Screen
	void clearScreenFunction(){
		system("clear");
		onload();
	}
	//Lists the current working directory
	void listDir(){
		system("ls");
		onload();
	}
	//Vim function
	void vimFunction(){
		char filename[32];
		std::cin.getline(filename, 32);
		std::string vim = "vim ";
		vim = vim + filename;
		const char *command = vim.c_str();
		system(command);
		onload();	
	}
	//Compile C++ code function
	void cppFunction(){
		char filename[32];
		std::cin.getline(filename, 32);
		std::string cpp = "g++ ";
		cpp = cpp + filename;
		const char *command = cpp.c_str();
		system(command);
		onload();
	}
	//Run Binary Executable Programs 
	void biRun(){
		char filename[32];
		std::cin.getline(filename, 32);
		std::string run = "./";
		run = run + filename;
		const char *command = run.c_str();
		system(command);
		onload();
	}
	//Change Current Directory
	//void cd(){
	//	char directory[32];
	//	std::cin.getline(directory, 32);
	//	std::string cd = "cd";
	//	cd = cd + directory;
	//
	//}
	//File creation function
	void createFile(){
		char filename[32];
		std::cin.getline(filename, 32);
		std::ofstream outfile (filename);
		outfile.close();
		onload();
	}
};

int main(){

	//Create a local instance of StartUp
	startUp startup;
	//Clears the Terminal 
	system("clear");
	//Loads our custom Terminal
	startup.onload();
	
	return 0;
}
