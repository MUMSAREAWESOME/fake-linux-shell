#include "log.h"
#include "comandRunners.h"
#include "logo.h"
#include <cctype>
#include <iostream>
#include <algorithm>

void printHeader(int length, char character){
  for (int i = 0; i < length; i ++){
    std::cout << character;
  }
  std::cout << std::endl;
}

void help(){
  std::cout << "Current valic commands: " << "quit, q, launch, clear, run, command, help" << std::endl;
}

int main(){
  showLogo();
  while (true){
    printHeader(60, '=');
    std::cout << "=> ";
    std::string comand;
    std::cin >> comand;
    transform(comand.begin(), comand.end(), comand.begin(), ::tolower);

    if (comand == "quit" || comand == "q"){
      addToLog("log/log.txt", "Exited");
      break;
    }
    else if (comand == "launch"){
      bool chmod;
      std::string choice, path, name;

      std::cout << "Do you need to run chmod with this? [y/n]: ";
      std::cin >> choice;
      transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
      if (choice == "y") chmod = true;
      else chmod = false;

      std::cout << "Path to executable: ";
      std::cin >> path;

      std::cout << "Executable name: ";
      std::cin >> name;
      
      launchExecutable(chmod, path, name);

      std::cout << std::endl;
    }
    else if (comand == "clear"){
      clear();
      showLogo();
    }
    else if (comand == "run" || comand == "command"){
      std::cin.ignore();
      std::string comandToRun;
      std::cout << "Command: ";
      getline(std::cin, comandToRun);
      runComand(comandToRun);
    }
    else if (comand == "help"){
      help();
    }
  }

  return 0;
}
