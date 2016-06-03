#############################
### Project configuration ###
#############################
SRC_DIRS = src
INC_DIRS = inc ../bit_manip/inc
TEST_DIRS = test/$(TEST_MODULE)
BUILD_DIR = build
OBJECT_DIR = obj

# Pass project configuration to the submake
export SRC_DIRS
export INC_DIRS
export TEST_DIRS
export BUILD_DIR
export OBJECT_DIR
