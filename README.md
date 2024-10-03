# Description
> This project use a graphical library (minilibX) implemented for Linux system. It will have unexpected behaviour if
> is executed in other OS.

This project is a wireframe model that read a file with information about X,Y,Z coordinates of the points
of an image (width position X coor, row line Y coor and number Z coor), processe it and display 
the image defined in the file.

A file is considered wrong file if not all the lines have the same number of elements (considering element
any item separated by spaces). Some elements has info about the color of the point in hex format, for example
1xffff.

To check the results `make` the project and run command ` ./fdf <map_name>`, where ` map_name` is the 
name of a .fdf file. You have some samples of .fdf files in **test_maps** folder.
