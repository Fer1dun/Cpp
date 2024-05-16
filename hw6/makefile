SRC_DIR := .
OBJ_DIR := .obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)
TARGET := main.out
CXX := g++
CPPFLAGS := -I$(SRC_DIR)
CXXFLAGS := -std=c++11 

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_FILES) $(DEP_FILES) $(TARGET)

-include $(DEP_FILES)
