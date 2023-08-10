/*
  ==============================================================================

    LinearSliderDragFillBox.h
    Created: 9 August 2023
    Author:  Mason Self

  ==============================================================================
*/

#pragma once
#include "LinearSliderBase.h"

class DragFillLabelLayer : public juce::Label
{
public:
    DragFillLabelLayer(const juce::String& componentName, const juce::String& labelText, juce::Colour _backgroundColor, juce::Colour _textColor, juce::Colour _borderColor, float _textSize, int _fullWidth);
    void paint(juce::Graphics& g) override;
private:
    juce::Colour backgroundColor;
    juce::Colour textColor;
    juce::Colour borderColor;
    const float textSize;
    const int fullWidth;
};


class SOSDragFillBox : public SOSLinearSliderBase, juce::Slider::Listener
{
public:
    SOSDragFillBox(IAudioProcessor& p, const juce::Identifier& paramID , int paramIndex, const juce::String& name, juce::Colour emptyColor, juce::Colour fullColor, juce::Colour textColor, juce::Colour borderColor, float textSize, int fullComponentWidth);
    ~SOSDragFillBox();

    void resized() override;
    void sliderValueChanged(juce::Slider*) override;

private:
    void ResizeFillLabel();
    
    DragFillLabelLayer emptyLabel;
    DragFillLabelLayer fillLabel;
};
