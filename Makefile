

################################################################################
#
#
#
#
###############################################################################


#WORK_DIR = `pwd`
WORK_DIR = .
OBJ_DIR  = $(WORK_DIR)/obj
QUIET    = 

SRC_DIR  = $(WORK_DIR)/src
INC_DIR  = $(WORK_DIR)/include

CC  ?= gcc
CCPP?= g++

test:
	@echo WORK_DIR=$(WORK_DIR)
	@echo OBJ_DIR=$(OBJ_DIR)
	@echo SRC_DIR=$(SRC_DIR)
	@echo INC_DIR=$(INC_DIR)
	@echo CC     =$(CC)
	@echo CCPP   =$(CCPP)


%.c:%.o
	$(QUIET) == "" && @echo 



