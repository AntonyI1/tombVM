# Instruction Set (TombVM v0.3.0)

| Opcode | Instruction       | Format                   | Description                       |
|--------|-------------------|--------------------------|-----------------------------------|
| 0x01   | MOV R, val        | reg, val                 | Set register to value             |
| 0x02   | ADD R, val        | reg, val                 | Add value to register             |
| 0x03   | PRINT R           | reg                      | Print register value              |
| 0x04   | JMP addr          | addr                     | Jump to address                   |
| 0x05   | CMP R, val        | reg, val                 | Compare reg with value            |
| 0x06   | JE addr           | addr                     | Jump if equal (after CMP)         |
| 0x07   | STORE R, addr     | reg, addr                | Store register value to memory    |
| 0x08   | LOAD R, addr      | reg, addr                | Load memory value into register   |
| 0x09   | PUSH R            | reg                      | Push register onto internal stack |
| 0x0A   | POP R             | reg                      | Pop stack into register           |
| 0xFF   | HALT              |                          | Stop program                      |
