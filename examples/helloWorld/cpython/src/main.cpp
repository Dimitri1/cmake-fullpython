#include <type_traits>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <memory>
#include <vector>

namespace py = pybind11;

void hello()
{
	std::cout << "hello cpython" << "\n";
}

// std::map<std::string, py::array_t<double>> vectToMapVect(std::vector<py::array_t<double>> npVec)
// {
// }

PYBIND11_MODULE(mainCpython, m)
{
	m.def("hello", &hello, "hello");
	// m.def("vectToMapVect", &vectToMapVect, "vectToMapVect");
}
