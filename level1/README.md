# Reverse Engineering a Password-Protected Program with GDB

## Overview
The goal is to reverse-engineer the password by examining how the program processes user input and performs string comparison.

## Steps

1. **Start GDB with the Binary:**
   ```sh
   gdb ./level1
   ```

2. **Enable Assembly Layout:**
   ```sh
   layout asm
   ```
   This allows you to view the real-time assembly code execution.

3. **Identify Key Functions:**
   - The program contains:
     - A `printf` (display prompt)
     - A `scanf` (user input)
     - A `strcmp` (password comparison)
     - Another `printf` (result message)
   - This structure indicates that the program expects a password and compares it using `strcmp`.

4. **Set a Breakpoint on strcmp:**
   ```sh
   break strcmp
   ```
   This will pause execution when `strcmp` is called, allowing inspection of its arguments.

5. **Run the Program:**
   ```sh
   run
   ```
   Enter any arbitrary password (e.g., `coucou`).

6. **Inspect Registers:**
   ```sh
   info registers
   ```
   - `$edx` and `$ecx` are used to store arguments for `strcmp`.
   - Other registers serve different roles (e.g., stack management, counters).

7. **Examine Memory Addresses:**
   ```sh
   x/s $ecx
   ```
   - Displays the user-inputted string (e.g., `coucou`).
   
   ```sh
   x/s $edx
   ```
   - Reveals the secret password stored in the program (e.g., `__stack_check`).

8. **Validate the Password:**
   - Restart the program and enter the extracted password (`__stack_check`).
   - The program should now validate successfully.

## Security Note
To prevent buffer overflows, source.c input should be limited to 100 characters. Exceeding this limit may lead to unintended behavior or vulnerabilities.
