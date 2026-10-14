#include "log.h"
#include <iostream>
#include <fstream>

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

  logFile.close();

  return 0;
}
