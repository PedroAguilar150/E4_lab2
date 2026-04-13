	# Este archivo contiene un conjunto de instrucciones que le dicen al compilador qué archivos
	# debe procesar, qué librerías incluir y cómo generar el ejecutable final.
	# En lugar de escribir comandos en el terminal cada vez que quiera compilar los cambios
	# simplemente escribes make y el sistema se encarga de compilar solo lo que cambió,
	#ahorrando mucho tiempo en proyectos complejos.

	# en que carpeta busca el codigo fuente
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./build/obj
BIN_DIR = ./build/bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, \
             $(OBJ_DIR)/%.o,$(SRC_FILES))

# cambio el codigo desde aqui para que genere el ejecutable en la carpeta build/bin y los archivos objeto en build/obj
all: setup $(BIN_DIR)/programa			
setup:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/programa: $(OBJ_FILES)
	gcc -o $@ $(OBJ_FILES)
# hasta aqui 
info:
	@echo "Source files: $(SRC_FILES)"
	@echo "Object files: $(OBJ_FILES)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@ -I $(INC_DIR) -Wall -Wextra -Werror -Wpedantic --std=c11
doc: 
	doxygen doxyfile