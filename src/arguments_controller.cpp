#include "./../include/argument_controller.h"
#include <iostream>
#include <fstream>
using namespace std;

void A_Controller::readArguments(int argc, char *argv[]){
  if(argc < 2){
    cout << "Missing arguments, usage: " << argv[0] << " <filename> " << endl;
  }
  else{
    ifstream file(argv[1]);
    if(file.is_open()){
      cout << "could not open this file" << endl; 
    }
    else{
      cout << " file to read... " << argv[1] << endl;
    }
  }

}


