#include "./../include/token.h"


Token::Token(){
  this->id = "";
  this->value = "";
}

Token::Token(string id, string val){
  this->id = id;
  this->value = val;
}



string Token::getId(){return this->id;}

string Token::getVal(){return this->value;}

