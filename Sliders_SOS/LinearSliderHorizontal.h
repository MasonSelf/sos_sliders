/*
  ==============================================================================

    LinearSliderHorizontal.h
    Created: 5 Jul 2023 9:02:10am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "LinearSliderBase.h"

class SOSSliderHorizontal : public SOSLinearSliderBase
{
public:
    SOSSliderHorizontal(IAudioProcessor& p, const juce::Identifier& paramID , int paramIndex, juce::Colour _trackColor, juce::Colour _fillColor, juce::Colour _handleColor);
    void paint(juce::Graphics& g) override;
    float GetHandlePosition();
};
