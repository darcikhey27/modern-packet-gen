BUILD_DATE      := $(shell date +%c)

CC              = gcc

FLAGS_VERSION = -DVERSION=\""$(VERSION)"\" -DBUILD_DATE=\""$(BUILD_DATE)\""
FLAGS_WARN    = -Wall $(WERROR)
FLAGS_DIALECT = -std=c99
CFLAGS        = $(FLAGS_WARN) $(FLAGS_VERSION) -g3 -O3

SRC_DIR        = src
OBJ_DIR        = obj

modernpgC := $(addprefix $(SRC_DIR)/, main.c sys.c)
modernpgH := $(addprefix $(SRC_DIR)/, common.h main.h pkt_conf.h sys.h types.h)
modernpgO := $(addprefix $(OBJ_DIR)/, modern-pkt-gen)


$(OBJ_DIR)/modern-pkt-gen: $(modernpgC) $(modernpgH) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(modernpgC) -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)


