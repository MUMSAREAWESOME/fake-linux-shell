#include "comandRunners.h"
#include "log.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

void launchExecutable(bool chmodNeeded, std::string pathToExecutable, std::string executableName){
  std::string comand;

  if (chmodNeeded){
    std::string temp = "chmod +x ";
    temp += pathToExecutable;
    std::system(temp.c_str());
  }

  comand += pathToExecutable;

  bool goAhead = false;

  for (int i = 0; i < 4; i ++){
    std::string cont;
    std::cout << "Comand about to execute: " << comand << '\n' << "Would you like to continue? [y/N]" << '\n' << "=> ";
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
    logMsg += comand;
    std::system(comand.c_str());
    addToLog("log/log.txt", logMsg);
  }
  else addToLog("log/log.txt", "Did not execute");
}

void clear(){
  std::system("clear");
  addToLog("log/log.txt", "Cleared Screen");
}

void runComand(std::string comand){
  std::string logText = comand;
  std::system(comand.c_str());
  addToLog("log/log.txt",logText);
  std::cout << '\n';
}
