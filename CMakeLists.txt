cmake_minimum_required(VERSION 3.16.3)

#Details of Project Version and Language
project(LightYears
    VERSION 1.0.0
    LANGUAGES C CXX
)

#Cpp Standard
set(CMAKE_CXX_STANDARD 14)

#Enforce the Cpp Standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Don't use Cpp extensions as it may vary from OS to OS
set(CMAKE_CXX_EXTENSIONS OFF)

#Used to fetch content from some other source
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

set(SFML_LIB_NAME SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 2.5.1
    GIT_SHALLOW FALSE 
    GIT_PROGRESS TRUE
)

#After Fetch make it available for our project
FetchContent_MakeAvailable(${SFML_LIB_NAME})

#Creates a variable: Var_Name Var_Value
set(LIGHT_YEARS_GAME_TATRGET_NAME LightYearsGame)

#Add directory LightYears relative to this file
add_subdirectory(LightYears)