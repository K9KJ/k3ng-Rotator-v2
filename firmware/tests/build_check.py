Import("env")

# Evaluate the compile-time checks here, before the firmware link step.
check_env = env.Clone()
check_env.Append(CCFLAGS=["-fno-lto"])
check = check_env.Object("$BUILD_DIR/tests/encoder_delta.o", "$PROJECT_DIR/tests/encoder_delta.cpp")
env.Depends("$BUILD_DIR/${PROGNAME}.elf", check)
