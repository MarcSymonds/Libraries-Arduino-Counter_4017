/* Project: 4017 Decade Counter Interfacing.
 * File: Counter_4017.h
 * Description: Interface with a 4017 decade counter.
 *     Uses the DirectIO library.
 *
 * Copyright (C) 2014 Marc Symonds
 * All rights reserved.
 *
 * This software may be used and redistributed, with or without
 * modification, as long as it is understood that this software
 * is provided as-is without any explicit or implied warranties
 * of merchant-ablity or fitness of purpose.
 */

#ifndef Counter_4017_h
#define Counter_4017_h

#include "Arduino.h"
#include "DirectIO.h"

class Counter_4017
{
  public:
    Counter_4017(byte clockPin, byte lastElementDetectPin);

    void clock();
    void clockPrime();
    void clockTrigger();
    void clear();
    boolean onLastElement();

  private:
    DIO_SetPinFPtr _clockPin;
    byte _lastElementDetectPin;
};

#endif
