/* Project: 4017 Decade Counter Interfacing.
 * File: Counter_4017.cpp
 * Description: Interface with a 4017 decade counter.
 *     Uses the DirectIO library.
 *
 * Copyright (C) 2014 Marc Symonds
 * All rights reserved.
 *
 * This software may be used and redistributed, with or without
 * modification, as long as it is understood that this software
 * is provided as-is without any explicit or implied warranties
 * of merchant-ability or fitness of purpose.
 */

#include "Arduino.h"
#include "Counter_4017.h"
#include "DirectIO.h"

Counter_4017::Counter_4017(byte clockPin, byte lastElementDetectPin)
{
  pinMode(clockPin, OUTPUT);
  pinMode(lastElementDetectPin, INPUT);

  _clockPin = DIO_GetSetPinFunction(clockPin);
  _lastElementDetectPin = lastElementDetectPin;

  clear();
}

void Counter_4017::clock()
{
  _clockPin(false);
  _clockPin(true);
}

void Counter_4017::clockTrigger()
{
  _clockPin(true);
}

void Counter_4017::clockPrime()
{
  _clockPin(false);
}

void Counter_4017::clear()
{
  while (!onLastElement())
    clock();

  while (onLastElement())
    clock();
}

boolean Counter_4017::onLastElement()
{
  return (digitalRead(_lastElementDetectPin) == HIGH ? true : false);
}
