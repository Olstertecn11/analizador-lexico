#include "./../include/analyzer.h"
#include <algorithm>

Analyzer::Analyzer(){
  this->generateSingleTokens();
  this->generateWordTokens();
}


void Analyzer::generateSingleTokens(){
  this->singleTokens.push_back(Token("numeral", "#"));
  this->singleTokens.push_back(Token("PuntoYComa", ";"));
  this->singleTokens.push_back(Token("Punto", "."));
  this->singleTokens.push_back(Token("Igual", "="));
  this->singleTokens.push_back(Token("Menor", "<"));
  this->singleTokens.push_back(Token("Mayor", ">"));
  /* string letters = "abcdefjhigklmnñopqrstuvwxyz"; */
  /* for(int i = 0; i < letters.length(); i++){ */
  /*   string s(1, letters[i]); */
  /*   this->singleTokens.push_back(Token("Id", s)); */
  /* } */
}


bool Analyzer::isSinleToken(string ref){
  for(int i = 0; i < this->singleTokens.size(); i++){
    if(ref == this->singleTokens[i].getVal()){
      return true;
    }
  }
  return false;

}

Token Analyzer::getSingleToken(string ref){
  for(int i = 0; i < this->singleTokens.size(); i++){
    if(ref == this->singleTokens[i].getVal()){
      return this->singleTokens[i];
    }
  }
  return Token("", "");
}


void Analyzer::searchSingleToken(string line){
  for(int i = 0; i < line.length(); i++){
    string s(1, line[i]);
    if(this->isSinleToken(s)){
      Token token = this->getSingleToken(s);
      if(token.getVal() != ""){
        cout << "Lexema= " << token.getVal() << "; Token = " << token.getId() << endl;
      }
    }
  }
}


void Analyzer::generateWordTokens(){
  this->wordTokens.push_back(Token("reservada", "include"));
  this->wordTokens.push_back(Token("reservada", "iostream"));
  this->wordTokens.push_back(Token("reservada", "int"));
  this->wordTokens.push_back(Token("reservada", "string"));
  this->wordTokens.push_back(Token("reservada", "printf"));
  this->wordTokens.push_back(Token("reservada", "cout"));
  this->wordTokens.push_back(Token("reservada", "using"));
  this->wordTokens.push_back(Token("reservada", "namespace"));
  this->wordTokens.push_back(Token("reservada", "std"));
  this->wordTokens.push_back(Token("reservada", "main"));
  this->wordTokens.push_back(Token("reservada", "endl"));
}

void Analyzer::searchWordToken(string line){
  

}


string Helper::removeSubString(string line, int x, int y){
  string a_string = line.substr(0, x);
  string b_string = line.substr(y+1, line.length()-1);
  string new_string = a_string + b_string;
  cout << "substring created: " << new_string << endl;
  return new_string;
}



string Helper::deleteStringFromLine(string line, string ref){

  for(int i = 0; i < line.length(); i++){
    int real_distance = ref.length()-1;
    if(Helper::isTheString(line, i, i+real_distance, ref)){
      return Helper::removeSubString(line, i, i+real_distance);
    }
  }

  return line;
}


bool Helper::isTheString(string line, int x, int y, string ref){
  string new_string = "";
  for(int i = x; i <= y; i++){
    new_string += line[i];
  }

  return new_string == ref;
}

string Analyzer::compareLine(string line){
  for(Token item : this->wordTokens){
    string prev_string = line;
    cout << "item to eval: " << item.getVal() << endl;
    line = Helper::deleteStringFromLine(line, item.getVal());
    if(line.length() != prev_string.length()){
      cout << "Lexema = " << item.getVal() << " ; Token = " << item.getId() << endl;
    }
  }
  for(Token item : this->singleTokens){
    string prev_string = line;
    line = Helper::deleteStringFromLine(line, item.getVal());
    if(line.length() != prev_string.length()){
      cout << "Lexema = " << item.getVal() << " ; Token = " << item.getId() << endl;
    }
  }
  return line;
}

void Analyzer::analyzeLine(string line){

  line.erase(remove(line.begin(), line.end(), ' '), line.end());
  while(line != ""){
    line = this->compareLine(line);
  }

}




