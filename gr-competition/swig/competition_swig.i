/* -*- c++ -*- */

#define COMPETITION_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "competition_swig_doc.i"

%{
#include "competition/competition.h"
%}


%include "competition/competition.h"
GR_SWIG_BLOCK_MAGIC2(competition, competition);
