# Dirty RAGS
## (Quick and Dirty Random Array Generator and Sorter)
### Created by Corey Burdick (for fun)

Dirty Rags is a command line utility written in C++ that randomly generates an array with 5 elements by default, and prints those elements
to the terminal. Various options are able to be used to change what is done with this generated array. 

## How to build

### Step 1. Download Source

You can either download the source directly from github using the download button, but it is recommended that you use the following command.

```
git clone https://github.com/Corey-Burdick/Dirty-RAGS.git
```
### Step 2. Build From Source

Once you have downloaded the source, you can use the following commands in the terminal to build.

```
cd Dirty-RAGS

mkdir build

cd build

cmake ..

make
```

## Usage

Dirty Rags can be run after being compiled by using "./dirtyrags" in the command line, followed by any options.

Dirty Rags currently supports two soriting algorithms: Bubble Sort, and Merge Sort (recommended, especially for large arrays).

You can choose which sorting algorithm to do by adding "-b" for bubble sort, or "-m" for merge sort.

If you use both options, Dirty Rags will use whichever is last in the command.

You can also decide the number of elements in the generated array with "-c" followed by the desired number of elements (default 5).

You may also pass the argument "-t", which will display the time it takes for Dirty Rags to generate and sort the array in milliseconds.

By default, rags only shows the first ten elements of a sorted or generated array. You can show the whole array with "-v", enabling verbose mode.

If you wish to save a generated array, you can use the option "-s" to do so. This will output the generated array to "output.txt" in your working directory.

You can see a list of all options with "-h" or "--help".

**Examples:**

```
./dirtyrags -c 10 -b -m

(This would result in using the merge sort algorithm to sort 10 elements).

./dirtyrags -c 10 -b -t

(This would result in using the bubble sort algorithm to sort 10 elements, and show the time it took to generate the initial array, and sort it).
```

## Notice
This software is developed and maintained by a moron, for their own entertainment. If you find a bug, memory leak, or anything else, please contact said
moron at coreyburdickwork@gmail.com

If you want to see an error message that cannot appear during normal execution, short of a bit-flip on non-ecc memory DIMMS, you can pass the option "--silly".
