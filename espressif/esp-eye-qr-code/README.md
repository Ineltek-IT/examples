# Qrcode reading example

In this examples, after a booting log, the example emits the qr-code read value between two curly brackets followed by a new lines. E.g.
```{www.example.com}\n```

## Notes

Please note that there is a minimum distance at which the camera can focus on the qr code. This also put a limit to the minimum side of the qr code. If the qr code is nearer than 5 to 6 cm, it may be necessary to put an additional lens (crf. reference nr. 1).

In the table below are recorded a few couples of lens distance and qr-code side size.  

| Qr-code side length (cm) | Approx. Lens distance (cm) |
|---|---|
|6.5 | 17 |
|4 | 3| 
|2.5|6|


## References

+ [Minimum lens distance thread](https://electronics.stackexchange.com/questions/458332/shortest-focus-distance-of-ov2640-camera-modules-with-fixed-focus)
+ [Original esp-who example](https://github.com/espressif/esp-who/tree/master/examples/code_recognition)
