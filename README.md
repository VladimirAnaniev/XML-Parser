# XML-Parser
Command line interface for parsing and editing XML files

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Documentation](#documentation)

## Installation
TODO

## Usage
#### Open a file
You can only open one file at a time.

``open [File Path]``
- Opens the file, parses the xml and saves it in memory as a tree of nodes

#### Close a file
You can only close a file if you have opened one.

``close``
- Closes the file without saving changes

#### Saving
Saving a file puts the node tree currently in memory in a file as a formatted xml string. Then the file is closed.

``save``
- Saves the xml file in the same file it was read from.

``save as [File Path]``
- Saves the xml file in a file given as an argument. If no such file exists, it will be created.

#### Other commands
``print``
- Outputs the xml file as a formatted string on the console.

#### Editing the xml
``select [id] [key]``
- Outputs the value of the **[key]** argument of the element with **[id]**

``set [id] [key] [value]``
- Sets the **[key]** argument of the element with **[id]** to **[value]**.
If **[key]** exists, value gets changed, else a new pair is created.

``child [id] [n]``
- Outputs the **n**-th child of the element with **[id]**

## Documentation
TODO