CC=gcc

SRC_DIR=src
INC_DIR=include

BUILD_DIR=build
EXECUTABLE=out

BUILD_EXECUTABLE=$(BUILD_DIR)/$(EXECUTABLE)
SOURCES=$(wildcard $(SRC_DIR)/*/.c $(SRC_DIR)/*.c)
OBJECTS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

CFLAGS=-I$(INC_DIR) -Wall

all: $(BUILD_EXECUTABLE)
	@echo "Compilation réussie."

$(BUILD_EXECUTABLE): $(OBJECTS)
	@echo "Création de l'exécutable: $@"
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "$@: OK\n---"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilation du fichier objet: $@"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$@: OK\n---"

run: $(BUILD_EXECUTABLE)
	@echo "Lancement de l'éxécutable"
	@./$(BUILD_EXECUTABLE)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Nettoyage terminé."

.PHONY: clean run