#include <sstream>
#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cmath>
using namespace std;

int main() {
  int n;
  float pi = 0.0;
  float negOne = -1.0;
  float one = 1.0;
  float two = 2.0;

  cout << "Please enter a non-negative integer upper limit of sumation for the Leibnitz for computing pi:" << endl;
  cin >> n;

  for (float k = 0.0; k <= n; k++)
  {
      pi += pow(negOne,k)/((two*k)+one);
  }

  pi = pi*4.0;

  cout << "PI (approx): " << setprecision(DBL_DIG) << pi << "; n: " << setw(7)  << n << endl;
  cout << "PI (actual): " << "3.141592653589793" << endl;
  cout << "Decimal digits of precision: " << DBL_DIG << endl;
  cout << "Number of base 2 mantissa digits of double precision floating point value: " <<  DBL_MANT_DIG << endl;
  cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;
}
