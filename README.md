# Custom-MCU
1. brew install qemu

2. Download https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
	- Place folder in same directory as this project

3. ./install

## Debug (Reverse firmware to show LED_On)
1. qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel main.bin
	- ./gcc-arm/bin/arm-none-eabi-gdb
		- (gdb) target remote localhost:1234
		- (gdb) file main.elf
		- (gdb) break main
		- (gdb) cont

2. Using Objdump && Radare2
	- ```
	➜  ./gcc-arm/bin/arm-none-eabi-objdump -s -j .rodata main.elf

	main.elf:     file format elf32-littlearm

	Contents of section .rodata:
 	 1031c 00101f10 4c50435f 4750494f 312d3e44  ....LPC_GPIO1->D
 	 1032c 41544120 3d200000 0a000000 31000000  ATA = ......1...
 	 1033c 4c454420 4f6e0a00 4c454420 4f66660a  LED On..LED Off.
 	 1034c 00
	````
	- r2 -aarm -b16 -d gdb://localhost:1234
		- pd 25 @ 0x1031c
			```
			0x00010328      312d           cmp r5, 0x31                ; '1'
			```
			- This is the value we have to change in order for the LED to do what we
			want
		- `dr r5=0x01` won't work
		- ```
		[0x0001016c]> s 0x00010328
		[0x00010328]> wa cmp r5, 0x30
		Written 2 bytes (cmp r5, 0x30) = wx 302d
		```
			- In gdb, to edit a register, it would be
			 	- (gdb) set $r3 = 0x0
		- If you run `pd 25 @ 0x1031c` again, you'll see its compare'd to '0' now.
		- Hit `dc`
			- We should see `LED On` in the debug terminal
