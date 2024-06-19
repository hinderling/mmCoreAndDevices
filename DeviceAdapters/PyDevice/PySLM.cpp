#include "pch.h"
#include "PySLM.h"

const char* g_Keyword_Width = "Width";
const char* g_Keyword_Height = "Height";
const char* g_Keyword_BytesPerPixel = "BytesPerPixel";
const char* g_Keyword_NumberOfComponents = "NumberOfComponents";
const char* g_Keyword_Exposure = "Exposure";


int CPySLM::ConnectMethods(const PyObj& methods)
{
    _check_(PySLMClass::ConnectMethods(methods));
    read_ = methods.GetDictItem("read");
    return CheckError();
}

int CPySLM::SetImage(unsigned char* pixels) {
    // Assuming pixels is a 1D array representing an image
     PyLock lock;
    return CheckError();
}

int CPySLM::SetPixelsTo(unsigned char intensity) {
    PyLock lock;
    return CheckError();
}

int CPySLM::DisplayImage() {
    PyLock lock;
    return CheckError();
}

int CPySLM::SetExposure(double exp_ms) {
    return SetLongProperty(g_Keyword_Exposure, exp_ms);
}

unsigned CPySLM::GetExposure() const {
    return GetLongProperty(g_Keyword_Exposure);
}

unsigned CPySLM::GetWidth() const {
    return GetLongProperty(g_Keyword_Width);
}

unsigned CPySLM::GetHeight() const {
    return GetLongProperty(g_Keyword_Height);
}

unsigned CPySLM::GetNumberOfComponents() const {
    return GetLongProperty(g_Keyword_NumberOfComponents);
}

unsigned CPySLM::GetBytesPerPixel() const {
    return GetLongProperty(g_Keyword_BytesPerPixel);
}


int CPySLM::IsSLMSequenceable(bool& isSequenceable) {
    isSequenceable = false;
    return DEVICE_OK;
}

int CPySLM::GetSLMSequenceMaxLength(long& nrEvents) {
    return DEVICE_UNSUPPORTED_COMMAND;
}

int CPySLM::StartSLMSequence() {
    return DEVICE_UNSUPPORTED_COMMAND;
}

int CPySLM::StopSLMSequence() {
    return DEVICE_UNSUPPORTED_COMMAND;
}

int CPySLM::ClearSLMSequence() {
    return DEVICE_UNSUPPORTED_COMMAND;
}

int CPySLM::AddToSLMSequence(unsigned char* pixels) {
    return DEVICE_UNSUPPORTED_COMMAND;
}

int CPySLM::SendSLMSequence() {
    return DEVICE_UNSUPPORTED_COMMAND;
}