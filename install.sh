# Compile
echo "Starting compilation..."

./gcc-arm/bin/arm-none-eabi-as startup_chain/startup.s -o startup.o
./gcc-arm/bin/arm-none-eabi-gcc -I $PWD/gcc-arm/arm-none-eabi/include --specs=rdimon.specs -Wl,--start-group -lgcc -lc -lm -lrdimon -Wl,--end-group -c main.c -o main.o
./gcc-arm/bin/arm-none-eabi-gcc -I $PWD/gcc-arm/arm-none-eabi/include  -c -o syscalls.o syscalls.c
./gcc-arm/bin/arm-none-eabi-gcc -nostdlib -T linkers/link.ld main.o startup.o syscalls.o $PWD/gcc-arm/arm-none-eabi/lib/libc.a -o main.elf
# Convert ARM executable to a data file
./gcc-arm/bin/arm-none-eabi-objcopy -O binary main.elf main.bin

echo "Compilation finished!"

echo "Cleanup time..."
rm -rf *.o

# Run
echo "Emulating.."
echo "Use Ctrl-A + C + ENTER for qemu console"
echo ""
qemu-system-arm -M versatilepb -m 128M -nographic -serial mon:stdio -append 'console=ttyS0' -kernel main.bin
# -M overo -m 128M -nographic -device usb-mouse -device usb-kbd
