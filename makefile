# Set to @ to keep this makefile quiet
SILENCE = @

ALL_TEST_MODULES = \
				   ATtiny \
				   SpiHw



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



#############################
### Auto-generated values ###
#############################
# If user did not specify a module to test, test all of them.
ifeq ($(strip $(TEST_MODULE)),)
	TEST_MODULE = $(ALL_TEST_MODULES)
endif



###############
### Targets ###
###############
.PHONY: $(TEST_MODULE) clear

test: clear $(TEST_MODULE)

$(TEST_MODULE):
	$(SILENCE)$(MAKE) $(TEST_MAKEFILE) test TEST_MODULE=$@

clean:
	$(SILENCE)$(MAKE) $(TEST_MAKEFILE) clean

# clear the terminal screen
clear:
	@clear
