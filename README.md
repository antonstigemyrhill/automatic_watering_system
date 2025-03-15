How to build an automatic watering system:
=====================================

1. Buy necessary hardwate in: /hardware
2. Connect everything according to: /schematics/watering_system.svg

```shell
# Change directory to example
$ cd platform-raspberrypi/examples/arduino-blink

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Clean build files
$ pio run --target clean
```
