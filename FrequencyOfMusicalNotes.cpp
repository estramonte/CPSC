#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  //Use the formula below to compute the frequencies of the following notes:
  //C#0, D0, D3 , C4, D#7, and C8.
  double Fr = 16.35; // ref frequency
  double one = 0.083333333;
  double two = 0.166666667;
  double three = 0.25;
  // Fkv = Fr * 2^v * 2^k/12
  double CFkv = Fr * pow(2,0) * pow (2, one);
  double CWv = 34500/CFkv;

  double D0Fkv = Fr * pow(2,0) * pow (2, two);
  double D0Wv = 34500/D0Fkv;

  double D3Fkv = Fr * pow(2,3) * pow (2, two);
  double D3Wv = 34500/D3Fkv;

  double C4Fkv = Fr * pow(2,4) * pow (2, 0);
  double C4Wv = 34500/C4Fkv;

  double D7Fkv = Fr * pow(2,7) * pow (2, three);
  double D7Wv = 34500/D7Fkv;

  double C8Fkv = Fr * pow(2,8) * pow (2, 0);
  double C8Wv = 34500/C8Fkv;

  cout << "Reference Frequency: " << Fr << " Hz" << endl;
  cout << "Speed of Sound: 345 m/s" << endl;
  cout << "C#0; nu: 0; k:1; frequency: " << CFkv << " Hz; wavelength: " << CWv << " cm" << endl;
  cout << "D0; nu: 0; k:2; frequency: " << D0Fkv << " Hz; wavelength: " << D0Wv << " cm" << endl;
  cout << "D3; nu: 3; k:2; frequency: " << D3Fkv << " Hz; wavelength: " << D3Fkv << " cm" << endl;
  cout << "C4; nu: 4; k:0; frequency: " << C4Fkv << " Hz; wavelength: " << C4Wv << " cm" << endl;
  cout << "D#7; nu: 7; k:3; frequency: " << D7Fkv << " Hz; wavelength: " << D7Wv << " cm" << endl;
  cout << "C8; nu: 8; k:0; frequency: " << C8Fkv << " Hz; wavelength: " << C8Wv << " cm" << endl;



}
