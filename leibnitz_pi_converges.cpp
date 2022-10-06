#include <sstream>
#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cmath>
using namespace std;

int main() {
  float pi = 0.0;
  float negOne = -1.0;
  float one = 1.0;
  float two = 2.0;

  for (int i = 2; i <=1048576; i*=2)
  {
    pi = 0.0;
    for (float k = 0.0; k <= i; k++)
    {
        pi += pow(negOne,k)/((two*k)+one);
      }
      pi = pi*4.0;
      cout << "PI: " << setprecision(DBL_DIG) << pi << "; n: " << setw(7)  << i << endl;
  }
}
