# Function to copy SFML DLLs to the executable directory (Windows-specific)
function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:${LIB_NAME}>
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    $<TARGET_FILE_DIR:${LIB_NAME}>
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()