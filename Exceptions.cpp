// Sum the integers from 1 to n. For example, if n is 5, then
// sigma returns the sum 1 + 2 + 3 + 4 + 5 == 15.
// @param n unsigned integer upper bound of summation
// @pre n>= 1
// @post return value is the sum of the integers from 1 to n.
// @return sum of the integers from 1 to n, where n is
//         specified as an argument of 0 if an error occurred.
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

unsigned long sigma(unsigned long n)
{
  unsigned long sum = 0;
  string strMessage = "Postcondition sum == (n(n+1))/2 violated: sum: " + to_string(sum) + "; n(n+1)/2: " + to_string((n*(n+1))/2) + " (Loc: " + __FILE__ + ", " + to_string(__LINE__) + ")";

  try
  {
    // Check preconditions
    //     Raise a runtime_error exception if the precondition (n>=1) is not met.
    if (n<1)
    {
      throw runtime_error(strMessage);
    }

    //Function body
    //     Implement a for loop to compute sum of integers from 1 to n
    else
    {
      for (int i = 1; i <= n; i++)
      {
        sum += i;
      }
    }

    //Check postconditions
    //   Raise a runtime_error exception if the postcondition (sum == (n(n+1)/2))
    //   is not met
    if (sum != (n*(n+1)/2))
    {
      throw runtime_error(strMessage);
    }

  }
  catch (runtime_error & ex)
  {
    cout << "Exception: " << ex.what() << endl;
    cout << "Cannot compute sum; returning 0" << endl;
    sum = 0; // 0 is returned to indicate an error occured.
  }

  return sum;
}

int main()
{
  int sum = sigma(5);
  cout << "sigma(5) = " << sum << endl;
  sum = sigma(0);
  cout << "sigma(0) = " << sum << endl;

  return 0;
}
