echo "Compilando"
g++ -std=c++17 ./src/main.cpp -o ./build/main
./build/main ./build/file.cpp ./build/prueba.cpp
