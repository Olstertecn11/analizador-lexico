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
    Analyzer();
    vector<string> split(string);
    void generateTokens();
    void searchSingleToken(string);
    void searchWordToken(string);
};
