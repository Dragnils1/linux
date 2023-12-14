# Имя вашего исполняемого файла
TARGET = main

# Исходные файлы
SOURCES = main.cc

# Флаги компилятора
CXXFLAGS = -Wall $(shell pkg-config --cflags zlib)

# Флаги линковщика
LDFLAGS = $(shell pkg-config --libs zlib)

# Объектные файлы
OBJECTS = $(SOURCES:.cc=.o)

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Правило для объектных файлов
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки проекта
clean:
	rm -f $(TARGET) $(OBJECTS)

# Дополнительные зависимости
main.o: main.hh
