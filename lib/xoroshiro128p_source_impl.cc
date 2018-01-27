/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "xoroshiro128p_source_impl.h"
#include "xoroshiro/xoroshiro-variates.h"

namespace gr {
  namespace xoroshiro {

    xoroshiro128p_source::sptr
    xoroshiro128p_source::make(uint64_t seed, uint32_t iterations)
    {
      return gnuradio::get_initial_sptr
        (new xoroshiro128p_source_impl(seed, iterations));
    }

    /*
     * The private constructor
     */
    xoroshiro128p_source_impl::xoroshiro128p_source_impl(uint64_t seed, uint32_t iterations)
      : gr::sync_block("xoroshiro128p_source",
              gr::io_signature::make(0, 0, 0),
                       gr::io_signature::make(1, 1, sizeof(float))),
      iterations(iterations)
    {
      xoroshiro128p_seed(state, seed);
    }

    /*
     * Our virtual destructor.
     */
    xoroshiro128p_source_impl::~xoroshiro128p_source_impl()
    {
    }

    int
    xoroshiro128p_source_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      float *out = (float*) output_items[0];
      for(int i = 0; i < noutput_items; i++)
        *(out++) = xoroshiro128p_cltf(state, iterations);

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace xoroshiro */
} /* namespace gr */

