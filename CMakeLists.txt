cmake_minimum_required(VERSION 3.16)

project(ExperimentProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SRC_FILES src/*.cpp)

foreach(src_file ${SRC_FILES})
    get_filename_component(basename ${src_file} NAME_WE)
    
    set(exe_name "${basename}_exec")
    
    add_executable(${exe_name} ${src_file})
    
    target_precompile_headers(${exe_name} PRIVATE include/utils.hpp)
    
    string(REPLACE "_" ";" parts_list "${basename}")
    
    set(shorthand "")
    foreach(part IN LISTS parts_list)
        string(SUBSTRING ${part} 0 1 char)
        set(shorthand "${shorthand}${char}")
    endforeach()
    
    add_custom_target(${shorthand}
        DEPENDS ${exe_name}
        COMMAND $<TARGET_FILE:${exe_name}>
        COMMENT "Running ${basename} via shorthand '${shorthand}'"
    )
    
    add_custom_target(${basename}
        DEPENDS ${exe_name}
        COMMAND $<TARGET_FILE:${exe_name}>
        COMMENT "Running ${basename} via full name"
    )
endforeach()
