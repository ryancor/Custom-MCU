# Custom-MCU
1. brew install qemu

2. Download https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
	- Place folder in same directory as this project

3. ./install

## Debug
1. qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel main.bin
	- ./gcc-arm/bin/arm-none-eabi-gdb
		- (gdb) target remote localhost:1234
		- (gdb) file main.elf
		- (gdb) break main
		- (gdb) cont
