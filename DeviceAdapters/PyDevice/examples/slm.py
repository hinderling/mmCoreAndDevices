import numpy as np
import os
import tempfile
from PIL import Image
import matplotlib.pyplot as plt
import pycromanager
from pycromanager import Core


class SLM:
    """Demo SLM implementation."""

    def __init__(self, width=512, height=512):
        self._width = width
        self._height = height
        self._exposure = 1
        self._image = np.zeros((self._height, self._width), dtype=np.uint8)
        self._number_of_components = 1 # Assuming grayscale image
        self._bytes_per_pixel = 1 # Assuming 8-bit
        self._test = 0

    def set_image(self, image):
        #convert list of chars to numpy array
        image = np.frombuffer(image, dtype=np.uint8)
        # reshape to 2D
        image = image.reshape(self._height, self._width)
        pil_img = Image.fromarray(image)
        pil_img.show()
        self._image = image

    def display_image(self):
        # Here you would add the code to actually display the image on the SLM
        # For the moment, we just write the image to a file in tmp. Make sure we have the correct folder
        # on all platforms

        # Create a temporary directory
        tmpdir = os.path.join(tempfile.gettempdir(), 'SLM')
        os.makedirs(tmpdir, exist_ok=True)

        # Save the image
        filename = os.path.join(tmpdir, 'SLM_image.png')
        plt.imsave(filename, self._image, cmap='gray')

    def set_pixels_to(self, value):
        self._image = np.full((self._height, self._width), value, dtype=np.uint8)
        pil_img = Image.fromarray(self._image)
        pil_img.show()


    @property
    def test(self) -> int:
        return self._test

    @test.setter
    def test(self, value):
        core = Core()
        core.log_message("changing test value to " + str(value))
        self._test = value

    @property
    def exposure(self) -> float:
        return self._exposure

    @exposure.setter
    def exposure(self, value):
        self._exposure = value*3

    @property
    def width(self) -> int:
        return self._width

    @property
    def height(self) -> int:
        return self._height

    @property
    def number_of_components(self) -> int:
        return self._number_of_components

    @property
    def bytes_per_pixel(self) -> int:
        return self._bytes_per_pixel

devices = {'slm': SLM()}

if __name__ == "__main__":
    import sys
    import os

    sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from bootstrap import PyDevice

    device = PyDevice(devices['slm'])
    print(device)
    assert device.device_type == 'SLM'