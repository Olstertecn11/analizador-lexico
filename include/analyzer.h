#include <vector>
#include <iostream>
#include "token.h"
using namespace std;


class Analyzer
{
  private:
    vector<Token> singleTokens;
    vector<Token> wordTokens;
    vector<Token> foundTokens;
  public:
    vector<string> split(string);
    void generateTokens();
    void searchSingleToken(string);
    void searchWordToken(string);
};
