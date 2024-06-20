#include "pch.h"
#include "PySLM.h"

const char* g_Keyword_Width_SLM = "Width";
const char* g_Keyword_Height_SLM = "Height";
const char* g_Keyword_BytesPerPixel = "BytesPerPixel";
const char* g_Keyword_NumberOfComponents = "NumberOfComponents";
const char* g_Keyword_Exposure_SLM = "Exposure";


int CPySLM::ConnectMethods(const PyObj& methods) {
    _check_(PySLMClass::ConnectMethods(methods));
    display_image_ = methods.GetDictItem("display_image");
    set_image_ = methods.GetDictItem("set_image");
    set_pixels_to_ = methods.GetDictItem("set_pixels_to");
    return CheckError();
}

int CPySLM::SetImage(unsigned char* pixels) {
    PyLock lock;
    size_t size = 512 * 512;
    PyObject* pyData = PyBytes_FromStringAndSize(reinterpret_cast<const char*>(pixels), size);
    set_image_.Call(pyData);
    return CheckError();
}

int CPySLM::SetPixelsTo(unsigned char intensity) {
    PyLock lock;
    PyObject* pyValue = PyLong_FromUnsignedLong(intensity);
    set_pixels_to_.Call(pyValue);
    return CheckError();
}

int CPySLM::DisplayImage() {
    display_image_.Call();
    return CheckError();
}

int CPySLM::SetExposure(double interval_ms) {
    return SetFloatProperty(g_Keyword_Exposure_SLM, interval_ms);
}

double CPySLM::GetExposure() {
    return GetFloatProperty(g_Keyword_Exposure_SLM);
}


/*
unsigned CPySLM::GetWidth() const {
    return GetUnsignedProperty(g_Keyword_Width_SLM);
}

unsigned CPySLM::GetHeight() const {
    return GetUnsignedProperty(g_Keyword_Height_SLM);
}

unsigned CPySLM::GetNumberOfComponents() const {
    return GetUnsignedProperty(g_Keyword_NumberOfComponents);
}

unsigned CPySLM::GetBytesPerPixel() const {
    return GetUnsignedProperty(g_Keyword_BytesPerPixel);
}

*/