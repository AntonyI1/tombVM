# TombVM: A Simulated Virtual Machine for Binary Analysis and Malware Inspection

TombVM is a custom-built virtual machine (VM) simulator designed in C++ for safe, controlled execution and analysis of binary programs. It provides an emulated environment to execute custom bytecode, offering capabilities for low-level static and dynamic inspection, particularly useful for understanding program flow and behavior.

## Features (v0.3.0)
- Custom 8-bit Instruction Set: Compact, register-based instruction set.
- Register-Based Architecture: Four 8-bit general-purpose registers (R0-R3).
- Simulated Memory: Dedicated memory array (1024 int32_t elements) for STORE/LOAD operations.
- Internal Stack: LIFO stack for PUSH/POP operations.
- Instruction Pointer (IP): Manages program flow and jumps.
- Conditional Branching: CMP and JE instructions for decision-making.
- Binary Loader: Loads .vmbin files into simulated memory.
- Error Handling: Basic handling for unknown opcodes and stack underflow.

## Instruction Set

| Opcode | Instruction        | Format           | Description                            |
|--------|--------------------|------------------|----------------------------------------|
| 0x01   | MOV R, value       | reg, val         | Set register to value                  |
| 0x02   | ADD R, value       | reg, val         | Add value to register                  |
| 0x03   | PRINT R            | reg              | Print value of register                |
| 0x04   | JMP addr           | addr             | Jump to instruction address            |
| 0x05   | CMP R, value       | reg, val         | Compare reg to value and set flag      |
| 0x06   | JE addr            | addr             | Jump if previous CMP matched           |
| 0x07   | STORE R, addr      | reg, addr        | Store register value to memory         |
| 0x08   | LOAD R, addr       | reg, addr        | Load memory value into register        |
| 0x09   | PUSH R             | reg              | Push register onto internal stack      |
| 0x0A   | POP R 	            | reg              | Pop stack into register                |
| 0xFF   | HALT               | —                | Terminate program                      |


## Test Harness

```bash
./tests/run_tests.sh
