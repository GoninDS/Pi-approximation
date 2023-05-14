// TODO(me): change from defines to parameters

#define NUMBER_AMOUNT 100 

#include <vector>

void generate_points(std::vector<bool>& points);

void generate_random(double& container);

void calculate_position(double& x_value, double& y_value);

int main(int argc, char ** argv) {
  
  // Create the vector to hold the points
  std::vector<bool> points;

  // Generate the points
  generate_points(points);

  return 0;
}

void generate_points(std::vector<bool>& points) {
  double x_value = 0.0;
  double y_value = 0.0;
  for (int i = 0; i < NUMBER_AMOUNT; ++i) {
    generate_random(x_value);
    generate_random(y_value);
    calculate_position(x_value, y_value);
  }
}

void generate_random(double& container) {
  // rand_r
}

void calculate_position(double& x_value, double& y_value) {
  
}