#include "logo.h"
#include <iostream>
#include <fstream>
#include <string>

void showLogo(){
  std::ifstream logo("assets/logo.txt");

  std::string line;

  while (getline(logo, line)){
    std::cout << line << std::endl;
  }

  logo.close();
}
