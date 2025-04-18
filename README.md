# 🧠 Minimal x86 Kernel in C

## 🚀 Introduction

Have you ever wondered *how an x86 machine boots*? It's actually pretty straightforward — and now you can see it for yourself.

This project is a **minimal kernel written from scratch in C**, showing the bare essentials of how to boot, clear the screen, and print text — all without any OS.

---

## 📦 What This Kernel Does

- 🖥 Prints a message directly to the screen (via VGA text buffer).
- ⚙️ Boots on real hardware using `GRUB2` (via Multiboot).
- 🔧 Runs perfectly inside QEMU (and probably other VMs too).
- 💡 Clean, beginner-friendly code for learning low-level OS dev.

---

## 🛠 How to Build & Run
- Create object files from `kernel.asm` and `kernel.c`:
```bash
nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c kernel.c -o kc.o
```

- Link the object files:
```bash
ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
```

- Edit the grub.cfg file if you want to use one:
```bash
set timeout=15
set default=0

menuentry "Kernel 420" {
    multiboot /boot/kernel ro
    boot
}
```

- If you want to create the ISO:
```bash
grub-mkrescue -o kernel.iso iso/
```
Then to boot using qemu you can either :
1- ```bash
qemu-system-i386 -cdrom kernel.iso
``` if you want to use the iso.
2- ```bash
qemu-system-i386 -kenel iso/boot/kernel
```
if you want to use the binary directly.

### 🔧 Requirements (on Arch Linux)
- An x86 computer.
- ```bash
sudo pacman -S qemu-full grub xorriso nasm ld gcc
```

