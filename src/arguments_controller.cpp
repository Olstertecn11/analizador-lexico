#include "./../include/argument_controller.h"
#include <iostream>
#include <fstream>
using namespace std;

void A_Controller::readArguments(int argc, char *argv[]){
  if(argc < 2){
    cout << "Missing arguments, usage: " << argv[0] << " <filename> " << endl;
  }
  else{
    this->loadFile(argv[1]);
  }
}


void A_Controller::loadFile(string filename){
  ifstream file;
  string cadena, substring;
  int pos,size;
  file.open(filename, ios::in);
  if(!file.fail()){
    file >> size; 
    while(!file.eof()){
      getline(file, cadena);
      cout << "line readed: " << cadena << endl;
    }
  }
  else{
    cout << "error opening file" << endl;
  }
}


