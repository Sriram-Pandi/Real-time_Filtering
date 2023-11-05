Name: Sriram Pandi

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Project related information and instructions:

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

What operating system and IDE you used to run and compile your code:

Operating system- Windows
IDE- Microsoft visual studio

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Instructions for running your executables:

The following folders were added-

filter.h - contains all the required header files.
filters.cpp - contains all the relavent functions for various operations.
vidDisplay.cpp - contains the main function where the functions are called.
imgDisplay.cpp - conatains the code to display the live video 

To run the task-1 have the imgDisplay.cpp in a folder. Build it and run the code(after adding the required libraries and their paths) to see the image located at a specified path.

To run all the remaining tasks starting from task-2, have the filter.h, filters.cpp and vidDisplay.cpp files in a folder. 
(after adding the required libraries and their paths) Build and run the code.By pressing the following keys the respective outputs will be visible:

g - greyscale video (Task-3)
h - alternate greyscale video (Task-4)
b - blur video (Task-5)
x - sobelx video (Task-6)
y - sobely video (Task-6)
m - gradient magnitude video (Task-7)
l - blurquantized video (Task-8)
c - cartoon Live video( Task -9)
n - negative video(Another effect Task-10)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Instructions for testing any extensions you completed:

Following the above steps and after running the second folder with vidDisplay.cpp by pressing the below mentioned keys 
respective outputs are displayed.

The following keys are for extensions:
e - color_correction and thresholding ( Extension-1 ) 
w - popart_processing ( Extension-2 )

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Whether you are using any time travel days, and how many:

Utilising one ( 1 ) travel day after one week permission for lately joining the classes. Submitting on 02-04-2023.



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Of course! Let's delve deeper into each step:

---

## **Real-Time Image and Video Processing with OpenCV**
By: Sriram Pandi

### **Description:**
This project, developed using OpenCV, covers a wide range of techniques in real-time image and video processing. It spans from foundational operations like image reading to more complex filters that can be interactively applied to live video streams.

### **Steps:**

1. **Read and Display Image**
   - **File**: `imgDisplay.cpp`
   - **Description**: A simple module that fetches an image from the specified path and renders it on a window.
   - **Features**: 
     - Interactive: User can close the display window by pressing the 'q' key.

2. **Display Live Video**
   - **Description**: Streams live video from the default camera source.
   - **Features**: 
     - Allows users to capture and save specific frames during the live feed.

3. **Convert to Gray Scale**
   - **Description**: Converts a colored image to its grayscale representation.
   - **Technique**: Uses OpenCV's cvtColor function, specifically the COLOR_BGR2HSV transformation, to achieve this.

4. **Alternate Grayscale Conversion**
   - **Description**: A manual approach to grayscale conversion.
   - **Technique**: Calculates grayscale values using a weighted average of the image's RGB channels. The weights are 0.6 for green, 0.2 for red, and 0.2 for blue.

5. **Gaussian Blur**
   - **Description**: Blurs the image to reduce its noise and detail.
   - **Technique**: A 5x5 Gaussian filter, broken down into separable 1x5 vertical and horizontal filters.
   - **Interaction**: Pressing the 'b' key displays the blurred image.

6. **Sobel Filters**
   - **Description**: Detects edges in the image in horizontal and vertical orientations.
   - **Functions**: 
     - `sobel-x`: Detects edges in the horizontal direction.
     - `sobel-y`: Detects edges in the vertical direction.
   - **Interaction**: 'x' key reveals the X Sobel output, and 'y' key reveals the Y Sobel output.

7. **Gradient Magnitude Calculation**
   - **Description**: Calculates the magnitude of gradients in the image, useful for edge detection and other applications.
   - **Technique**: Uses the Euclidean formula, \( I = \sqrt{sx^2 + sy^2} \), to compute the gradient magnitude.

8. **Blur Quantization**
   - **Description**: Blurs the image and then reduces its color depth to a specified number of levels.
   - **Technique**: Bucketing pixel values based on the desired number of quantization levels.
   - **Interaction**: Activated using the 'l' key.

9. **Cartoon Effect**
   - **Description**: Transforms the image to look like a cartoon.
   - **Technique**: Combination of gradient magnitude, blurring, quantization, and thresholding. Pixels with a gradient magnitude larger than a threshold are set to black to mimic inked outlines.
   
10. **Negative Image Effect**
    - **Description**: Inverts the colors of the image.
    - **Technique**: Subtracts each pixel value from 255 (maximum value for an 8-bit image channel).
    - **Interaction**: Activated using the 'n' key.

11. **Color Correction and Thresholding (Extension 1)**
    - **Description**: Aims to enhance the image by adjusting its colors and contrast.
    - **Technique**: Uses gamma correction, switches between color spaces (from BGR to YCrCb and back), and applies binary thresholding. The result is an interesting and unique filter effect.

12. **Pop Art Filter (Extension 2)**
    - **Description**: Aims to mimic the iconic pop art visual style.
    - **Technique**: Manipulates the hue, saturation, and value (HSV) channels of the image, applying distinct transformations based on hue ranges.
    - **Interaction**: Press 'w' to see the pop art effect.

### **Reflection:**
This project served as a comprehensive exploration of image processing techniques using OpenCV. The hands-on experience provided insights into data types, basic C++ syntax, pointer operations, and the intricacies of the OpenCV library.

### **Acknowledgments:**
- The pop art inspiration was derived from [Creating Pop Art using OpenCV and Python](https://www.analytics-link.com/post/2019/07/11/creating-pop-art-using-opencv-and-python).
- OpenAI's ChatGPT provided clarifications and guidance for specific concepts.
- Srinivas Peri, a course-mate, provided collaborative discussions on coding challenges.

---

This detailed description should give a more in-depth understanding of each step and its significance in the project.