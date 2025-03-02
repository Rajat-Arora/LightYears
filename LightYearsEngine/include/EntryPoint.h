#pragma once
#include<memory>

namespace ly
{
    class Application;
    
} // namespace ly

//Function needs to be implemented by the client of the Application
extern std::unique_ptr<ly::Application> GetApplication();