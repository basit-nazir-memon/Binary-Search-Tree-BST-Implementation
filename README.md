# Binary Search Tree Program

This is a C++ program that implements a Binary Search Tree (BST) and stores the BST data in a text file. The program allows you to perform basic operations on the BST, such as insertion, deletion, searching, and printing.

## Program Structure

The program consists of the following files:

1. `header.h`: This header file contains the class and function declarations for the BST program.
2. `declaration.cpp`: This file contains the function definitions for the declared functions in `header.h`.
3. `source.cpp`: This file contains the `main()` function and provides a simple user interface for interacting with the BST.
4. `text.txt`: This text file is used to store the BST data.

## Compilation

To compile the program, follow these steps:

1. Ensure that you have a C++ compiler installed on your system (e.g., g++ for Linux or MinGW for Windows).
2. Open a terminal or command prompt and navigate to the directory containing the program files.
3. Run the following command to compile the program:

```shell
g++ declaration.cpp source.cpp -o bst_program
```

This command compiles both `declaration.cpp` and `source.cpp` files and generates an executable named `bst_program`.

## Usage

To run the program, execute the following command in the terminal or command prompt:

```shell
./bst_program
```

The program will display a menu of options that you can choose from. Use the number keys to select an option and press Enter to execute it.

## BST Data Storage

The program stores the BST data in a text file named `text.txt`. This file is automatically created and updated whenever the program performs any modification operations, such as insertion or deletion.

The text file follows a pre-order traversal format, where each node is represented by a single line containing its value. The left subtree is listed before the right subtree.

Here is an example of how the `text.txt` file may look:

```
10
2
35
-35
5
21
45
-897564231
-897564231
-897564231
7
-897564231
34
```

## Contributing

If you would like to contribute to this program, please follow these steps:

1. Fork the repository.
2. Create a new branch for your changes.
3. Make the necessary modifications and improvements.
4. Test your changes thoroughly.
5. Commit and push your changes to your forked repository.
6. Open a pull request, describing the changes you have made.

Your contributions are greatly appreciated!

## License

This program is licensed under the [MIT License](LICENSE). Feel free to modify and distribute it according to the terms of the license.

## Contact

If you have any questions or suggestions regarding this program, please contact [basitnazir585@gmail.com](mailto:basitnazir585@gmail.com).

Thank you for using our BST program!
