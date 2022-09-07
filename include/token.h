
#include <iostream>
using namespace std;

class Token{
  private:
    string id;
    string value;
  public:
    Token();
    Token(string, string);
    string getId();
    string getVal();
};
