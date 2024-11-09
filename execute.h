#ifndef EXECUTE_H
#define EXECUTE_H
#include "ALU.h"
#include "decoder.h"
#include "processor.h"

Processor execute(Processor proc, control_flags_t flags);

#endif


