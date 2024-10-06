#include "src/Core/Core.hpp"

int main(int argc, const char **argv) {
  EngineApp *app = new EngineApp();
  app->Init();
  app->StartEngineLoop();
  delete app;
  return 0;
}