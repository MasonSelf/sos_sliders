/*
  ==============================================================================

    RotarySliderChoice.h
    Created: 5 Jul 2023 9:22:20am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "RotarySliderLookAndFeel.h"

class SOSRotaryChoiceSlider : public juce::Slider
{
public:
    SOSRotaryChoiceSlider(AudioPluginAudioProcessor& p, const juce::Identifier& paramID ,int paramIndex, juce::Colour& _fill, juce::Colour& _outline, juce::Colour& _pointer)
    : audioProcessor(p), feel(_fill, _outline, _pointer)
    {
        sliderAttachment =
            std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>
            (audioProcessor.apvts, paramID.toString(), *this);

        auto param = std::make_unique<juce::AudioParameterChoice*>(static_cast<juce::AudioParameterChoice*>(audioProcessor.getParameters().getUnchecked(paramIndex)));

        setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        setLookAndFeel(&feel);
        setValue((*param)->getIndex());
        setTextBoxStyle(juce::Slider::TextBoxBelow, true, 200, 20);
        setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::black);
        setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::transparentBlack);
        setLookAndFeel(&feel);
        
    }
    ~SOSRotaryChoiceSlider()
    {
        setLookAndFeel(nullptr);
    }

    AudioPluginAudioProcessor& audioProcessor;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
private:
    SOSRotarySliderLookAndFeel feel;
};

