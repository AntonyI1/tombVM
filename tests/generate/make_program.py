import os

REGISTERS = {
    "R0": 0x00,
    "R1": 0x01,
    "R2": 0x02,
    "R3": 0x03,
}


# All test programs mapped by filename (no extension)
TEST_PROGRAMS = {
    "basic_mov_add": [
        0x01, REGISTERS["R0"], 0x05,  # MOV R0, 5
        0x02, REGISTERS["R0"], 0x03,  # ADD R0, 3
        0x03, REGISTERS["R0"],        # PRINT R0
        0xFF
        # Expected: 8
    ],
    "basic_add_zero": [
        0x01, REGISTERS["R0"], 0x07,  # MOV R0, 7
        0x02, REGISTERS["R0"], 0x00,  # ADD R0, 0
        0x03, REGISTERS["R0"],        # PRINT R0
        0xFF
        # Expected: 7
    ],
    "jump_forward": [
        0x01, REGISTERS["R0"], 0x01,  # MOV R0, 1
        0x04, 0x08,                   # JMP to byte 8
        0x01, REGISTERS["R0"], 0xFF,  # MOV R0, 255 (skipped)
        0x03, REGISTERS["R0"],        # PRINT R0
        0xFF
        # Expected: 1
    ],
    "jump_nowhere": [
        0x04, 0xFF,                   # JMP to invalid address
        0x01, REGISTERS["R0"], 0xAA,  # MOV R0, 170 (skipped)
        0x03, REGISTERS["R0"],
        0xFF
        # Expected: [undefined / crash / edge behavior]
    ],
    "cmp_je_true": [
        0x01, REGISTERS["R0"], 0x05,  # MOV R0, 5
        0x05, REGISTERS["R0"], 0x05,  # CMP R0, 5
        0x06, 0x0E,                   # JE to byte 14
        0x01, REGISTERS["R0"], 0x00,  # MOV R0, 0 (skipped)
        0x03, REGISTERS["R0"],        # PRINT R0 (skipped)
        0xFF,
        0x03, REGISTERS["R0"],        # PRINT R0 (actual)
        0xFF
        # Expected: 5
    ],
    "cmp_je_false": [
        0x01, REGISTERS["R0"], 0x04,  # MOV R0, 4
        0x05, REGISTERS["R0"], 0x05,  # CMP R0, 5
        0x06, 0x0D,                   # JE to byte 13 (skipped)
        0x01, REGISTERS["R0"], 0x99,  # MOV R0, 153
        0x03, REGISTERS["R0"],        # PRINT R0
        0xFF,
        0x03, REGISTERS["R0"],        # PRINT R0 (skipped)
        0xFF
        # Expected: 153
    ],
    "basic_push_pop": [
        0x01, REGISTERS["R3"], 0x2A,  # MOV R3, 42
        0x09, REGISTERS["R3"],        # PUSH R3
        0x01, REGISTERS["R3"], 0x00,  # MOV R3, 0
        0x0A, REGISTERS["R3"],        # POP R3
        0x03, REGISTERS["R3"],        # PRINT R3
        0xFF
        # Expected: 42
    ]
}

def write_bin(name, bytes_list):
    out_path = f"tests/programs/{name}.vmbin"
    os.makedirs(os.path.dirname(out_path), exist_ok=True)
    with open(out_path, "wb") as f:
        f.write(bytes(bytes_list))
    print(f"Wrote {out_path}")

if __name__ == "__main__":
    for name, program in TEST_PROGRAMS.items():
        write_bin(name, program)
