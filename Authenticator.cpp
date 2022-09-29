#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
  const char AuthenticatorChar1 = 'E';
  const char AuthenticatorChar2 = 'C';
  const char AuthenticatorChar3 = 'A';
  char MessageChar1;
  char MessageChar2;
  char MessageChar3;
  const int ValidChecksum = 5;

  cout << "Enter the first character of the message code:" << endl;
  cin >> MessageChar1;
  cout << "Enter the second character of the message code:" << endl;
  cin >> MessageChar2;
  cout << "Enter the third character of the message code:" << endl;
  cin >> MessageChar3;
  cout << endl;

  string MessageCode = MessageChar1 + MessageChar2 + MessageChar3 + " ";
  string AuthenticatorCode = AuthenticatorChar1 + AuthenticatorChar2 + AuthenticatorChar3 + " ";

  cout << "Authenticator Code: ECA" << endl;
  cout << "Message Code: " << MessageChar1 << MessageChar2 << MessageChar3 << endl;
  cout << endl;

  int ASCIIMessageChar1 = int(MessageChar1);
  int ASCIIMessageChar2 = int(MessageChar2);
  int ASCIIMessageChar3 = int(MessageChar3);
  int ASCIIMessageSum = ASCIIMessageChar1 + ASCIIMessageChar2 + ASCIIMessageChar3;
  int checksum = ASCIIMessageSum % 7;
  int ASCIIAuthenticatorChar1 = int(AuthenticatorChar1);
  int ASCIIAuthenticatorChar2 = int(AuthenticatorChar2);
  int ASCIIAuthenticatorChar3 = int(AuthenticatorChar3);
  int ASCIIAuthenticatorSum = ASCIIAuthenticatorChar1 + ASCIIAuthenticatorChar2 + ASCIIAuthenticatorChar3;

  if (MessageCode == AuthenticatorCode) {
    cout << "Message is authentic." << endl;
    cout  << "Concurrence: message is authentic." << endl;
  }
  else {
    cout << "Message is invalid." << endl;
    cout << "Concurrence: message is invalid." << endl;
  }

  cout << endl;
  cout << "Characterization of Message Code" << endl;
  cout << "-------------------------------------------" <<endl;

  cout << "ASCII Values of Message Code Characters: ";
  cout << ASCIIMessageChar1 << ", " << ASCIIMessageChar2 << ", " << ASCIIMessageChar3 << endl;

  cout << "Sum of ASCII values for Message Code Characters: ";
  cout << ASCIIMessageSum << endl;

  if (checksum == ValidChecksum) {
    cout << "Message Code Checksum is valid: 5" << endl;
  }
  else {
    cout << "Message Code Checksum is invalid: " << checksum << "; expected 5" << endl;
  }

  if (AuthenticatorChar1 != MessageChar1) {
    cout << "First characters do not match: Message: " << MessageChar1 << "; Authenticator: " << AuthenticatorChar1 << endl;
  }

  if (AuthenticatorChar2 != MessageChar2) {
    cout << "Second characters do not match: Message: " << MessageChar2 << "; Authenticator: " << AuthenticatorChar2 << endl;
  }

  if (AuthenticatorChar3 != MessageChar3) {
    cout << "Third characters do not match: Message: " << MessageChar3 << "; Authenticator: " << AuthenticatorChar3 << endl;
  }

  if (ASCIIAuthenticatorSum < ASCIIMessageSum){
    cout << "Message code (" << MessageChar1 << MessageChar2 << MessageChar3 << ") is lexicographically  greater than the  (ECA)" << endl;
  }
  else if (ASCIIAuthenticatorSum < ASCIIMessageSum){
    cout << "Message code (" << MessageChar1 << MessageChar2 << MessageChar3 << ") is lexicographically  lesser than the  (ECA)" << endl;
  }

}
