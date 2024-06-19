#pragma once
#include "PyDevice.h"

using PySLMClass = CPyDeviceTemplate<CSLMBase<std::monostate>>;
class CPySLM : public PySLMClass {
public:
    CPySLM(const string& id) : PySLMClass(id) {}
    
    // Set the image to be displayed on the SLM
    int SetImage(unsigned char* pixels) override;
    
    // Set all pixels on the SLM to a specific intensity
    int SetPixelsTo(unsigned char intensity) override;
    
    // Display the image on the SLM
    int DisplayImage() override;

    // Set the exposure time for the SLM
    int SetExposure(double interval_ms) override;

    // Get the exposure time for the SLM
    double GetExposure() override;

    // Get the width of the SLM
    long GetWidth() const override;

    // Get the height of the SLM
    long GetHeight() const override;

    // Get the number of components for the SLM
    long GetNumberOfComponents() const override;

    // Get the bytes per pixel for the SLM
    long GetBytesPerPixel() const override;
};