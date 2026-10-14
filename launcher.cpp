#include <cctype>
#include <iostream>
#include <fstream>
#include <algorithm>

void printHeader(int length, char character){
  for (int i = 0; i < length; i ++){
    std::cout << character;
  }
  std::cout << std::endl;
}

int addToLog(std::string logPath, std::string message){

  //  This function takes a file path and a message and puts it into the log (at the file path)
  
  std::ofstream logFile(logPath, std::ios::app);

  if (logFile.is_open()){
    logFile << message << std::endl;
  }
  else{
    std::cerr << "Failed to add " << message << " to log file located at " << logPath << '\n';
    return 1;
  }

  return 0;
}

void clear(){
  std::system("clear");
  addToLog("/home/awesome-server/scripts/launcher/log/log.txt", "Cleared Screen");
}

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
    addToLog("/home/awesome-server/scripts/launcher/log/log.txt", logMsg);
  }
  else addToLog("/home/awesome-server/scripts/log/log.txt", "Did not execute");
}

int main(){

  while (true){
    printHeader(10, '=');
    std::cout << "=> ";
    std::string comand;
    std::cin >> comand;
    transform(comand.begin(), comand.end(), comand.begin(), ::tolower);

    if (comand == "quit" || comand == "q"){
      addToLog("/home/awesome-server/scripts/launcher/log/log.txt", "Exited");
      break;
    }
    else if (comand == "launch"){
      bool chmod;
      std::string temp, path, name;

      std::cout << "Do you need to run chmod with this? [y/n]: ";
      std::cin >> temp;
      transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
      if (temp == "y") chmod = true;
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
    }
  }

  return 0;
}
