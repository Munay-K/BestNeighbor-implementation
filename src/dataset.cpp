#include "dataset.h"

template<>
void Dataset<double>::print() {
  std::cout << "-------------------------------\n";
  for (auto v : data){
    v.print();
  }
  std::cout << "-------------------------------\n";
}
