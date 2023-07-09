/*
  ==============================================================================

    LinearVerticalSlider.h
    Created: 5 Jul 2023 9:01:39am
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "LinearSliderBase.h"

class SOSSliderVertical : public SOSLinearSliderBase
{
public:
    //constructor without color choices
    SOSSliderVertical(IAudioProcessor& p, const juce::Identifier& paramID, int paramIndex);

    //constructor with color choices
    SOSSliderVertical(IAudioProcessor& p,
                      const juce::Identifier& paramID ,
                      int paramIndex,
                      juce::Colour _trackColor,
                      juce::Colour _fillColor,
                      juce::Colour _handleColor);
    void paint(juce::Graphics& g) override;
    
    float GetHandlePosition(float trackHeight);
};
