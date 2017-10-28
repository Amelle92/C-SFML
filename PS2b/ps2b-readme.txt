ps2b-readme.txt

Adam Melle

	My program fully works. It works by utilizing the previously programmed LFSR. It reads in an image and displays it using sfml. Then it passes that image to the transform function and extracts the rgb of each pixel and xor's it against the value returned by the generate function. Once the loop has done that for every pixel it returns the image and displays it, causing it to be completely scrambled. Once the program is exited an output image is created. Then if the output image is run back through the program, it will unscramble the image back to its original state using the extact same steps.
