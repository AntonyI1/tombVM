# tombVM

A C++ virtual machine sandbox for binary analysis & malware behavior inspection.  
Includes conditional branching support and a built-in test harness.

## Features (v0.2.0)
- Custom instruction set (MOV, ADD, CMP, JE, PRINT, JMP, HALT)
- 4 general-purpose 8-bit registers
- Instruction pointer and execution loop
- Conditional jumps (CMP + JE)
- Binary loader for `.vmbin` programs
- Automated test harness with expected output comparison
- Whitespace-tolerant test validation

## Instruction Set

| Opcode | Instruction        | Format           | Description                            |
|--------|--------------------|------------------|----------------------------------------|
| 0x01   | MOV R, value       | reg, val         | Set register to value                  |
| 0x02   | ADD R, value       | reg, val         | Add value to register                  |
| 0x03   | PRINT R            | reg              | Print value of register                |
| 0x04   | JMP addr           | addr             | Jump to instruction address            |
| 0x05   | CMP R, value       | reg, val         | Compare reg to value and set flag      |
| 0x06   | JE addr            | addr             | Jump if previous CMP matched           |
| 0xFF   | HALT               | —                | Terminate program                      |

## Test Harness

```bash
./tests/run_tests.sh
