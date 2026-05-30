CC = gcc
NASM = nasm
AR = ar
ARFLAGS = rcs

# По умолчанию (если написать просто `make`), собираем 64 бита
all: 64

# Таргет для 64-битной сборки
64:
	$(NASM) -f elf64 -d BITS=64 recv.asm -o recv64.o
	$(CC) -c main.c -I./include -o cloudq64.o
	$(AR) $(ARFLAGS) libcloudq64.a cloudq64.o recv64.o
	@echo "--- 64-битная libcloudq64.a успешно собрана! ---"

# Таргет для 32-битной сборки (требует gcc-multilib)
32:
	$(NASM) -f elf32 -d BITS=32 recv.asm -o recv32.o
	$(CC) -m32 -c main.c -I./include -o cloudq32.o
	$(AR) $(ARFLAGS) libcloudq32.a cloudq32.o recv32.o
	@echo "--- 32-битная libcloudq32.a успешно собрана! ---"

# Очистка всего скомпилированного добра
clean:
	rm -f *.o *.a
