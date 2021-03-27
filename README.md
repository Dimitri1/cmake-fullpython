# Status

[![Build Status](https://github.com/Dimitri1/cmake-fullpython/actions/workflows/main.yml/badge.svg)

# Problem to solve

The main objective of cmake-fullpython.cmake is
to provide a frame to helps developers to adress software
fragmentation problem in projects that require
a cmake downstream python integration.

# Proposed solution

cmake-fullpython.cmake provides a python executable
that belongs to the folowing diagram.

```bash

 |-----------------------------------------|
 |                                         |
 |         upstream cmake project          |
 |                                         |
 |-----------------------------------------|
 |                                         |
 |    pybind11     python3    virtualenv   | 
 |                                         |
 |-----------------------------------------|
 |                                         |  ----------------------------------
 |                                         |      |                             |
 |                                         |      |                             |
 |                                         |   [PYBIND11 .so CPP API]     [cmakeHook.py] (upstram CMAKE variables)
 |					   |      |                    	        |
 |					   |      |                    	        |
 |					   |      |                    	        |
 |         cmake-fullpython.cmake          |  -------------------------------------------> [venv/bin/python]
 |                                         |                                               | ../site-packages/pipPackages..
 |                                         |                                                                 /...     
 |-----------------------------------------|
 ```


# Usage

- Clone this repository:

```bash
git clone https://github.com/Dimitri1/cmake-fullpython
```

- Configure system:

```bash
configure.sh
```

- Launch tests

```bash
docker  run -it -v $PWD:/work hdgerin/cmake-fullpython:${DIST}-latest  bash -c "mkdir  /tmp/build /tmp/install && cd /tmp/build && cmake -DINSTALL=/tmp/install  /work/examples/[exampleDir] && make && ctest -V"
```


## Authors

- Dimitri Gerin <dimitri.gerin@gmail.com>
