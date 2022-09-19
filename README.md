# Lexical Analyzer
  
  > A simple **Lexical** Analizer for C/C++ Languages
  
### Dependencies

- [g++ compiler](https://www.guru99.com/c-gcc-install.html) 
  
## Dev Guide
  We need pass like argument to the program all files we want to analyze
  > Linux
```bash
  cd
  git clone https://github.com/Olstertecn11/analizador-lexico.git
  cd analizador-lexico
  chmod +x compile.sh
  ./compile.sh
  ./build/main ~/analizador-lexico/build/file.cpp ~/analizador-lexico/build/prueba.cpp
```

  > **Windows** *( Need Compile again )*
```powershell
  cd
  git clone https://github.com/Olstertecn11/analizador-lexico.git
  cd analizador-lexico
  g++ -std=c++17 ./src/main.cpp -o ./build/main
  ./build/main ~/analizador-lexico/build/file.cpp ~/analizador-lexico/build/prueba.cpp
```
