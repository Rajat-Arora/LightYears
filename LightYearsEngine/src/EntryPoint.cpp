#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
    std::unique_ptr<ly::Application> app = GetApplication();
    app->Run();
}