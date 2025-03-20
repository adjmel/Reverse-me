# Reverse Engineering a Password-Protected Program with Ghidra

## Overview
This guide details how to analyze a more complex password-protected program using **Ghidra** via the online tool [Dogbolt](https://dogbolt.org). Instead of using GDB, we leverage Ghidra’s decompiled C code to understand the program logic and retrieve the correct password.

## Steps

1. **Upload the Binary to Dogbolt**
   - Navigate to [Dogbolt](https://dogbolt.org/?id=0f4f5fa4-6d58-4c8a-8f18-6f960baf701b#Ghidra=332).
   - Upload `./level2` and select Ghidra as the decompiler.

2. **Analyze the Decompiled C Code**
   - The decompiled code provides a high-level understanding of the program’s functionality.
   - The program processes a user-inputted string and applies several checks before validation.

3. **Understanding the Password Logic**
   - The input must **start with "00"**; otherwise, the program returns "nope" immediately.
   - The program then processes the remaining part of the input in groups of **three-digit ASCII codes**.
   - These three-digit codes are converted to characters using `atoi()`.
   - The resulting string must match **"delabere"**.

4. **Constructing the Correct Password**
   - ASCII values of "delabere" (https://onlinestringtools.com/convert-string-to-ascii):
     ```
     d = 100, e = 101, l = 108, a = 97, b = 98, e = 101, r = 114, e = 101
     ```
   - Concatenating these values gives:
     ```
     1001011089798101114101
     ```
   - Adding the required "00" prefix:
     ```
     001001011089798101114101
     ```
   - Adjusting for **grouped three-digit parsing**:
     - A separator (`,`) is needed for numbers like `97` and `98` to prevent them from merging incorrectly (e.g., `978` instead of `97,98`).
     ```
     0010110897,98,101114101
     ```
   - This ensures the program reads each segment correctly and reconstructs "delabere".

## Final Password
```
0010110897,98,101114101
```
Enter this string when prompted by the program to pass the validation.

## Notes
- The separator is necessary because the `atoi()` function reads three-digit groups and might otherwise merge unintended values.
- The logic behind this separator requirement isn’t fully clear but ensures correct parsing of "delabere".

## Disclaimer
This guide is for educational purposes only. Unauthorized reverse engineering of software without permission is illegal and unethical.

