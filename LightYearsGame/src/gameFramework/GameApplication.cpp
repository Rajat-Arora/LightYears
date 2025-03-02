#include "gameFramework/GameApplication.h"

std::unique_ptr<ly::Application> GetApplication()
{
    return std::make_unique<ly::GameApplication>();
}