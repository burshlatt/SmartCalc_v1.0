# Путь к директории с исходными файлами на языке C
C_SRC_DIR = CFiles

# Путь к директории с исходными файлами на языке C++/Qt
QT_SRC_DIR = SmartCalc

# Путь к директории, в которую будут сохранены объектные файлы и исполняемый файл
OBJ_DIR = test

# Имя исполняемого файла
TARGET = $(OBJ_DIR)/SmartCalc

# Список исходных файлов на языке C
C_SOURCES = $(wildcard $(C_SRC_DIR)/*.c)

# Список исходных файлов на языке C++/Qt
QT_SOURCES = $(wildcard $(QT_SRC_DIR)/*.cpp $(QT_SRC_DIR)/*.ui $(QT_SRC_DIR)/*.pro)

# Список объектных файлов
C_OBJECTS = $(patsubst $(C_SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(filter %.c,$(C_SOURCES)))
QT_OBJECTS = $(patsubst $(QT_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter %.cpp,$(QT_SOURCES))) \
            $(patsubst $(QT_SRC_DIR)/%.ui,$(OBJ_DIR)/%.o,$(filter %.ui,$(QT_SOURCES)))
OBJECTS = $(C_OBJECTS) $(QT_OBJECTS)

# Компиляторы и опции компиляции
CC = gcc
CXX = g++
CFLAGS = -Wall -g
CXXFLAGS = $(CFLAGS) -std=c++11 `pkg-config --cflags Qt5Widgets`
LDFLAGS = `pkg-config --libs Qt5Widgets`

# Цель по умолчанию
all: $(TARGET)

# Компиляция объектных файлов на языке C
$(OBJ_DIR)/%.o: $(C_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Компиляция объектных файлов на языке C++/Qt
$(OBJ_DIR)/%.o: $(QT_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

# Установка программы
install:
	install -m 755 $(TARGET) /usr/local/bin

uninstall:
	rm -f /usr/local/bin/$(notdir $(TARGET))
	
clean:
	rm -f $(OBJECTS) $(TARGET)

dvi:
	latex refman.tex

dist:
	tar -czvf SmartCalc.tar.gz $(C_SOURCES) $(QT_SOURCES) Makefile refman.tex refman.pdf
	
tests:
	./$(TARGET) --test
	
gcov_report:
	gcov -o $(OBJ_DIR) $(C_SOURCES)
