#include <iostream>
#include <math.h>






double teilA_direkt(double x){
  double result;
  
  result = (1/sqrt(x))-(1/(sqrt(x+1)));
  
  return result;
}


double teilB_direkt(double x){
  
  return (1-cos(x))/(sin(x));
  
}

double teilC_direkt(double x, double delta){
  
  return (sin(x+delta)-sin(x));
  
}



int main(int argc, char **argv) {
    std::cout << "Aufgabenteil A direkt: " << teilA_direkt(3.9e15) << std::endl;
    std::cout << "Aufgabenteil B direkt: " << teilB_direkt(1e-10) << std::endl;
    std::cout << "Aufgabenteil C direkt: " << teilC_direkt(2,1e-12) << std::endl;
    return 0;
}
