BUILD = build
TEST = test
BIN = bin
TARGET = bin/fractal
TARGET2 = bin/test
SRCDIR = src
SRCFILES = $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJ=$(patsubst $(SRCDIR)/%,$(BUILD)/%,$(SRCFILES:.cpp=.o))
TESTOBJ=$(patsubst $(SRCDIR)/%,$(TEST)/%,$(SRCFILES:.cpp=.o))
FLAGS = -DRULE1
FLAGS2 = -DRULE2
#LIBS = $(shell pkg-config --cflags --libs Qt6Widgets) -fPIC
LIBS = 
CC = g++
INC = -I include

all: $(TARGET) 

$(TARGET): $(OBJ)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET) $(LIBS) ";
	$(CC) $^ -o $(TARGET) $(LIBS) $(INC) 

$(BUILD)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILD)
	@mkdir -p $(BIN)
	$(CC)  $(LIBS) $(INC) -c $^ -o $@  $(FLAGS)

$(TEST)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(TEST)
	$(CC)  $(LIBS) $(INC) -c $^ -o $@  $(FLAGS2)

.PHONY: clean
clean:
	@echo "Cleaning..."
	@echo " $(RM)  $(BUILD) $(BIN)"
	$(RM) -r $(BUILD) $(BIN)
cleantest:
	@echo "Cleaning..."
	@echo " $(RM)  $(TEST) "
	$(RM) -r $(TEST)
