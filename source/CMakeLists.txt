include_directories(${CompPhys_SOURCE_DIR}/include)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(CompPhys main.cpp 
                        Integration.cpp
                        Interpolation.cpp
                        LinearSystems.cpp
                        EigenFinders.cpp
                        RootFinders.cpp
                        Derivatives.cpp)
target_link_libraries(CompPhys Eigen3::Eigen)