#include <vector>
/* #include "token.cpp" */
#include "./../src/token.cpp"


class Analyzer
{
  private:
    vector<Token> singleTokens;
    vector<Token> wordTokens;
    vector<Token> foundTokens;
  public:
    Analyzer();
    vector<string> split(string);
    void generateSingleTokens();
    void generateWordTokens();
    void searchSingleToken(string);
    void searchWordToken(string);
    bool isSinleToken(string);
    Token getSingleToken(string);
    void analyzeLine(string);
    string compareLine(string);
    string deleteCharFromLine(string, string);
};


class Helper{

  public:
    static string deleteStringFromLine(string, string);
    static string removeSubStringForChar(string, string);
    static string removeSubString(string, int , int );
    static bool  isTheString(string, int, int, string);
};




