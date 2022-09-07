#include <vector>
#include <iostream>
/* #include "token.cpp" */
#include "./../src/token.cpp"
using namespace std;


class Analyzer
{
  private:
    vector<Token> singleTokens;
    vector<Token> wordTokens;
    /* vector<Token> foundTokens; */
  public:
    Analyzer();
    /* vector<string> split(string); */
    void generateSingleTokens();
    void generateWordTokens();
    void searchSingleToken(string);
    /* void searchWordToken(string); */
    bool isSinleToken(string);
    Token getSingleToken(string);
    
};
