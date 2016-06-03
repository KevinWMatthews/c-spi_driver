# Set to @ to keep this makefile quiet
SILENCE = @

ALL_TEST_MODULES = \
				   ATtiny \
				   ChipFunctions \
				   Spi


CFLAGS = -Wfatal-errors

export CFLAGS


##############################
### Makefile configuration ###
##############################
# Set to 'Y' to suppress makefile messages when entering and leaving sub-makes.
SUPPRESS_ENTERING_DIRECTORY_MESSAGE = Y
ifeq ($(SUPPRESS_ENTERING_DIRECTORY_MESSAGE),Y)
	NO_PRINT_DIRECTORY = --no-print-directory
endif

TEST_MAKEFILE = Makefile_CppUTest.make
MAKE = make $(NO_PRINT_DIRECTORY) --file
CLEAR = clear

# Pass makefile configuration to the submakes
export NO_PRINT_DIRECTORY
export TEST_MAKEFILE
export MAKE



#############################
### Auto-generated values ###
#############################
# If user did not specify a module to test, test all of them.
ifeq ($(strip $(TEST_MODULES)),)
	TEST_MODULES = $(ALL_TEST_MODULES)
endif



###############
### Targets ###
###############
# Generating the target for the submake in this fashion enables us to use the TEST_MODULES target.
ifeq ($(MAKECMDGOALS),test)
	SUBMAKE_TARGET = test
endif
ifeq ($(MAKECMDGOALS),clean)
	SUBMAKE_TARGET = clean
endif

.PHONY: test clean $(TEST_MODULES) clear

test: clear $(TEST_MODULES)
	@echo "Built and tested: $(TEST_MODULES)"

clean: $(TEST_MODULES)
	@echo "Cleaned: $(TEST_MODULES)"

$(TEST_MODULES):
# Using $@ trims the whitespace
	$(SILENCE)$(MAKE) Makefile_$@.make $(SUBMAKE_TARGET) TEST_MODULE=$@

# clear the terminal screen
clear:
	$(CLEAR)
