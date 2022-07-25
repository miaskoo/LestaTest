cmake_minimum_required(VERSION 3.22.1)

project(LestaTest LANGUAGES C CXX)

set(CPP_VERSION 17)

# includes
include_directories("./" "src/classes/header" "src/another/header" "GL" "glut")
link_directories("./")

# test
file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE SOURCES src/*.cpp)
# Glut
file(GLOB_RECURSE HEADERS_GLUT glut/*.h "GL/glut.h")
file(GLOB_RECURSE SOURCES_GLUT glut/*.c)

#add filterSs
source_group("test/header" FILES ${HEADERS})
source_group("test/source" FILES ${SOURCES})
source_group("glut" FILES ${SOURCES_GLUT})


add_executable(${PROJECT_NAME} "main.cpp" "nvToolsExt.h" "test.h" "test.cpp" ${HEADERS} ${SOURCES} ${SOURCES_GLUT})
target_link_libraries(${PROJECT_NAME} nvToolsExt32_1.lib glu32.lib winmm.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib)

add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_CONSOLE -DWIN32)
add_compile_definitions($<$<CONFIG:DEBUG>:DEBUG> $<$<CONFIG:RELEASE>:NDEBUG>)



set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
