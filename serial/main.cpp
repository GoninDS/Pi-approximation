// TODO(me): change from defines to parameters

#define NUMBER_AMOUNT 100000000

#include <vector>
#include <iostream>
#include <random>

void show_results(double& pi);
void generate_points(std::vector<bool>& points);
bool calculate_position(double& x_value, double& y_value);
double approximate_pi(std::vector<bool>& points);

int main(int argc, char ** argv) {
  // Create the vector to hold the points
  std::vector<bool> points;
  // Generate the points
  generate_points(points);
  // Approximate pi
  double pi = approximate_pi(points);
  show_results(pi);
  return 0;
}

void generate_points(std::vector<bool>& points) {
  // Create the default random engine generator
  std::default_random_engine generator;
  // Set the distribution in the range [0,1[
  std::uniform_real_distribution<double> distribution(0.0,1.0);
  double x_value = 0.0;
  double y_value = 0.0;
  bool in_circle = false;
  for (int i = 0; i < NUMBER_AMOUNT; ++i) {
    // Generate the random points
    x_value = distribution(generator);
    y_value = distribution(generator);
    // Calculate if it is in the circle
    in_circle = calculate_position(x_value, y_value);
    points.push_back(in_circle);
  }
}


bool calculate_position(double& x_value, double& y_value) {
  bool answer = false;
  double x_squared = x_value * x_value;
  double y_squared = y_value * y_value;
  if (x_squared + y_squared <= 1) {
    answer = true;
  }  
  return answer;
}

double approximate_pi(std::vector<bool>& points) {
  double total_points = (double)(points.size());
  double total_in_circle = 0.0;
  double pi = 0.0;
  // Find the total amount of points in the circle
  for (int i = 0; i < total_points; ++i) {
    // If true, the point is in the circle
    if(points[i]){
      ++total_in_circle;
    }
  }
  pi = (double)(4.0 * total_in_circle / total_points);
  return pi;
}

void show_results(double& pi) {
  std::cout << "PI APPROXIMATION: " << pi << std::endl;
}
