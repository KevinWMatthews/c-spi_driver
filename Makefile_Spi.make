# Set to @ to keep this makefile quiet
SILENCE = @



#############################
### Project configuration ###
#############################
SRC_DIRS = src 
INC_DIRS = inc mockHw ../bit_manip/inc
TEST_MODULE = Spi



##############################
### Makefile configuration ###
##############################
# Set to 'Y' to suppress makefile messages when entering and leaving sub-makes.
SUPPRESS_ENTERING_DIRECTORY_MESSAGE = Y
ifeq ($(SUPPRESS_ENTERING_DIRECTORY_MESSAGE),Y)
	NO_PRINT_DIRECTORY = --no-print-directory
endif

TEST_MAKEFILE = makefile_cpputest.make
MAKE = make $(NO_PRINT_DIRECTORY) --file

# Pass project configuration to the submake
export SRC_DIRS
export INC_DIRS
export TEST_MODULE

# Pass makefile configuration to the submake
export NO_PRINT_DIRECTORY



###############
### Targets ###
###############
.PHONY: test clean
test clean:
	$(MAKE) $(TEST_MAKEFILE) $@

