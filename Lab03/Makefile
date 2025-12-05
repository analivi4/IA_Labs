
# Define o nome do arquivo executável
TARGET = agente

# Diretórios de cabeçalhos (-I flag)
# Permite que os includes usem o caminho da pasta, ex: #include "Problema/Mapa.h"
INCLUDES = -I. -IBusca -IProblema

# Flags do compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Arquivos fonte (implementações C++)
SOURCES = main.cpp \
          Busca/Buscas.cpp

# Arquivos objeto (gerados a partir dos SOURCES)
# Troca a extensão .cpp por .o (ex: main.cpp -> main.o)
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão: compila os objetos e depois liga para criar o executável
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET)

# Regra genérica para compilar qualquer .cpp em um .o
# -c: Compila, mas não liga (cria apenas o .o)
# $<: O nome do arquivo .cpp que dispara a regra (a dependência)
# $@: O nome do arquivo .o que será criado (o alvo)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regra para limpar os arquivos gerados (.o e o executável)
clean:
	rm -f $(TARGET) $(OBJECTS)