# Required Packages : 
Arch :  
``` 
sudo pacman -S base-devel qtermwidget
```
Debian : 
```
sudo apt-get install build-essential libqtermwidget5-0
```
# Minimal-Terminal
This is just a terminal I made while trying to learn C++, one of my first C++ projects, and I think its really good, heres how to use it : 

You can make your own custom changes by editing the `minimal-term.cpp` file and compiling it by running : 
```
g++ $(pkg-config --cflags --libs Qt5Widgets qtermwidget5) -fPIC -o minimal-term minimal-term.cpp
```
And run it by running : `./minimal-term`
Its just like a TTY in a window, probably shouldn't use it as your main unless you make some tweaks to it
