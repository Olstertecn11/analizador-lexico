#include "./../src/analyzer.cpp"
/* #include "analyzer.h" */
/* #include "./../include/analyzer.h" */



class A_Controller{
  public:
    A_Controller();
    Analyzer analyzer;
    void readArguments(int, char *[]);
    void loadFile(std::string);
    void multiRead(int, char *[]);
};
