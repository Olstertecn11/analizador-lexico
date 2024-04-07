#include "./../include/analyzer.h"
#include <algorithm>
#include <cctype>
#include <ctype.h>
#include <fstream>
#include <iostream>

Analyzer::Analyzer() {
  this->generateSingleTokens();
  this->generateWordTokens();
}

void Analyzer::generateSingleTokens() {
  this->singleTokens.push_back(Token("numeral", "#"));
  this->singleTokens.push_back(Token("PuntoYComa", ";"));
  this->singleTokens.push_back(Token("Punto", "."));
  this->singleTokens.push_back(Token("Igual", "="));
  this->singleTokens.push_back(Token("Menor", "<"));
  this->singleTokens.push_back(Token("Mayor", ">"));
  this->singleTokens.push_back(Token("SignoSuma", "+"));
  this->singleTokens.push_back(Token("SignoMultiplicacion", "*"));
  this->singleTokens.push_back(Token("SignoResta", "-"));
  this->singleTokens.push_back(Token("SignoDivision", "/"));
  this->singleTokens.push_back(Token("DosPuntos", ":"));
  this->singleTokens.push_back(Token("SignoResiduo", "%"));
  this->singleTokens.push_back(Token("ParentesisIzq", "("));
  this->singleTokens.push_back(Token("ParentesisDer", ")"));
  this->singleTokens.push_back(Token("LlavesDer", "{"));
  this->singleTokens.push_back(Token("LlavesIzq", "}"));
  string letters = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < letters.length(); i++) {
    string s(1, letters[i]);
    this->singleTokens.push_back(Token("Id", s));
  }
}

bool Analyzer::haveSingleToken(string ref) {
  for (int i = 0; i < ref.length(); i++) {
    string s(1, ref[i]);
    for (Token token : this->singleTokens) {
      if (token.getVal() == s)
        return true;
    }
  }
  return false;
}

Token Analyzer::getSingleToken(string ref) {
  for (int i = 0; i < this->singleTokens.size(); i++) {
    if (ref == this->singleTokens[i].getVal())
      return this->singleTokens[i];
  }
  return Token("", "");
}

void Analyzer::searchSingleToken(string line) {}

void Analyzer::generateWordTokens() {
  this->wordTokens.push_back(Token("reservada", "iostream"));
  this->wordTokens.push_back(Token("reservada", "stdio"));
  this->wordTokens.push_back(Token("reservada", "stdlib"));
  this->wordTokens.push_back(Token("reservada", "io"));
  this->wordTokens.push_back(Token("reservada", "include"));
  this->wordTokens.push_back(Token("reservada", "int"));
  this->wordTokens.push_back(Token("reservada", "float"));
  this->wordTokens.push_back(Token("reservada", "if"));
  this->wordTokens.push_back(Token("reservada", "char"));
  this->wordTokens.push_back(Token("reservada", "for"));
  this->wordTokens.push_back(Token("reservada", "while"));
  this->wordTokens.push_back(Token("reservada", "string"));
  this->wordTokens.push_back(Token("reservada", "printf"));
  this->wordTokens.push_back(Token("reservada", "cout"));
  this->wordTokens.push_back(Token("reservada", "using"));
  this->wordTokens.push_back(Token("reservada", "namespace"));
  this->wordTokens.push_back(Token("reservada", "std"));
  this->wordTokens.push_back(Token("reservada", "main"));
  this->wordTokens.push_back(Token("reservada", "endl"));
  this->wordTokens.push_back(Token("reservada", "iostream"));
  this->wordTokens.push_back(Token("reservada", "\n"));
}

void Analyzer::searchWordToken(string line) {}

bool Analyzer::isLetter(string line) {
  string letters = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < line.length(); i++) {
    if (line[i] == letters[i]) {
      return true;
    }
  }
  return false;
}

string Helper::removeSubString(string line, int x, int y) {
  string a_string = line.substr(0, x);
  string b_string = line.substr(y + 1, line.length() - 1);
  string new_string = a_string + b_string;
  return new_string;
}

string Helper::deleteStringFromLine(string line, string ref) {
  for (int i = 0; i < line.length(); i++) {
    int real_distance = ref.length() - 1;
    if (i + real_distance > ref.length())
      return line;
    if (Helper::isTheString(line, i, i + real_distance, ref)) {
      string linr = Helper::removeSubString(line, i, i + real_distance);
      return linr;
    }
  }

  return line;
}

bool Helper::isTheString(string line, int x, int y, string ref) {
  string new_string = "";
  for (int i = x; i <= y; i++) {
    new_string += line[i];
  }
  return new_string == ref;
}

string Analyzer::compareLine(string line) {
  ofstream archivo;
  archivo.open("salida.txt", ios::app);
  if (!archivo.is_open()) {
    cout << "error abriendo xd \n";
  }

  int posx = 0;
  int posy = 0;
  for (int i = 0; i < line.length(); i++) {
    if (line[i] == '\"') {
      posx = i;
      break;
    }
  }
  for (int i = posx + 1; i < line.length(); i++) {
    if (line[i] == '\"') {
      posy = i;
      break;
    }
  }

  if (posx != 0) {
    string nueva = "";
    string aux = "";
    for (int i = 0; i < line.length(); i++) {
      if (i < posx || i > posy) {
        nueva += line[i];
      } else {
        aux += line[i];
      }
    }
    archivo << "<" << aux << "> "
            << " cadena " << endl;
    line = nueva;
  }

  for (Token item : this->wordTokens) {
    string prev_string = line;
    if (line.length() > item.getVal().length()) {
      line = Helper::deleteStringFromLine(line, item.getVal());
      if (line.length() != prev_string.length()) {
        archivo << "<" << item.getVal() << ">  " << item.getId() << endl;
      }
    }
  }

  if (this->isLetter(line)) {
    string rep = line;
    for (int i = 0; i < line.length(); i++) {
      if (std::isalpha(line[i]) != 0) {
        archivo << "<id>" << line[i] << endl;
      }
      rep += line[i];
    }
    line = rep;
  }

  for (Token item : this->singleTokens) {
    string prev_string = line;
    if (line == "")
      return line;
    if (!this->haveSingleToken(line)) {
      archivo << "vacia: " << line << endl;
      return "";
    }
    line = this->deleteCharFromLine(line, item.getVal());
    if (line.length() != prev_string.length()) {
      archivo << "<" << item.getVal() << "> " << item.getId() << endl;
    }
  }
  if (archivo.is_open())
    archivo.close();
  return line;
}

string Helper::removeSubStringForChar(string line, string ref) {
  string new_string = "";
  for (int i = 0; i < line.length(); i++) {
    string s(1, line[i]);
    if (s != ref) {
    }
  }
  return new_string;
}

string Analyzer::deleteCharFromLine(string line, string ref) {
  for (int i = 0; i < line.length(); i++) {
    string s(1, line[i]);
    if (s == ref) {
      line = Helper::removeSubStringForChar(line, s);
      return line;
    }
  }
  return line;
}

void Analyzer::analyzeLine(string line) {
  line.erase(remove(line.begin(), line.end(), ' '), line.end());
  while (line != "") {
    line = this->compareLine(line);
  }
}
