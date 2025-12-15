from pwn import *

elf = ELF('./a.out')
rop = ROP(elf)
print(rop.gadgets)
