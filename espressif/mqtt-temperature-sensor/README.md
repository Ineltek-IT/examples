# MQTT temperature sensor

Simple MQTT temperature sensor IoT node, which waits for the provisioning of WiFi credentials and then sends a temperature measurement every 5 seconds to a broker. It's based on the ESP32-S2-Saola-1.
This example is based on:
* [esp-idf provisioning](https://github.com/espressif/esp-idf/tree/master/examples/provisioning)
* [esp-idf mqtts](https://github.com/espressif/esp-idf/tree/master/examples/protocols/mqtt/ssl)

Please not that it's not a copy and paste solution yet.

## How to use example

### Hardware Required

The code is based on the ESP32-S2-Saola-1 board.

### Application Required

Provisioning applications are available for various platforms. See below

#### Platform : Android

For Android, a provisioning application along with source code is available on GitHub : [esp-idf-provisioning-android](https://github.com/espressif/esp-idf-provisioning-android)

#### Platform : iOS

For iOS, a provisioning application along with source code is available on GitHub : [esp-idf-provisioning-ios](https://github.com/espressif/esp-idf-provisioning-ios)

#### Platform : Linux / Windows / macOS

To provision the device running this example, the `esp_prov.py` script needs to be run (found under `$IDF_PATH/tools/esp_prov`). Make sure to satisfy all the dependencies prior to running the script.

Presently, `esp_prov` supports BLE transport only for Linux platform. For Windows/macOS it falls back to console mode and requires another application (for BLE) through which the communication can take place.

There are various applications, specific to Windows and macOS platform which can be used. The `esp_prov` console will guide you through the provisioning process of locating the correct BLE GATT services and characteristics, the values to write, and input read values.

### Configure the project

TODO

### Build and Flash

Build the project and flash it to the board, then run monitor tool to view serial output:

```
idf.py -p PORT flash monitor
```

(To exit the serial monitor, type ``Ctrl-]``.)

See the Getting Started Guide for full steps to configure and use ESP-IDF to build projects.

## Example Output
TODO

### Wi-Fi Scanning

Provisioning manager also supports providing real-time Wi-Fi scan results (performed on the device) during provisioning. This allows the client side applications to choose the AP for which the device Wi-Fi station is to be configured. Various information about the visible APs is available, like signal strength (RSSI) and security type, etc. Also, the manager now provides capabilities information which can be used by client applications to determine the security type and availability of specific features (like `wifi_scan`).


## Troubleshooting

### Provisioning failed

It is possible that the Wi-Fi credentials provided were incorrect, or the device was not able to establish connection to the network, in which the the `esp_prov` script will notify failure (with reason). Serial monitor log will display the failure along with disconnect reason :

```
E (367015) app: Provisioning failed!
    Reason : Wi-Fi AP password incorrect
    Please reset to factory and retry provisioning
```

Once credentials have been applied, even though wrong credentials were provided, the device will no longer go into provisioning mode on subsequent reboots until NVS is erased (see following section).

### Provisioning does not start

If the serial monitor log shows the following :

```
I (465) app: Already provisioned, starting Wi-Fi STA
```

it means either the device has been provisioned earlier with or without success (e.g. scenario covered in above section), or that the Wi-Fi credentials were already set by some other application flashed previously onto your device. On setting the log level to DEBUG this is clearly evident :

```
D (455) wifi_prov_mgr: Found Wi-Fi SSID     : myssid
D (465) wifi_prov_mgr: Found Wi-Fi Password : m********d
I (465) app: Already provisioned, starting Wi-Fi STA
```

To fix this we simple need to erase the NVS partition from flash. First we need to find out its address and size. This can be seen from the monitor log on the top right after reboot.

```
I (47) boot: Partition Table:
I (50) boot: ## Label            Usage          Type ST Offset   Length
I (58) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (65) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (73) boot:  2 factory          factory app      00 00 00010000 00124f80
I (80) boot: End of partition table
```

Now erase NVS partition by running the following commands :

```
$IDF_PATH/components/esptool_py/esptool/esptool.py erase_region 0x9000 0x6000
```


