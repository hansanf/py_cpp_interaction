# py_cpp_interaction

cmake -B build
cd build
make

export PYTHONPATH=${PYTHONPATH}:$(pwd)
python3
>>> import cpp2py_binding as cpp
>>> cpp.get_lane_instance()