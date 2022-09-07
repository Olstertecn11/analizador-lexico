#include "./../include/analyzer.h"

Analyzer::Analyzer(){
  this->generateSingleTokens();
}


void Analyzer::generateSingleTokens(){
  this->singleTokens.push_back(Token("numeral", "#"));
  this->singleTokens.push_back(Token("PuntoYComa", ";"));
  this->singleTokens.push_back(Token("Punto", "."));
  this->singleTokens.push_back(Token("Igual", "="));
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
  this->wordTokens.push_back(Token("reservada", "int"));
  this->wordTokens.push_back(Token("reservada", "string"));
  this->wordTokens.push_back(Token("reservada", "printf"));
  this->wordTokens.push_back(Token("reservada", "cout"));
  this->wordTokens.push_back(Token("reservada", "using"));
  this->wordTokens.push_back(Token("reservada", "namespace"));
  this->wordTokens.push_back(Token("reservada", "std"));
  this->wordTokens.push_back(Token("reservada", "iostream"));
  this->wordTokens.push_back(Token("reservada", "main"));
  this->wordTokens.push_back(Token("reservada", "endl"));
}




