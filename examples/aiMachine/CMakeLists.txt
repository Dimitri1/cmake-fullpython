project(native C CXX)
cmake_minimum_required(VERSION 3.5)

get_filename_component(TOPDIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ ABSOLUTE)
get_filename_component(CMAKEFULLPYTHON ${TOPDIR}/cmake-fullpython.cmake ABSOLUTE)


# setup build/install directories
set(INSTALLDIR ${INSTALL})
get_filename_component(PYTHONSRC ${CMAKE_CURRENT_SOURCE_DIR}/python ABSOLUTE)
get_filename_component(CPYTHONSRC ${CMAKE_CURRENT_SOURCE_DIR}/cpython ABSOLUTE)

set(PYBIND11_INSTALL_DIR /install )

include(${CMAKEFULLPYTHON})
set(CMAKE_MODULE_PATH ${TOPDIR})
set(ENA_VIRTUALENV_DEV_MODE True)
set(REQUIREMENTS ${CMAKE_CURRENT_SOURCE_DIR}/requirements.txt)

# cmake_configure for python hook example variable
set(CMAKE_PYTHON_HOOK_TEST "HELLO-PYTHON-HOOK")

create_virtualenv(main ${PYBIND11_INSTALL_DIR}
	               ${REQUIREMENTS} 
		       cmakeHook.py
		       ${PYTHONSRC}
		       ${CPYTHONSRC}
		       ${INSTALLDIR}
		       ${ENA_VIRTUALENV_DEV_MODE})
	       
	       
enable_testing(TRUE)
add_test(NAME hookCheck
         COMMAND ${INSTALLDIR}/venv-main/bin/python -c "import cmakeHook;print(cmakeHook.hello)")
add_test(NAME cpythonCheck
         COMMAND ${INSTALLDIR}/venv-main/bin/python -c "import mainCpython;print(mainCpython.hello)")
add_test(NAME tfModulesCheck
         COMMAND ${INSTALLDIR}/venv-main/bin/python -c "import tensorflow")
add_test(NAME onnxModulesCheck
         COMMAND ${INSTALLDIR}/venv-main/bin/python -c "import onnx")
add_test(NAME torchModulesCheck
         COMMAND ${INSTALLDIR}/venv-main/bin/python -c "import torch")

