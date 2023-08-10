//
// Created by Mason Self on 7/8/23.
//

#include "LinearSliderHorizontal.h"

DragFillLabelLayer::DragFillLabelLayer(const juce::String& componentName, const juce::String& labelText, juce::Colour _backgroundColor, juce::Colour _textColor, juce::Colour _borderColor, float _textSize, int _fullWidth)
: juce::Label(componentName, labelText), backgroundColor(_backgroundColor), textColor(_textColor), borderColor(_borderColor), textSize(_textSize), fullWidth(_fullWidth)
{
    setInterceptsMouseClicks(false, false);
}

void DragFillLabelLayer::paint(juce::Graphics& g)
{
    g.setColour(backgroundColor);
    g.fillAll();
    g.setColour(borderColor);
    g.drawRect(0, 0, fullWidth, getHeight());
    g.setColour(textColor);
    g.setFont(textSize);
    g.drawText(getText(), 0, 0, fullWidth, getHeight(), juce::Justification::centred, 1);
}


SOSDragFillBox::SOSDragFillBox(IAudioProcessor& p, const juce::Identifier& paramID , int paramIndex, const juce::String& name, juce::Colour emptyColor, juce::Colour fullColor, juce::Colour textColor, juce::Colour borderColor, float textSize, int fullComponentWidth)
: SOSLinearSliderBase(p, paramID, paramIndex),
  emptyLabel("empty label", name, emptyColor, textColor.interpolatedWith(fullColor, 0.35f), borderColor, textSize, fullComponentWidth),
  fillLabel("full label", name, fullColor, textColor, borderColor, textSize, fullComponentWidth)
{
    
    setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    addListener(this);
    addAndMakeVisible(emptyLabel);
    addAndMakeVisible(fillLabel);
    //setInterceptsMouseClicks(true, false);
}

SOSDragFillBox::~SOSDragFillBox()
{
    removeListener(this);
}

void SOSDragFillBox::resized()
{
    emptyLabel.setBounds(0, 0, getWidth(), getHeight());
    ResizeFillLabel();
}

void SOSDragFillBox::sliderValueChanged(juce::Slider*)
{
    ResizeFillLabel();
}

void SOSDragFillBox::ResizeFillLabel()
{
    fillLabel.setBounds(0, 0, static_cast<int>(getValue() * static_cast<float>(getWidth())), getHeight());
}
