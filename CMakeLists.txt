cmake_minimum_required(VERSION 3.27)
project(lab6_7_clion)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(lab6_7_clion main.cpp
        domain/carte.cpp
        Headers/carte.h
        repository/repo.cpp
        Headers/repo.h
        service/service_biblioteca.cpp
        Headers/service_biblioteca.h
        ui/ui_biblioteca.cpp
        Headers/ui_biblioteca.h
        teste/test_repo.cpp
        Headers/teste.h
        teste/test_domain.cpp
        domain/validator.cpp
        Headers/validator.h
        teste/test_validator.cpp
        teste/test_service.cpp
        Headers/my_vector.h
        Headers/vector_iterator.h
)
