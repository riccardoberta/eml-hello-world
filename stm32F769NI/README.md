# TensorFlow Lite Micro Mbed Project

This folder contains source, header and project files needed to build a single TensorFlow Lite Micro target using
the Mbed command line interface.

## Usage

First of all, you need to install the ARM Mbed CLI following the [setup guide](https://os.mbed.com/docs/mbed-os/v6.3/quick-start/build-with-mbed-cli.html)

To load the dependencies this code requires, run:

```
mbed config root .
mbed deploy
```

TensorFlow requires C++ 11, so you'll need to update your profiles to reflect
this. Here's a short Python command that does that:

```
python -c 'import fileinput, glob;
for filename in glob.glob("mbed-os/tools/profiles/*.json"):
  for line in fileinput.input(filename, inplace=True):
    print line.replace("\"-std=gnu++98\"","\"-std=c++11\", \"-fpermissive\"")'
```

With that setting updated, you should now be able to compile:

```
mbed compile -m auto -t GCC_ARM
```

This should result in a binary at the following path:

```
./BUILD/DISCO_F769NI/GCC_ARM/stm32F769NI.bin
```

To deploy, plug in your STM board and copy the file to it. On MacOS, you can do this with the following command:

```
cp ./BUILD/DISCO_F769NI/GCC_ARM/stm32F769NI.bin /Volumes/DIS_F769NI/
```

Copying the file will initiate the flashing process. Once this is complete, you should see an animation on the device's screen.

In addition to this animation, debug information is logged by the board while the program is running. To view it, establish a serial connection to the board using a baud rate of 9600. On OSX and Linux, the following command should work, replacing /dev/tty.devicename with the name of your device as it appears in /dev:

```
screen /dev/tty.usbmodem14403 9600
```

You will see a lot of output flying past!