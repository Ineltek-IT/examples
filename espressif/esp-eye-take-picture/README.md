# Take picture with ESP-EYE

In this example the ESP-EYE takes a picture and shows its size. It is the example shown [here](https://github.com/espressif/esp32-camera)


1. Clone esp-camera with `git clone --recursive https://github.com/espressif/esp32-camera.git`
2. Go to `esp32-camera/examples/main`
3. Replace the file `take_picture.c` with the one provided in this folder
4. Compile, Flash & Monitor

You should see an output like

```
I (861945) example:take_picture: Taking picture...
I (891957) example:take_picture: Picture taken! Its size was: 153600 bytes
```
