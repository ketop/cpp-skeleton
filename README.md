# cpp project skeleton
c++ project skeleton, use c++14 standard for generic use. it's a good template for starter.
this code base use googletest for unit testing, and benchmark for benchmark tesing.



## Build Architecture
- x86_64

## Build Compiler
- g++(GCC) 12.2.1
- cmake 3.26.3
- make  4.4.1


## Requirements
- googletest
- benchmark
- spdlog
- nlohmann/json


## Build
```bash
cmake -H. -Bbuild
cmake --build build
```
after build succeed, all application binaries will be put at *./bin*

## Running App
```
cd bin && ./app
```


## Running Test
```bash
cd bin && ./apptest

```

## Running Benchmark
```bash
cd bin && ./appbenchmark
```
