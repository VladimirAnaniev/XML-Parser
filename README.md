# XML-Parser
Command line interface for parsing and editing XML files

## Table of Contents

- [Principles](#principles)
- [Example](#example)
- [Installation](#installation)
- [Usage](#usage)

## Principles
#### Only one parent element
The file should have only one parent and all remaining should be
its children or children of its children..

#### Each element has a unique id
Each element should have an id. If an element doesn't have one, the parser
will generate a random string and use it as an id.
All ids must be unique and duplicates will be treated as
explained in the [example](#example).


## Example
Lets have a file named **`example.txt`** with the following content:
``````
<parent name="Ivan">
    <son id="1" name="Georgi">
        <age>15</age>
    </son>
    <daughter name="Maria">
        <age>14</age>
        <talents number="2">
            <talent id="1">Singing</talent>
            <talent id="2">Dancing</talent>
        </talents>
    </daughter>
    <occupation type="unemployed"/>
</parent>
``````
After opening this file and executing the `print` command the result will be:
``````
<parent id="XtQ*" name="Ivan">
    <son id="1" name="Georgi">
        <age id="ceT*">
            15
        </age>
    </son>
    <daughter id="NJn*" name="Maria">
        <age id="ytg*">
            14
        </age>
        <talents id="niB*" number="2">
            <talent id="1_1">
                Singing
            </talent>
            <talent id="2">
                Dancing
            </talent>
        </talents>
    </daughter>
    <occupation id="mqG*" type="unemployed"/>
</parent>
``````
What you can see is that all elements that had no
ids previously have had one generated for them at
random *(3 random characters, followed by \*)*.

Also, because all ids should be unique, *Maria's singing talent's*
**id** has been changed to **"1_1"**, because *Georgi* already has **id="1"**.


## Installation
You will need [CMake](https://cmake.org/)

1. [Clone](https://help.github.com/articles/cloning-a-repository/) this repository.
2. [Run CMake.](https://cmake.org/runningcmake/)

`````
$ clone https://github.com/VladimirAnaniev/XML-Parser.git
$ cd XML_Parser
$ mkdir build
$ cd build
$ ccmake ..
$ make
$ ./XML_Parser
`````

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
``save``
- Saves the xml file in the same file it was read from.

``save as [File Path]``
- Saves the xml file in a file given as an argument. If no such file exists, it will be created.

#### Editing
``newchild [parentId] [tag] [id]``
- Creates a new element with **[tag]** and **[id]** and puts it as a child of the element with **[parentId]**

``set [id] [key] [value]``
- Sets the **[key]** argument of the element with **[id]** to **[value]**.
If **[key]** exists, value gets changed, else a new pair is created.

``setid [old] [new]``
- Changes the id of the element with id=**[old]** to **[new]**

``delete [id] [key]``
- Deletes the **[key]** argument of the element with **[id]**.

``remove [id]``
- Removes the element with **[id]** from the node tree.

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
