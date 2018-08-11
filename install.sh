# Compile
echo "Starting compilation of ARM"

./gcc-arm/bin/arm-none-eabi-as startup.s -o startup.o
./gcc-arm/bin/arm-none-eabi-gcc --specs=rdimon.specs   -Wl,--start-group -lgcc -lc -lm -lrdimon -Wl,--end-group -c main.c -o main.o
./gcc-arm/bin/arm-none-eabi-ld -T link.ld main.o startup.o -o main.elf
./gcc-arm/bin/arm-none-eabi-objcopy -O binary main.elf main.bin

echo "Compilation finished!"

echo "Cleanup"
rm -rf *.o && rm -rf main.elf

# Run
echo "Emulating.."
qemu-system-arm -M versatilepb -m 128M -nographic -kernel main.bin
