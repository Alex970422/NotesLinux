from pwn import *

p = process("./vuln")
p.recvuntil(b"Ton input :")



p.interactive

