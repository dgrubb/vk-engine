// File: Input.h
// Author: dgrubb
// Date: 26/05/2020
//
// Low-level interfacing with display output

#ifndef INPUT_H
#define INPUT_H

// Project includes
#include "components/Queue.h"

namespace Input
{
    enum Event
    {
        EXIT_REQUEST = 0
    };

    void PollInputs(Queue<Event>& eq);
}

#endif // INPUT_H
