ASM = kernel.asm
C = kernel.c
LINKER = link.ld

ASM_OBJ = kasm.o
C_OBJ = kc.o

KERNEL = iso/boot/kernel
ISO = kernel.iso

all: $(KERNEL)

$(ASM_OBJ): $(ASM)
	nasm -f elf32 $(ASM) -o $(ASM_OBJ)

$(C_OBJ): $(C)
	gcc -m32 -c $(C) -o $(C_OBJ)

$(KERNEL): $(ASM_OBJ) $(C_OBJ) $(LINKER)
	ld -m elf_i386 -T link.ld -o $(KERNEL) $(ASM_OBJ) $(C_OBJ)

iso: $(ISO)

$(ISO): $(KERNEL)
	grub-mkrescue -o $(ISO) iso/

clean:
	rm -f $(ASM_OBJ) $(C_OBJ) $(KERNEL) $(ISO)

.PHONY: all iso clean
