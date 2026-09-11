
CC := $(shell which clang 2>/dev/null || which gcc 2>/dev/null || echo "HATA")

CFLAGS = -Wall -Wextra -Isrc
SRC = src/codes/notefile.c
TARGET = notefile


ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    RM = del /Q
else
    RM = rm -f
endif

all: check_cc $(TARGET)


check_cc:
	@if [ "$(CC)" = "HATA" ]; then \
		echo "Gcc ya da clang gibi birşey yok"; \
		echo "Lutfen C derleyicisi yükleyin."; \
		exit 1; \
	fi

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	$(RM) $(TARGET)

