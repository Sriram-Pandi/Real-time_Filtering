# Real-Time Image and Video Filtering with OpenCV

[imgDisplay.cpp](imgDisplay.cpp) opens an image. [vidDisplay.cpp](vidDisplay.cpp) reads the default webcam and applies filters from [filter.cpp](filter.cpp), including blur, Sobel gradients, quantization, and cartoon effects. See the [project report](PRCV_project-1_Report.pdf) for the assignment and outputs.

With a C++ compiler and an OpenCV 4 pkg-config entry:

```bash
c++ imgDisplay.cpp -o imgDisplay $(pkg-config --cflags --libs opencv4)
c++ vidDisplay.cpp filter.cpp -o vidDisplay $(pkg-config --cflags --libs opencv4)
./imgDisplay /path/to/image.jpg
./vidDisplay
```

Use `q` to quit.
