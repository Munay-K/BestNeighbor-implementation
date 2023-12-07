#include <iostream>
#include <vector>
#include <cmath>

#include "../src/timeseries.h"
#include "../src/dataset.h"

std::vector<double> normalize(const std::vector<double>& x) {
  const double eps = 1e-6;

  double sum = 0.0;
  double sumSquared = 0.0;

  // Calculate the mean
  for (double value : x) {
    sum += value;
    sumSquared += value * value;
  }

  const double n = static_cast<double>(x.size());
  const double mean = sum / n;

  // Calculate the standard deviation
  const double variance = (sumSquared - (sum * sum) / n) / n;
  const double stdDev = std::sqrt(variance);

  // Check if standard deviation is close to zero
  if (stdDev < eps) {
    // Return a vector of zeros
    return std::vector<double>(x.size(), 0.0);
  }

  // Normalize the vector
  std::vector<double> normalized;
  normalized.reserve(x.size());

  for (double value : x) {
    normalized.push_back((value - mean) / stdDev);
  }

  return normalized;
}

int main() {
  // Example usage
  Dataset<double> ds("../src/data", ' ');
  std::vector<double> input;

  for (auto val : ds.data[0].values){
    input.push_back(val.second);
  }

  // Print vector
  for (double value : input) {
    std::cout << value << " ";
  }

  std::cout << std::endl << std::endl;
  std::vector<double> result = normalize(input);

  // Print the normalized vector
  for (double value : result) {
    std::cout << value << " ";
  }

  return 0;
}
