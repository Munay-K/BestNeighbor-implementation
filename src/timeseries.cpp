#include "timeseries.h"

template<>
void TimeSeries<double>::print() {
  std::cout << '[';
  for (auto v : values){
    std::cout << '(' << v.first << ", " << v.second << ')';
  }
  std::cout << ']' << std::endl;
}
