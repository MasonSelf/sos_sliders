/*
  ==============================================================================

    RotarySliderFloat.h
    Created: 5 Jul 2023 9:22:09am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "RotarySliderLookAndFeel.h"

class SOSRotaryFloatSlider : public juce::Slider
{
public:
    SOSRotaryFloatSlider(AudioPluginAudioProcessor& p, const juce::Identifier& paramID ,int paramIndex, juce::Colour& _fill, juce::Colour& _outline, juce::Colour& _pointer, const juce::String& suffix)
    : audioProcessor(p), feel(_fill, _outline, _pointer)
    {
        sliderAttachment =
            std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>
            (audioProcessor.apvts, paramID.toString(), *this);

        auto param = std::make_unique<juce::AudioParameterFloat*>(static_cast<juce::AudioParameterFloat*>(audioProcessor.getParameters().getUnchecked(paramIndex)));

        setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        setLookAndFeel(&feel);
        setRange((*param)->range.start, (*param)->range.end, 0.00001);
        setValue((*param)->get());
        setTextBoxStyle(juce::Slider::TextBoxBelow, false, 200, 20);
        setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::black);
        setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::transparentBlack);
        setTextValueSuffix(suffix);
        setNumDecimalPlacesToDisplay(1);
    }
    ~SOSRotaryFloatSlider()
    {
        setLookAndFeel(nullptr);
    }

    AudioPluginAudioProcessor& audioProcessor;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    
private:
    SOSRotarySliderLookAndFeel feel;
};

