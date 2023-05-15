#include <vector>
#include <iostream>
#include <string>
#include <random>

/**
 * @brief Generates points from [0,1[ with a standard distribution
 * 
 * @param points Vector that contains if the points are in or outside of the circle
 * @param number_amount The amount of numbers used for the simulation
 */
void generate_points(std::vector<bool>& points, int& number_amount);
/**
 * @brief Checks if the x and y values are inside the circle
 * 
 * @param x_value The x value for the point
 * @param y_value The y value for the point
 * @return true The point is in the circle
 * @return false The point is out of the circle
 */
bool calculate_position(double& x_value, double& y_value);
/**
 * @brief Approximates pi with the amount of points calculated in the circle
 * 
 * @param points Contains the vector that contains if the points are in or outside of the circle
 * @return double The answer with the approximated pi
 */
double approximate_pi(std::vector<bool>& points);
/**
 * @brief Show the obtained results in the command line
 * 
 * @param pi The variable containing the approximation
 */
void show_results(double& pi);


int main(int argc, char ** argv) {
  if (argc == 2) {
    int number_amount = std::stoi(argv[1]);
    // Create the vector to hold the points
    std::vector<bool> points;
    // Generate the points
    generate_points(points, number_amount);
    // Approximate pi
    double pi = approximate_pi(points);
    show_results(pi);
  } else {
    std::cerr << 
        "Please only insert the amount of numbers for the simulation"
        << std::endl;
  }
  return 0;
}

void generate_points(std::vector<bool>& points, int& number_amount) {
  // Create the default random engine generator
  std::default_random_engine generator;
  // Set the distribution in the range [0,1[
  std::uniform_real_distribution<double> distribution(0.0,1.0);
  double x_value = 0.0;
  double y_value = 0.0;
  bool in_circle = false;
  for (int i = 0; i < number_amount; ++i) {
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
