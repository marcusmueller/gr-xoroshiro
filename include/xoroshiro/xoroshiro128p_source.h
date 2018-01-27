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


#ifndef INCLUDED_XOROSHIRO_XOROSHIRO128P_SOURCE_H
#define INCLUDED_XOROSHIRO_XOROSHIRO128P_SOURCE_H

#include <xoroshiro/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace xoroshiro {

    /*!
     * \brief A XOROSHIRO128+-based Gaussian Noise source
     * It uses the power of the Central Limit Theorem.
     * Why? Because I can, and to show that our fastnoise source is bad.
     * \ingroup xoroshiro
     *
     */
    class XOROSHIRO_API xoroshiro128p_source : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<xoroshiro128p_source> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of xoroshiro::xoroshiro128p_source.
       *
       * To avoid accidental use of raw pointers, xoroshiro::xoroshiro128p_source's
       * constructor is in a private implementation
       * class. xoroshiro::xoroshiro128p_source::make is the public interface for
       * creating new instances.
       */
      static sptr make(uint64_t seed = 1, uint32_t iterations = 64);
    };

  } // namespace xoroshiro
} // namespace gr

#endif /* INCLUDED_XOROSHIRO_XOROSHIRO128P_SOURCE_H */

