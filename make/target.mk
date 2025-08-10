include make/common.mk

PROJECT_BINARY := $(BUILD_DIR)/main/main

.PHONY: run
run: $(PROJECT_BINARY)
	@echo "Running $(PROJECT_BINARY)..."
	"$(PROJECT_BINARY)"

.PHONY: debug
debug: $(PROJECT_BINARY)
	@echo "Debugging $(PROJECT_BINARY)..."
	gdb "$(PROJECT_BINARY)"

.PHONY: valgrind
valgrind: $(PROJECT_BINARY)
	valgrind --leak-check=full "$(PROJECT_BINARY)"

.PHONY: test
test: $(PROJECT_BINARY)
	ctest --test-dir "$(BUILD_DIR)" --output-on-failure
