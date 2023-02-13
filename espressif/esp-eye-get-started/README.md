# Get started with ESP-EYE

This brief tutorial shows how to start with the first example of ESP-EYE. The required documentation is already all on the espressif esp-who repo but it's somewhat scattered around. 

These steps are tested on a Windows 11 machine. You need to have [git](https://git-scm.com/download/win) installed. 


## Install ESP-IDF

To install ESP-IDF we will use vscode extension. 
First install [vscode](https://code.visualstudio.com/). Open vscode and go to `Extensions` by clicking `CTRL-SHIFT-x` or clicking on the icon on the left side of the screen.
Search for the plug-in "Espressif IDF" and install it. 
To configure Espressif IDF, open the command palette (`CTRL-SHIFT-p`) and write "ESP-IDF: Configure ESP-IDF extension option.". Go through the Express configuration. For more detail please refer to [Espressif plug-in installation guide](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/install.md).

## Download ESP-WHO

Open a terminal and clone the esp-who repo
`git clone --recursive https://github.com/espressif/esp-who.git`
It may take a while. For more detail please refer to [Espressif esp-who repo](https://github.com/espressif/esp-who).


## Compile and flash the example

Go to the folder `esp-who/examples/human_face_recognition/` right click and select `Open in terminal`. In the terminal write `code .` in order to open the folder in vscode. 
Open the command palette `CTRL-SHIP-p` and start writing "ESP-IDF: Set Espressif device target". Hit enter and click on the path which appears below the command palette. 

Open the command palette again and start writing "ESP-IDF: SDK configuration editor (menuconfig)". Once the menuconfig opens, search for "esp-who" in the research field and make sure the `Camera configuration` dropdown menu is set to `ESP-EYE Devkit`.
![esp eye menuconfig](../../img/esp-eye-menuconfig.png)



