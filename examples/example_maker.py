program = [
    0x01, 0x00, 0x05,   # MOV R0, 5
    0x02, 0x00, 0x02,   # ADD R0, 2
    0x03, 0x00,         # PRINT R0
    0xFF                # HALT
]

with open("test1.vmbin", "wb") as f:
    f.write(bytes(program))
    