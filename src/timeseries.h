#ifndef TIMESERIES_H
#define TIMESERIES_H

#include <iostream>
#include <vector>

template <typename T>
struct TimeSeries {
  TimeSeries(std::vector<std::pair<T, T>> invalues) : values{invalues}{}
  std::vector<std::pair<T, T>> values;
  void print();
};

#endif
