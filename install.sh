# Compile
echo "Starting compilation..."

./gcc-arm/bin/arm-none-eabi-as startup_chain/startup.s -o startup.o
./gcc-arm/bin/arm-none-eabi-gcc --specs=rdimon.specs   -Wl,--start-group -lgcc -lc -lm -lrdimon -Wl,--end-group -c main.c -o main.o
./gcc-arm/bin/arm-none-eabi-ld -T linkers/link.ld main.o startup.o -o main.elf
# Convert ARM executable to a data file
./gcc-arm/bin/arm-none-eabi-objcopy -O binary main.elf main.bin

echo "Compilation finished!"

echo "Cleanup time..."
rm -rf *.o

# Run
echo "Emulating.."
echo ""
qemu-system-arm -M versatilepb -m 128M -nographic -kernel main.bin
