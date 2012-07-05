

################################################################################
#
#
#
#
###############################################################################


QUIET   ?= @ 

#WORK_DIR = `pwd`
WORK_DIR  = .
OBJ_DIR   = $(WORK_DIR)/obj
SRC_DIR   = $(WORK_DIR)/src
INC_DIR   = $(WORK_DIR)/include
BIN_DIR   = $(WORK_DIR)/bin
TEST_DIR  = $(WORK_DIR)/test

BIN_TARGET= $(BIN_DIR)/memDetector

CC       ?= g++ 
LD        = g++
CFLAG    += -Winline 
INC_FLAG += -I. -I$(INC_DIR)
LD_FLAG  +=

#OBJ_FILE=$(OBJ_DIR)/main.o
OBJ_FILE += $(OBJ_DIR)/memDetector.o
OBJ_FILE += $(OBJ_DIR)/main.o
OBJ_FILE += $(OBJ_DIR)/biTree.o

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@echo " [SRC CC]  $@"
	@echo " "
	$(QUIET) rm -rf $@
	$(QUIET)$(CC) $(CFLAG) $(INC_FLAG) -o $@ -c $<

$(OBJ_DIR)/%.o:$(TEST_DIR)/%.cpp
	@echo " [SRC CC]  $@"
	@echo " "
	$(QUIET) rm -rf $@
	$(QUIET)$(CC) $(CFLAG) $(INC_FLAG) -o $@ -c $<


all:$(BIN_TARGET)

clean:
	@echo " [ Project CleaUp!!] "
	$(QUIET)rm -rf $(OBJ_DIR)
	$(QUIET)rm -rf $(BIN_DIR)

$(BIN_TARGET): $(OBJ_DIR) $(OBJ_FILE)
	@echo " [APP LD] $@"
	$(QUIET)$(LD) -Wl -o $@ $(OBJ_FILE)
	@echo "   -------[Execute Bin]-------- "
	./$@

$(OBJ_DIR):
	$(QUIET)rm -rf $(OBJ_DIR)
	$(QUIET)mkdir -p $(BIN_DIR)
	$(QUIET)mkdir -p $(OBJ_DIR)


test1:
	@echo WORK_DIR=$(WORK_DIR)
	@echo OBJ_DIR =$(OBJ_DIR)
	@echo SRC_DIR =$(SRC_DIR)
	@echo INC_DIR =$(INC_DIR)
	@echo CC      =$(CC)
	@echo CCPP    =$(CCPP)






