cmake_minimum_required(VERSION 3.14)
include(CPM.cmake)

CPMAddPackage(
  NAME pybind11
  GIT_TAG v2.9
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
)

CPMAddPackage(
  NAME eigen
  URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
)


pybind11_add_module(cpp2py_binding src/cpp2py_binding.cpp)
target_link_libraries(cpp2py_binding PUBLIC python3.8)
target_include_directories(cpp2py_binding
    PRIVATE ${pybind11_SOURCE_DIR}/include
    PRIVATE ${eigen_SOURCE_DIR}
    PRIVATE /usr/include/python3.8
)

# target_include_directories(${PROJECT_NAME} 
#     PRIVATE ${pybind11_SOURCE_DIR}/include
#     PRIVATE ${eigen_SOURCE_DIR}
#     PRIVATE /usr/include/python3.8
# )
# target_link_libraries(${PROJECT_NAME} PUBLIC python3.8)
# target_sources(${PROJECT_NAME} PRIVATE src/pyprocess/pyprocess.cpp)
# install(FILES src/pyprocess/ldmap_preprocess.py DESTINATION .)