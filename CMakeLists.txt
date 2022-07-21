cmake_minimum_required(VERSION 2.8.4)

project(NPnP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
SET( CMAKE_EXE_LINKER_FLAGS "-Wl,--no-as-needed" ) 
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_compile_options(-Wall -Wextra -Wconversion -O3 -flto) 

find_package(OpenCV REQUIRED)
find_package(Eigen3 3.3.0 REQUIRED)

set(sample_pnplib
        ${src_dir}/PnP/PnpInput.cpp
        ${src_dir}/Utils_pnp/Parsing.cpp
        ${src_dir}/PnP/PnpObjective.cpp
        ${src_dir}/PnP/PnpProblemSolver.cpp
        ${src_dir}/PnP/DualVar.cpp
        ${src_dir}/PnP/PnpBarrierMethodSolver.cpp
        ${src_dir}/Utils_pnp/GeneralUtils.cpp
        ${src_dir}/PnP/PnpResult.cpp
        ${src_dir}/PnP/PnpLocalSearch.cpp
        ${src_dir}/PnP/QuaternionVector.cpp
        )

set(src_files
	${src_dir}/RansacOptimalPnP/RansacOptimalPnP.cpp
	${src_dir}/CSVReader/CSVReader.cpp
	)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${src_dir})
include_directories(${src_dir}/Utils_pnp
                    ${src_dir}/PnP)

add_executable(NPnP ${src_dir}/main.cpp 
                    ${src_files}
                    ${sample_pnplib})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} Eigen3::Eigen)