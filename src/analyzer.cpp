#include "./../include/analyzer.h"
#include <algorithm>

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
  string letters = "abcdefjhigklmnñopqrstuvwxyz";
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

  for (Token item : this->wordTokens) {
    string prev_string = line;
    if (line.length() > item.getVal().length()) {
      line = Helper::deleteStringFromLine(line, item.getVal());
      if (line.length() != prev_string.length()) {
        cout << "<" << item.getVal() << ">  " << item.getId() << endl;
      }
    }
  }

  for (Token item : this->singleTokens) {
    string prev_string = line;
    if (line == "")
      return line;
    if (!this->haveSingleToken(line))
      return "";
    line = this->deleteCharFromLine(line, item.getVal());
    if (line.length() != prev_string.length()) {
      cout << "<" << item.getVal() << "> " << item.getId() << endl;
    }
  }
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
