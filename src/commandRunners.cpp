#include "commandRunners.h"
#include "log.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

void launchExecutable(bool chmodNeeded, std::string pathToExecutable, std::string executableName){
  std::string command;

  if (chmodNeeded){
    std::string temp = "chmod +x ";
    temp += pathToExecutable;
    std::system(temp.c_str());
  }

  command += pathToExecutable;

  bool goAhead = false;

  for (int i = 0; i < 4; i ++){
    std::string cont;
    std::cout << "command about to execute: " << command << '\n' << "Would you like to continue? [y/N]" << '\n' << "=> ";
    std::cin >> cont;
    transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
    
    if (cont == "y"){
      goAhead = true;
      break;
    }
    else if (cont == "n"){
      goAhead = false;
      break;
    }
    else continue;
  }
  
  if (goAhead){
    std::string logMsg = "Executed: ";
    logMsg += command;
    std::system(command.c_str());
    addToLog("log/log.txt", logMsg);
  }
  else addToLog("log/log.txt", "Did not execute");
}

void clear(){
  std::system("clear");
  addToLog("log/log.txt", "Cleared Screen");
}

void runcommand(std::string command){
  std::string logText = command;
  std::system(command.c_str());
  addToLog("log/log.txt",logText);
  std::cout << '\n';
}
