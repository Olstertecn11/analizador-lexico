#include "arguments_controller.cpp"

int main(int argc, char *argv[]) {
  A_Controller args_controller = A_Controller();
  args_controller.readArguments(argc, argv);
}
