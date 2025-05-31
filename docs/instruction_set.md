# Instruction Set (TombVM v0.1)

| Opcode | Instruction       | Format                   | Description                       |
|--------|-------------------|--------------------------|-----------------------------------|
| 0x01   | MOV R, val        | reg, val                 | Set register to value             |
| 0x02   | ADD R, val        | reg, val                 | Add value to register             |
| 0x03   | PRINT R           | reg                      | Print register value              |
| 0x04   | JMP addr          | addr                     | Jump to address                   |
| 0x05   | CMP R, val        | reg, val                 | Compare reg with value            |
| 0x06   | JE addr           | addr                     | Jump if equal (after CMP)         |
| 0xFF   | HALT              |                          | Stop program                      |

