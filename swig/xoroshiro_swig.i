/* -*- c++ -*- */

#define XOROSHIRO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "xoroshiro_swig_doc.i"

%{
#include "xoroshiro/xoroshiro128p_source.h"
%}


%include "xoroshiro/xoroshiro128p_source.h"
GR_SWIG_BLOCK_MAGIC2(xoroshiro, xoroshiro128p_source);
