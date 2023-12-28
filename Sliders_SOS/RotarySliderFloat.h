/*
  ==============================================================================

    RotarySliderFloat.h
    Created: 5 Jul 2023 9:22:09am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "RotarySliderLookAndFeel.h"
#include <sos_IAudioProcessor/sos_IAudioProcessor.h>
#include <juce_audio_processors/juce_audio_processors.h>


class SOSRotaryFloatSlider : public juce::Slider
{
public:
    SOSRotaryFloatSlider(IAudioProcessor& p, const juce::Identifier& paramID ,int paramIndex, juce::Colour _fill, juce::Colour _outline, juce::Colour _pointer, const juce::String& suffix);

    ~SOSRotaryFloatSlider();
    IAudioProcessor& audioProcessor;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    
private:
    SOSRotarySliderLookAndFeel feel;
};

class SOSRotaryFloatImageSlider : public juce::Slider
{
public:
   SOSRotaryFloatImageSlider(IAudioProcessor& p, const juce::Identifier& paramID ,int paramIndex, const juce::String& suffix, const void* imageData, const int imageSize);
    ~SOSRotaryFloatImageSlider();
    IAudioProcessor& audioProcessor;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    
private:
    SOSRotaryImageSliderLookAndFeel feel;
};


