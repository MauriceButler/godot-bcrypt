#!/usr/bin/env python
import os
import sys
import shutil

env = SConscript("godot-cpp/SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
env.Append(CPPPATH=["libbcrypt/include/"])
env.Append(LIBS = ['bcrypt'], LIBPATH = ['libbcrypt/build'])
sources = Glob("src/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "bcryptDemo/bin/godotBcrypt/godotBcrypt.{}.{}".format(env["platform"], env["target"]),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "bcryptDemo/bin/godotBcrypt/godotBcrypt{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
shutil.copyfile("godotBcrypt.gdextension", "bcryptDemo/bin/godotBcrypt/godotBcrypt.gdextension")
