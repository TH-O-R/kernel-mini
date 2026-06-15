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
- Building is easy and requires typing only one command:
```bash
make
```
This will create object files from `kernel.asm` and `kernel.c` then link them to get the raw kernel binary.

- You can also use this command after making the kernel binary to get a bootable ISO:
```bash
make iso
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

Then to boot using qemu you can either :

1- Use the ISO:
```bash
qemu-system-i386 -cdrom kernel.iso
```

2- Use the binary directly:
```bash
qemu-system-i386 -kernel iso/boot/kernel
```

### 🔧 Requirements (on Arch Linux)
- An x86 capable computer.
- Packages:
```bash
sudo pacman -S qemu-full grub xorriso nasm ld gcc
```
>**note**: you can also use `qemu-base` instead of `qemu-full` but you will need a VNC viewer of some kind to see the results.
- Packages (alt):
```bash
sudo pacman -S qemu-base grub xorriso nasm ld gcc tigervnc
```
