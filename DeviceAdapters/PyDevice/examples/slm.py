import numpy as np
import os
import tempfile
import matplotlib.pyplot as plt

class SLM:
    """Demo SLM implementation."""

    def __init__(self, width=100, height=100):
        self._width = width
        self._height = height
        self._exposure_ms = 1
        self._image = np.zeros((self._height, self._width), dtype=np.uint8)
        self._number_of_components = 1 # Assuming grayscale image
        self._bytes_per_pixel = 1 # Assuming 8-bit

    def set_SLM_image(self, image):
        #convert list of chars to numpy array
        image = np.array(image, dtype=np.uint8)
        # reshape to 2D
        image = image.reshape(self._height, self._width)
        self._image = image

    def display_SLM_image(self):
        # Here you would add the code to actually display the image on the SLM
        # For the moment, we just write the image to a file in tmp. Make sure we have the correct folder
        # on all platforms

        # Create a temporary directory
        tmpdir = os.path.join(tempfile.gettempdir(), 'SLM')
        os.makedirs(tmpdir, exist_ok=True)

        # Save the image
        filename = os.path.join(tmpdir, 'SLM_image.png')
        plt.imsave(filename, self._image, cmap='gray')

    @property
    def exposure(self):
        return self._exposure_ms

    @exposure.setter
    def exposure(self, value):
        self._exposure_ms = value

    @property
    def width(self):
        return self._width
    
    @width.setter
    def width(self, value):
        self._width = value

    @property
    def height(self):
        return self._height
    
    @height.setter
    def height(self, value):
        self._height = value

    @property
    def number_of_components(self):
        return self._number_of_components

    @property
    def bytes_per_pixel(self):
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