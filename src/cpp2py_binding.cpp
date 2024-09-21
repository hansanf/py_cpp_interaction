#include <pybind11/pybind11.h>
#include <iostream>

namespace py = pybind11;

class LaneInstance {
public:
    int id;

    LaneInstance() : id(0) {}

    void print() const {
        std::cout << "Lane ID: " << id << std::endl;
    }
};

LaneInstance get_lane_instance_from_cpp() {
    LaneInstance lane;
    // 填充 lane 对象的数据
    lane.id = 99;
    return lane;
}

// 自定义类型转换器
namespace pybind11 { namespace detail {
template <>
struct type_caster<LaneInstance> {
public:
    PYBIND11_TYPE_CASTER(LaneInstance, _("LaneInstance"));

    bool load(handle src, bool convert) {
        // 从 Python 对象转换到 C++ 对象（这里不实现，因为我们只关心从 C++ 到 Python 的转换）
        return false;
    }

    static handle cast(const LaneInstance &src, return_value_policy policy, handle parent) {
        // 将 C++ 对象转换为 Python 字典
        pybind11::dict dict;
        dict["id"] = src.id;
        return dict.release();
    }
};
}} // namespace pybind11::detail


PYBIND11_MODULE(cpp2py_binding, m) {
    m.def("get_lane_instance", &get_lane_instance_from_cpp, "Get a LaneInstance object from C++");
}