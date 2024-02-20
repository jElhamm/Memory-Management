# Memory Management

   This repository contains implementations of various [Memory Management](https://en.wikipedia.org/wiki/Memory_management_(operating_systems)) techniques in [C++](https://cplusplus.com/) and [Python](https://www.python.org/) programming languages.



## Table of Contents

   - [Introduction](#introduction)
   - [Overview](#overview)
   - [Usage](#usage)
   - [Examples](#examples)



## Introduction

   In this repository, you will find implementations of the following memory management techniques:


   * Paging


   [Implementation with C++](Paging/Implementation%20with%20C%2B%2B)


   [Implementation with Python](Paging/Implementation%20with%20Python)


   * Best Fit Memory Allocator:


   [Implementation with C++](Best%20Fit%20Memory%20Allocator/Implementation%20with%20C%2B%2B)


   [Implementation with Python](Best%20Fit%20Memory%20Allocator/Implementation%20with%20Python)


   * First Fit Memory Allocator:


   [Implementation with C++](First%20Fit%20Memory%20Allocator/Implementation%20with%20C%2B%2B)


   [Implementation with Python](First%20Fit%20Memory%20Allocator/Implementation%20with%20Python)


   * Fixed Partitioning Technique:


   [Implementation with C++](Fixed%20Partitioning%20Technique/Implementation%20with%20C%2B%2B)


   [Implementation with Python](Fixed%20Partitioning%20Technique/Implementation%20with%20Python)


   * Variable Partitioning Technique:


   [Implementation with C++](Variable%20Partitioning%20Technique/Implementation%20with%20C%2B%2B)


   [Implementation with Python](Variable%20Partitioning%20Technique/Implementation%20with%20Python)


   * Worst Fit Memory Allocator:


   [Implementation with C++](Worst%20Fit%20Memory%20Allocator/Implementation%20with%20C%2B%2B)


   [Implementation with Python](Worst%20Fit%20Memory%20Allocator/Implementation%20with%20Python)



   Each technique is implemented in both C++ and Python.


## Overview

   * [*Paging*](Paging): Paging is a memory management scheme that allows the physical memory to be divided into fixed-size blocks called pages
   and manages them efficiently by mapping them to corresponding logical addresses.

   * [*Best Fit Memory Allocator*](Best%20Fit%20Memory%20Allocator): This technique allocates the smallest free block of memory that can satisfy a requested memory allocation,
   leading to efficient memory utilization by reducing fragmentation.

   * [*First Fit Memory Allocator*](First%20Fit%20Memory%20Allocator): It allocates the first free block of memory that is large enough to accommodate the requested memory size, which is a simple and fast method but can lead to fragmentation.

   * [*Worst Fit Memory Allocator*](Worst%20Fit%20Memory%20Allocator): This technique allocates the largest free block of memory available,
   which can result in more internal fragmentation but may be suitable for scenarios where large contiguous blocks are needed.

   * [*Fixed Partitioning Technique*](Fixed%20Partitioning%20Technique): In this technique, memory is divided into fixed-size partitions, and each partition can hold a single process.
   It is simple to implement but can lead to internal fragmentation.

   * [*Variable Partitioning Technique*](Variable%20Partitioning%20Technique): Unlike fixed partitioning, this technique allows memory partitions to vary in size based
   on the process requirements, reducing internal fragmentation.


   Each memory management technique implements a different strategy for managing memory allocation and efficiency.
   For detailed information and usage instructions, refer to the specific directories in the repository.


## Usage

   To use the implementations, follow these steps:

   1. Clone the repository to your local machine.
   2. Choose the desired memory management technique.
   3. Navigate to the corresponding directory.
   4. Follow the installation instructions provided in the README file of each technique.

## References
   
   * [Memory Management in Operating System](https://www.geeksforgeeks.org/memory-management-in-operating-system/)


   BOOK: 
   * Modern Operating Systems Book by Andrew Tanenbaum.
   * Operating System Concepts Book by Abraham Silberschatz.

## License

   This repository is licensed under the MIT License.
   See the [LICENSE](./LICENSE) file for more details.