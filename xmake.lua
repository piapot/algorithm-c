add_rules("mode.debug", "mode.release")

add_requires("gtest", {alias = "gtest"})

add_includedirs("include")

target(("data_structure"))
    set_kind("shared")
    add_files("src/data_structure/*.c")

target("test")
    set_kind("binary")
    add_deps("data_structure")
    add_packages("gtest")
    add_files("tests/*.cpp")
    add_files("tests/data_structure/*.cpp")
