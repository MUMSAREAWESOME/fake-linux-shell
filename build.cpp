#include <cstdlib>
#include <iostream>

int main(){
  int cmd = std::system("g++ src/main.cpp src/log.cpp src/commandRunners.cpp src/logo.cpp -o fake-linux-shell");
  if (cmd == 0) std::cout << "Built without fail\n";
  else std::cout << "Build failed\n";
  return 0;
}
