# XML-Parser
Command line interface for parsing and editing XML files

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Documentation](#documentation)

## Installation
1. [Clone](https://help.github.com/articles/cloning-a-repository/) this repository.
2. Navigate to **cmake-build-debug** directory
3. Execute **XML_Parser**

```````````
$ git clone https://github.com/VladimirAnaniev/XML-Parser.git
$ cd XML_Parser/cmake-build-debug
$ ./XML_Parser
```````````

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

#### Editing
``set [id] [key] [value]``
- Sets the **[key]** argument of the element with **[id]** to **[value]**.
If **[key]** exists, value gets changed, else a new pair is created.

``delete [id] [key]``
- Deletes the **[key]** argument of the element with **[id]**.

#### Outputting
``print``
- Outputs the xml file as a formatted string on the console.

``child [id] [n]``
- Outputs the **n**-th child of the element with **[id]**.

``children [id]``
- Outputs all the children of the element with **[id]**.

``text [id]``
- Outputs the text of the element with **[id]**.

``select [id] [key]``
- Outputs the value of the **[key]** argument of the element with **[id]**

## Documentation
TODO