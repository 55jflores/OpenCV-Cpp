# Portfolio_vision
OpenCV C++ application that uses threads to do manipulate images concurrently
<br>
I read in an image and made one thread run the filter function to return a filtered version of the images.
<br>
Another thread ran the edges function to run a canny edge detection filter on the same image.
<br>
The filtered and canny edge images were then saved 
 
# Image I read in

![car1](https://user-images.githubusercontent.com/53010808/135925068-68b63b80-2d0e-4edc-b151-e3eb3eae806a.jpg)

# Filtered image (blue and red color channels were extracted from the original image to make this image)

![filter](https://user-images.githubusercontent.com/53010808/135925198-559f5b44-796a-445f-afff-73208eee9e6c.jpg)

# Canny edge detection image

![edges](https://user-images.githubusercontent.com/53010808/135925224-8ac97024-da68-4eb9-a6d3-beba9fd5ac61.jpg)


![cppfilter](https://user-images.githubusercontent.com/53010808/148854352-ed0e1913-65d0-43f0-8eae-a8b7007d5137.PNG)
