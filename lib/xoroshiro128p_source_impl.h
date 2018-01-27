/* -*- c++ -*- */
/* 
 * Copyright 2018 Marcus Müller.
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

#ifndef INCLUDED_XOROSHIRO_XOROSHIRO128P_SOURCE_IMPL_H
#define INCLUDED_XOROSHIRO_XOROSHIRO128P_SOURCE_IMPL_H

#include <xoroshiro/xoroshiro128p_source.h>

namespace gr {
  namespace xoroshiro {

    class xoroshiro128p_source_impl : public xoroshiro128p_source
    {
     private:
      uint64_t state[2];
      uint32_t iterations;
     public:
      xoroshiro128p_source_impl(uint64_t seed, uint32_t iterations);
      ~xoroshiro128p_source_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace xoroshiro
} // namespace gr

#endif /* INCLUDED_XOROSHIRO_XOROSHIRO128P_SOURCE_IMPL_H */

