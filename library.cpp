#include "library.h"

#include <iostream>
#include <juce_core/juce_core.h>
#include <juce_audio_formats/juce_audio_formats.h>

void hello() {
    juce::String hello = "Hello, World!";
    DBG (hello);
}
