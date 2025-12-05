# Makefile para o projeto Lab04 - Buscas Heurísticas

# Define o nome do arquivo executável
TARGET = agente_ia

# Diretórios de cabeçalhos (-I flag)
# Permite que os includes usem o caminho da pasta
INCLUDES = -I.  -IProblema -IBuscaHeuristica

# Flags do compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Arquivos fonte (implementações C++ que geram código objeto)
SOURCES = main.cpp \
          BuscaHeuristica/BuscasHeuristicas.cpp

# Arquivos objeto (gerados a partir dos SOURCES)
# Troca a extensão .cpp por .o
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão: compila os objetos e depois liga (link) para criar o executável
all: $(TARGET)

$(TARGET): $(OBJECTS)
	# Liga (linka) todos os arquivos objeto em um único executável
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET)

# Regra genérica para compilar qualquer .cpp em um .o
# -c: Compila, mas não liga (cria apenas o .o)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regra para limpar os arquivos gerados (.o e o executável)
clean:
	rm -f $(TARGET) $(OBJECTS)