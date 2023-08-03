# Binary Trees Tasks

This repository contains C programs for various tasks related to binary trees. Each task is implemented as a separate C file, and there is a corresponding main program to test the functionality of each task. Below is a description of each task and how to compile and run the programs.

## Task 0: New Node

Implement a function that creates a new binary tree node.

### Prototype

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
./0-node
```

## Task 1: Insert Left

Implement a function that inserts a new node as the left child of a given node.

### Prototype

```c
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
./1-left
```

## Task 2: Insert Right

Implement a function that inserts a new node as the right child of a given node.

### Prototype

```c
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right
./2-right
```

## Task 3: Delete

Implement a function that deletes an entire binary tree.

### Prototype

```c
void binary_tree_delete(binary_tree_t *tree);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
valgrind ./3-del
```

## Task 4: Is Leaf

Implement a function that checks if a given node is a leaf.

### Prototype

```c
int binary_tree_is_leaf(const binary_tree_t *node);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-main.c 4-binary_tree_is_leaf.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf
./4-leaf
```

## Task 5: Is Root

Implement a function that checks if a given node is a root.

### Prototype

```c
int binary_tree_is_root(const binary_tree_t *node);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-main.c 5-binary_tree_is_root.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root
./5-root
```

## Task 6: Pre-order Traversal

Implement a function that traverses a binary tree using pre-order traversal.

### Prototype

```c
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre
./6-pre
```

## Task 7: In-order Traversal

Implement a function that traverses a binary tree using in-order traversal.

### Prototype

```c
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in
./7-in
```

## Task 8: Post-order Traversal

Implement a function that traverses a binary tree using post-order traversal.

### Prototype

```c
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post
./8-post
```

## Task 9: Height

Implement a function that measures the height of a binary tree.

### Prototype

```c
size_t binary_tree_height(const binary_tree_t *tree);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height
./9-height
```

## Task 10: Depth

Implement a function that measures the depth of a node in a binary tree.

### Prototype

```c
size_t binary_tree_depth(const binary_tree_t *tree);
```

### Compilation and Execution

```shell
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth
./10-depth
```

Each task is implemented in a separate file and can be compiled and executed independently. The `binary_tree_print.c` file provides a utility function to print the binary tree structure for better visualization. Make sure to compile the necessary files for each task before running the test programs.
