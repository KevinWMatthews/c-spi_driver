#############################
### Project configuration ###
#############################
SRC_DIRS = src platform/src mockHw/avr
INC_DIRS = inc platform/inc mockHw ../bit_manip/inc
TEST_DIRS = test/$(TEST_MODULE)
BUILD_DIR = build
OBJECT_DIR = obj

# Pass project configuration to the submake
export SRC_DIRS
export INC_DIRS
export TEST_DIRS
export BUILD_DIR
export OBJECT_DIR
