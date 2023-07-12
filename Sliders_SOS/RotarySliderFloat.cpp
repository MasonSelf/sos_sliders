//
// Created by Mason Self on 7/8/23.
//

#include "RotarySliderFloat.h"

SOSRotaryFloatSlider::SOSRotaryFloatSlider(IAudioProcessor& p, const juce::Identifier& paramID ,int paramIndex, juce::Colour _fill, juce::Colour _outline, juce::Colour _pointer, const juce::String& suffix)
: audioProcessor(p), feel(_fill, _outline, _pointer)
{
    sliderAttachment =
            std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>
                    (audioProcessor.GetAPVTS(), paramID.toString(), *this);

    auto param = std::make_unique<juce::AudioParameterFloat*>(dynamic_cast<juce::AudioParameterFloat*>(audioProcessor.GetParams().getUnchecked(paramIndex)));

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
SOSRotaryFloatSlider::~SOSRotaryFloatSlider()
{
    setLookAndFeel(nullptr);
}