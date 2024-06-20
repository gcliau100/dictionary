# Dictionary

Welcome to the `Dictionary` repository! This project contains a single C++ program, `dict.cpp`, which provides a command-line interface for interacting with a dictionary file. The dictionary file is expected to have entries formatted with words followed by their definitions.

## Table of Contents

- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Files Description](#files-description)

## Introduction

The `Dictionary` project includes a C++ program that allows users to:
1. Count the number of words in the dictionary.
2. Print words with a given prefix.
3. Replace occurrences of a specific word.
4. Run an external program with the dictionary file as an argument.

## Prerequisites

To compile and run the `dict.cpp` program, you will need:
- A C++ compiler (e.g., g++)
- A dictionary file formatted correctly (e.g., `dictionary.txt`)

## Installation

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/dictionary.git
    cd dictionary
    ```

2. Compile the `dict.cpp` file:
    ```bash
    g++ -o dict dict.cpp
    ```

## Usage

The program can be run with various command-line arguments to perform different actions:

1. **Count the number of words in the dictionary:**
    ```bash
    ./dict
    ```

2. **Specify a different dictionary file:**
    ```bash
    ./dict -d another_dictionary.txt
    ```

3. **Print words with a given prefix:**
    ```bash
    ./dict -p prefix -n number
    ```
    - `prefix`: The prefix to search for.
    - `number`: The maximum number of words to print.

4. **Replace occurrences of a word:**
    ```bash
    ./dict -s word -r replacement
    ```
    - `word`: The word to be replaced.
    - `replacement`: The word to replace it with.

5. **Run an external program with the dictionary file:**
    ```bash
    ./dict -v binary
    ```
    - `binary`: The external program to run with the dictionary file as an argument.

## Files Description

- **dict.cpp**: This is the main C++ source file that implements the dictionary functionalities. It includes features to count words, print words with a specific prefix, replace words, and run an external program with the dictionary file.
