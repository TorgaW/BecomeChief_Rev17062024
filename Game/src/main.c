#include "../../VulpeculaEngine/src/engine/engine.h"
#include "../../VulpeculaEngine/src/sprite/sprite.h"
#include "../../VulpeculaEngine/src/memory/memory.h"

int main(int argc, char* argv[])
{
	SEngineApp engineApp = init_vulpecula_engine();
	loop_vulpecula_engine(&engineApp);
	return 0;
}