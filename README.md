# Hello World Example

This example is designed to demonstrate the absolute basics of using [TensorFlow
Lite for Microcontrollers](https://www.tensorflow.org/lite/microcontrollers).

It includes the full end-to-end workflow of training a model, converting it for
use with TensorFlow Lite for Microcontrollers for running inference on a
microcontroller.

It is based on the book [*TinyML*](https://www.oreilly.com/library/view/tinyml/9781492052036/) by Pete Warden and Danil Situnayake (O'Reilly)]

The model is trained to replicate a `sine` function and generates a pattern of
data to either blink LEDs or control an animation, depending on the capabilities
of the device.

## Deploy to microcontroller boards

The folder stm32F769NI cotains the code and [instructions](stm32F769NI/) to help you build and deploy the sample to the [STM32F769 discovery kit](https://www.st.com/en/evaluation-tools/32f769idiscovery.html)
using [ARM Mbed](https://github.com/ARMmbed/mbed-cli).

## Train your own model

So far you have used an existing trained model to run inference on
microcontrollers. The [model](/model/train_hello_world_model.ipynb) directory contains a Jupyter notebook with the instruction to demonstrate the process of training a 2.5 kB model using TensorFlow and converting it for use with TensorFlow Lite for Microcontrollers.