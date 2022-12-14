#include "./../include/argument_controller.h"
#include <iostream>
using namespace std;
#include <fstream>


A_Controller::A_Controller(){
  this->analyzer = Analyzer();
}

void A_Controller::readArguments(int argc, char *argv[]){
  if(argc < 2){
    cout << "Missing arguments, usage: " << argv[0] << " <filename> " << endl;
  }
  else{
    this->multiRead(argc, argv);
  }
}

void A_Controller::multiRead(int size, char *argv[]){
  for(int i = 1; i < size; i++){
    this->loadFile(argv[i]);
  }
}

void A_Controller::loadFile(string filename){
  ifstream file;
  string cadena, substring;
  file.open(filename);
  if(file.is_open()){
    while(!file.eof()){
      getline(file, cadena);
      this->analyzer.analyzeLine(cadena);
    }
    file.close();
  }
  else{
    cout << "error opening file: " << filename << endl;
  }
}


