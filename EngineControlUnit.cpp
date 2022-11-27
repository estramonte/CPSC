#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

class EngineControlUnit {
public:
  EngineControlUnit();
  ~EngineControlUnit();
  void handleCommand(char cCommand); // accepts character that corresponds to button press
  void PrintStart() ;
  void PrintButtons() ;

  void HydraulicJacks()
  {
    if (m_bActivatedHydraulicJacks == false) {
      m_bActivatedHydraulicJacks = true;
      cout << "Hydraulic Jacks activated" << endl;
      if (m_bActivatedBeltTires == true) {
        Tires();
      }
    }
    else {
      m_bActivatedHydraulicJacks = false;
      cout << "Hydraulic Jacks deactivated" << endl;
    }
  }

  void Infrared()
  {
    if (m_bActivatedIRIllumination == false) {
      m_bActivatedIRIllumination = true;
      cout << "Infrared Illumination activated" << endl;
    }
    else {
      m_bActivatedIRIllumination = false;
      cout << "Infrared Illumination deactivated" << endl;
    }
  }

  void Tires()
  {
    if (m_bActivatedBeltTires == false) {
      m_bActivatedBeltTires = true;
      cout << "Belt Tires activated" << endl;
    }
    else {
      m_bActivatedBeltTires = false;
      cout << "Belt Tires deactivated" << endl;
    }
  }

private:
  bool m_bActivatedHydraulicJacks; //Button A
  bool m_bActivatedBeltTires;      //Button B
  bool m_bActivatedIRIllumination; //Button E
};

EngineControlUnit :: EngineControlUnit() {
  m_bActivatedHydraulicJacks = false;
  m_bActivatedBeltTires = false;
  m_bActivatedIRIllumination = false;
}

EngineControlUnit :: ~EngineControlUnit() {
  cout << endl;
}

void EngineControlUnit :: handleCommand(char cCommand) {
  switch (cCommand)
  {
    case 'A':
    case 'a':
      HydraulicJacks();
      break;
    case 'B':
    case 'b':
      Tires();
      break;
    case 'E':
    case 'e':
      Infrared();
      break;
    defualt:
      break;
  }
}

void EngineControlUnit :: PrintStart (){
  cout << "Press X to turn off ignition or entering a steering wheel button (A, B or E)" << endl;
}

void EngineControlUnit :: PrintButtons (){
  cout << setw(9) << "(A)" << endl;
  cout <<setw(14) << "(F)  (G)  (B)" << endl;
  cout <<setw(14) << "(E)       (C)" << endl;
  cout << setw(9) << "(D)" << endl;
}

int main()
{
  EngineControlUnit Engine;
  char command;

  Engine.PrintStart();
  Engine.PrintButtons();

  cin >> command;

  while (true) {
    if (command == 'x' || command == 'X')
      break;
    else {
      Engine.handleCommand(command);
      Engine.PrintButtons();
      cin >> command;
    }
  }

  return 0;
}
