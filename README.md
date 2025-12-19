# Encrypted-multi-user-shell
# Encrypted Multi-User Shell 🔐🖥️

## Overview
This project implements a **secure, encrypted multi-user shell** as part of an Operating Systems course project.  
The shell supports **multiple users**, **command execution**, and **encrypted command history storage**, demonstrating core OS and security concepts.

The system focuses on secure user interaction, access control, and protection of sensitive shell data.

---

## Key Features
- Multi-user shell environment
- User authentication using a local user database
- Encrypted command history storage
- Secure handling of shell commands
- System call usage and testing
- Modular design for security-related components

---

## Core Concepts Demonstrated
- Operating system fundamentals
- Process creation and execution
- System calls
- File handling and permissions
- Basic encryption and decryption
- User authentication and access control

---

## Project Structure
encrypted-multi-user-shell/
├── secure_shell # Main shell executable
├── users.db # User credential storage
├── command_history.enc # Encrypted command history
├── decrypt_history.c # Command history decryption logic
├── test_systemcalls.c # System call testing
├── auth_test # Authentication testing
└── README.md

---


---

## How It Works
1. Users authenticate using stored credentials
2. Authenticated users access the shell
3. Commands entered by users are executed securely
4. Command history is encrypted before being stored
5. Decryption utilities allow controlled access to history data

---

## Compilation & Execution
Compile the required C files using `gcc`:

```bash
gcc secure_shell.c -o secure_shell
gcc decrypt_history.c -o decrypt_history
gcc test_systemcalls.c -o test_systemcalls

Run the shell:
./secure_shell
