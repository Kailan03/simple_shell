#!/bin/bash

# Test 1: Run basic commands
echo "ls" | ./shell

# Test 2: Run a command with arguments
echo "/bin/ls -l" | ./shell

# Test 3: Run an invalid command
echo "invalid_command" | ./shell

# Test 4: Run the shell interactively and exit
echo -e "exit\n" | ./shell

# Test 5: Test interactive input with arrow keys
echo -e "^[[D^[[D^[[D\n" | ./shell

# Test 6: Test interactive input with arrow keys
echo -e "^[[C^[[C^[[C^[[C\n" | ./shell

# Test 7: Test interrupting the shell
echo -e "^C\n" | ./shell

# Test command with arguments
echo "Test 2: Command with Arguments"
./shell <<< "/bin/ls -l"
echo "-------------------------"

# Test built-in command (cd)
echo "Test 3: Built-in Command (cd)"
./shell <<< "cd /tmp && pwd"
echo "-------------------------"

# Test non-existent command
echo "Test 4: Non-existent Command"
./shell <<< "nonexistent_command"
echo "-------------------------"

# Test piping
echo "Test 5: Piping"
./shell <<< "ls | grep shell"
echo "-------------------------"

# Test redirection
echo "Test 6: Redirection"
./shell <<< "ls > output.txt && cat output.txt"
rm output.txt
echo "-------------------------"

# Test background processes
echo "Test 7: Background Processes"
./shell <<< "sleep 5 &"
echo "-------------------------"

# Test environment variables
echo "Test 8: Environment Variables"
./shell <<< "export TEST_VAR=hello && echo \$TEST_VAR"
echo "-------------------------"

# Test exit command
echo "Test 9: Exit Command"
./shell <<< "exit"
echo "-------------------------"

# Test interactive mode
echo "Test 10: Interactive Mode"
./shell
echo "-------------------------"

# Test Ctrl+C and signals
echo "Test 11: Ctrl+C and Signals"
./shell <<< "sleep 10"
# During the sleep process, press Ctrl+C and observe the shell behavior
echo "-------------------------"

# Test edge cases
echo "Test 12: Edge Cases"
./shell <<< ""  # Empty input
./shell <<< "   "  # Input with spaces
echo "-------------------------"

echo "Test Suite Completed"
