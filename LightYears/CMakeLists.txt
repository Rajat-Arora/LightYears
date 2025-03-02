include(${CMAKE_SOURCE_DIR}/cmake/CopyLibToTarget.cmake)

add_executable(${LIGHT_YEARS_GAME_TATRGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
)

target_include_directories(${LIGHT_YEARS_GAME_TATRGET_NAME} PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${LIGHT_YEARS_GAME_TATRGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_GAME_TATRGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_GAME_TATRGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEARS_GAME_TATRGET_NAME} PUBLIC sfml-audio)

CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_GAME_TATRGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_GAME_TATRGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_GAME_TATRGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_GAME_TATRGET_NAME})