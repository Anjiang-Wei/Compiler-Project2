file(GLOB test_src "*.cc")
file(GLOB kernel_src "./kernels/*.cc")
file(GLOB solution_src "./solution/*.cc")
file(GLOB clean_src "./clean/*.cc")

# antlr runtime lib
file(GLOB antlr4-cpp-src
        ../runtime/src/*.cpp
        ../runtime/src/atn/*.cpp
        ../runtime/src/dfa/*.cpp
        ../runtime/src/misc/*.cpp
        ../runtime/src/support/*.cpp
        ../runtime/src/tree/*.cpp
        ../runtime/src/tree/pattern/*.cpp
        ../runtime/src/tree/xpath/*.cpp
        )

# add antlr include
include_directories(
        ../include
        ../generated
        ../runtime/src
)

# add antlr visitor src
set(antlr_src
        ../generated/projectExprLexer.cpp
        ../generated/projectExprParser.cpp
        ../generated/projectExprVisitor.cpp
        ../generated/projectExprBaseVisitor.cpp
        )
add_library (antlr4-cpp-runtime ${antlr4-cpp-src})


add_executable(test1 ${test_src} ${kernel_src})
add_executable(solution ${solution_src} ${antlr_src})
target_link_libraries(solution ${LIB_NAME})
target_link_libraries(solution antlr4-cpp-runtime) # add antlr library
add_executable(cleanf ${clean_src})

add_custom_target(solution_run
        COMMAND solution
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "run generated solution in ${CMAKE_CURRENT_SOURCE_DIR}"
        SOURCES ${solution_src}
        )

add_custom_target(clean_run
        COMMAND cleanf
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "run generated clean in ${CMAKE_CURRENT_SOURCE_DIR}"
        SOURCES ${clean_src}
        )

add_dependencies(solution_run clean_run)
add_dependencies(test1 solution_run)