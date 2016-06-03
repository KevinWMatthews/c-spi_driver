# Set to @ to keep this makefile quiet
SILENCE = @



#############################
### Project configuration ###
#############################
SRC_DIRS = src platform/src mockHw/avr
INC_DIRS = inc platform/inc mockHw ../bit_manip/inc

# Pass project configuration to the submake
export SRC_DIRS
export INC_DIRS



###############
### Targets ###
###############
.PHONY: test clean
test clean:
	$(SILENCE)$(MAKE) $(TEST_MAKEFILE) $@
