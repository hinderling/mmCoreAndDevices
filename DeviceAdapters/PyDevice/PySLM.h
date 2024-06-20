#pragma once
#include "PyDevice.h"

using PySLMClass = CPyDeviceTemplate<CSLMBase<std::monostate>>;

class CPySLM : public PySLMClass {
    PyObj set_image_;
    PyObj display_image_;
    PyObj set_pixels_to_;

public:
    CPySLM(const string& id) : PySLMClass(id) {}

    int SetImage(unsigned int * pixels) override {
        return DEVICE_UNSUPPORTED_COMMAND;
    }
    int SetImage(unsigned char* pixels) override;
    int DisplayImage() override;
    int SetPixelsTo(unsigned char intensity) override;
    int SetExposure(double interval_ms) override;
    double GetExposure() override;
    unsigned GetWidth() override {
        return 512;
    }
    unsigned GetHeight() override {
        return 512;
    }
    unsigned GetNumberOfComponents() override {
        return 1;
    }
    unsigned GetBytesPerPixel() override {
        return 1;
    }

    int IsSLMSequenceable(bool& isSequenceable) const override {
        isSequenceable = false;
        return 0;
    }

    int SetPixelsTo(unsigned char red, unsigned char green, unsigned char blue) override {
        return DEVICE_UNSUPPORTED_COMMAND;
    }

    int ConnectMethods(const PyObj& methods) override;



};