add_rules("mode.debug", "mode.release")
set_languages("c++23")

target("cpp")
set_default(true)
set_kind("binary")
add_files("temp_code/cpp/src/main.cpp")
set_optimize("faster")

target("test")
set_default(false)
set_kind("binary")
add_files("temp_code/cpp/test/*.cpp")
set_optimize("faster")
