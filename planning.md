# overview
  - **objective**: create a terminal application in cpp, sloc (source lines of code), that counts lines of code,
    comments, doxygen and blank lines in c/cpp, generating a formatted table.
  - **examples given**
```
$ ./sloc src/main.cpp
Files processed: 1
------------------------------------------------------------------------------------------------------------------
Filename            Language      Comments        Dox Comments    Blank           Code            # of lines
------------------------------------------------------------------------------------------------------------------
src/main.cpp        C++           1 (3.6%)        9 (32.1%)       3 (10.7%)       15 (53.6%)      28
------------------------------------------------------------------------------------------------------------------
```
  - **skills used/to be refined**
    - oop/classes
    - strings and stream manipulation
    - file streams
    - processing and parsing of cli arguments
    - convenient use of data structures (lists and dictionaries)
  - **input**
    - c/cpp source files and/or directories containing c/cpp source files
    - cli options
      - sorting order
      - recursion on directories
    - in detail:
      - -s f: sort data in ascending order by file name.
      - -s t: sort data in ascending order by file type.
      - -s c: sort data in ascending order by number of comment lines.
      - -s d: sort data in ascending order by number of doxygen comment lines.
      - -s b: sort data in ascending order by number of blank lines.
      - -s s: sort data in ascending order by number of sloc lines.
      - -s a: sort data in ascending order by number of all lines.
    - for descending order, uses -S
  - **interface**
    - no arguments provided, `--help` or `-h`: display *manual page*
```
$ ./build/sloc -h
Welcome to sloc cpp, version 1.0, (c) DIMAp/UFRN.

NAME
  sloc - single line of code counter.

SYNOPSIS
  sloc [-h | --help] [-r] [(-s | -S) f|t|c|b|s|a] <file | directory>

EXAMPLES
  sloc main.cpp sloc.cpp
     Counts loc, comments, blanks of the source files 'main.cpp' and 'sloc.cpp'

  sloc source
     Counts loc, comments, blanks of all C/C++ source files inside 'source'

  sloc -r -s c source
     Counts loc, comments, blanks of all C/C++ source files recursively inside 'source'
     and sort the result in ascending order by the number of comment lines.

DESCRIPTION
  Sloc counts the individual number **lines of code** (LOC), comments, and blank
  lines found in a list of files or directories passed as the last argument
  (after options).
  After the counting process is concluded the program prints out to the standard
  output a table summarizing the information gathered, by each source file and/or
  directory provided.
  It is possible to inform which fields sloc should use to sort the data by, as
  well as if the data should be presented in ascending/descending numeric order.

OPTIONS:
  -h/--help
            Display this information.

  -r
            Look for files recursively in the directory provided.

  -s f|t|c|d|b|s|a
            Sort table in ASCENDING order by (f)ilename, (t) filetype,
            (c)omments, (d)oc comments, (b)lank lines, (s)loc, or (a)ll.
            Default is to show files in order of appearance.

  -S f|t|c|d|b|s|a
            Sort table in DESCENDING order by (f)ilename, (t) filetype,
            (c)omments, (d)oc comments, (b)lank lines, (s)loc, or (a)ll.
            Default is to show files in order of appearance.
```
  - **execution**
    - valid file extensions:
      - .cpp
      - .hpp
      - .c
      - .h
    - if directory, access all supported files inside source directory
    - thus, end up with **list of input source files**, whatever the type of input provided
    - in summary:
      1. Read the input source and create a list of valid source files to process;
      2. For each file in the list, count the individual lines of code, blank lines, regular comments and doxygen comments, store this information in a convenient data structure (which one? 🤔), and;
      3. Display the result of the counting into a single table, with information associated with each individual file.
  - **output**
    - table with counting information for each category of line, per source file
    - if >1, present summation of counts on last line of table
    - show **number of lines and percentage**
    - fields are left aligned and all columns but the first have fixed width
      - first must grow to **accomodate largest path+file name in list**
    - do **NOT** truncate file path
    - error outputs:
      1. non-existing source file or directory
        `Sorry, unable to read "file.cpp".`
        `Sorry, unable to read "source".`
      2. existing file, but not supported
        `Sorry, ".tex" files are not supported at this time.`
      3. existing directory, but doesn't contain supported files
        `Sorry, unable to find any supported source file inside directory "src".`
    - other possible error treatments:
      - invalid sorting field
      - invalid option
      - option that requires arg without the arg
      - etc.
    - example for 3 source files:
```
$ ./sloc src/core
Files processed: 3
------------------------------------------------------------------------------------------------------------------
Filename            Language      Comments        Doc Comments    Blank           Code            # of lines
------------------------------------------------------------------------------------------------------------------
core/main_.cpp      C++           11 (16.4%)      32 (47.8%)      7 (10.4%)       17 (25.4%)      64
core/cowsay.h       C/C++ header  29 (13.9%)      64 (30.6%)      20 (9.6%)       96 (45.9%)      166
core/cowsay.cpp     C++           142 (27.3%)     23 (4.4%)       26 (5.0%)       330 (63.3%)     465
------------------------------------------------------------------------------------------------------------------
SUM                               182             119             53              443             695
------------------------------------------------------------------------------------------------------------------
```
# requirements
  - valid inputs
  - cli flags
  - required interface
  - error treatment
  - `FileInfo` class/struct
```cpp
/// This enumeration lists all the supported languages.
enum lang_type_e : std::uint8_t {
  C = 0,  //!< C language
  CPP,    //!< C++ language
  H,      //!< C/C++ header
  HPP,    //!< C++ header
  UNDEF,  //!< Undefined type.
};
/// Integer type for counting lines.
using count_t = unsigned long;
/// Stores the file information we are collecting.
class FileInfo {
  std::string filename;      //!< the filename.
  lang_type_e type{ CPP };   //!< the language type.
  count_t n_blank{ 0 };      //!< # of blank lines in the file.
  count_t n_comments{ 0 };   //!< # of comment lines.
  count_t n_docblocks{ 0 };  //!< # of comment lines inside a doc block.
  count_t n_loc{ 0 };        //!< # lines of code.
  count_t n_lines{ 0 };      //!< # of lines.
};
```
# architecture
  - struct to store cli information → pass into back-end
  - struct to store file information ← pass into front-end
  - `iostream, iomanip, string, vector, filesystem`
## features
  - cli-parser: set of functions to parse and treat cli errors
  - interface: set of functions to display interface
  - fileinfo-processing: set of functions to process consolidated fileinfo into percentages and sums
# components
  - `validate_cli`/`parse_arguments`
  - `collect_valid_files` → list of valid files
  - `print_error`
  - `sort_file_info`
  - `print_table`
# questions and to be researched
  - `filesystem`
  - `iomanip`
  - manual implementation (`man` & `tcolor`)
# roadmap
  - [ ] help & interface
    - [x] research about `man` & `tcolor`
    - [x] `print_help()`
    - [x] sorting algorithm
    - [x] research `iomanip` for table formatting
    - [x] formatted output table (take in mind the filename adaptation)
    - [ ] test on main
  - [ ] argument parsing
    - [x] argc and argv treating
    - [x] flag implementation
    - [ ] testing
  - [x] filesystem parsing
    - [x] research about `filesystem`
    - [x] isolate files and dirs to be searched
    - [x] recursive searching (`-r`)
  - [x] error treatment
    - [x] `ErrorType` enum (does not exist, not supported, empty directory, etc)
    - [x] error treatment implementation
