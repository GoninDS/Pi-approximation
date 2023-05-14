// TODO(me): change from defines to parameters

#define NUMBER_AMOUNT 100 

#include <vector>

void generate_points(std::vector<bool>& points);
void generate_random(double& container);
bool calculate_position(double& x_value, double& y_value);
double approximate_pi(std::vector<bool>& points);

int main(int argc, char ** argv) {  
  // Create the vector to hold the points
  std::vector<bool> points;
  // Generate the points
  generate_points(points);
  // Approximate pi
  approximate_pi(points);
  return 0;
}

void generate_points(std::vector<bool>& points) {
  double x_value = 0.0;
  double y_value = 0.0;
  bool in_circle = false;
  for (int i = 0; i < NUMBER_AMOUNT; ++i) {
    // Generate the random points
    generate_random(x_value);
    generate_random(y_value);
    // Calculate if it is in the circle
    in_circle = calculate_position(x_value, y_value);
    points.push_back(in_circle);
  }
}

void generate_random(double& container) {
  // rand_r
}

bool calculate_position(double& x_value, double& y_value) {
  bool answer = false;
  double x_squared = x_value * x_value;
  double y_squared = y_value * y_value;
  if (x_squared + y_square <= 1) {
    answer = true;
  }  
  return answer;
}

double approximate_pi(std::vector<bool>& points) {
  int total_points = points.size();
  int total_in_circle = 0;
  double pi = 0.0;
  // Find the total amount of points in the circle
  for (int i = 0; i < total_points; ++i) {
    // If true, the point is in the circle
    if(points[i]){
      ++total_in_circle;
    }
  }
  pi = (double)(4 * total_in_circle / total_points);
  return pi;
}
