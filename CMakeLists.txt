cmake_minimum_required(VERSION 3.10)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://codeload.github.com/Bjoe/hunter/legacy.zip/5dc9ecc9c76ea37e5fe5096442a206a1ce8de9c1"
    SHA1 "236137cd82f86ad7d0679fa0203b2f35bffc8e0a"
    LOCAL
)

project(poco-hunter-example)

hunter_add_package(OpenSSL)
hunter_add_package(PocoCpp)

find_package(OpenSSL REQUIRED)
find_package(Poco REQUIRED Foundation Crypto)

add_executable(phe "main.cpp")
target_link_libraries(phe Poco::Foundation Poco::Crypto OpenSSL::Crypto)
