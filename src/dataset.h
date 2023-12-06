#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "timeseries.h"

template <typename T>
class Dataset {
public:
  std::vector<TimeSeries<T>> data;

  Dataset(std::string filename, char delimiter = ' ') {
    std::fstream infile;
    infile.open(filename, std::ios::in);
    
    if (!infile.is_open()) {
      std::cout << "file named '" << filename << "' not found.\n";
    } else {
      std::string line, word;
      while (std::getline(infile, line)) {
        T x, y;
        x = 0;
        std::istringstream lineStream{ line };
        std::vector<std::pair<T, T>> invalues;

        while(lineStream >> y) {
          invalues.emplace_back(x, y);
          x++;
        }

        TimeSeries ts(invalues);
        data.emplace_back(ts);
      }
    }
  }

  void print();
};

#endif
