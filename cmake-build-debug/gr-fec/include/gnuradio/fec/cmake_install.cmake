# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "fec_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/fec" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/generic_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/generic_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/tagged_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/tagged_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/async_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/async_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/cc_common.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/cc_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/cc_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ccsds_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/dummy_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/dummy_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/repetition_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/repetition_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/decode_ccsds_27_fb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/encode_ccsds_27_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/rs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/viterbi.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ber_bf.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/conv_bit_corr_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/puncture_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/puncture_ff.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/depuncture_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/cldpc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/alist.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/gf2mat.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/gf2vec.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/awgn_bp.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ldpc_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ldpc_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/polar_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/polar_decoder_sc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/polar_common.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/polar_decoder_sc_list.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/polar_decoder_common.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/polar_encoder_systematic.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/polar_decoder_sc_systematic.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/maxstar.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/tpc_common.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/tpc_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/tpc_encoder.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "fec_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/fec" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/fec_mtrx.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ldpc_H_matrix.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ldpc_G_matrix.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ldpc_bit_flip_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ldpc_par_mtrx_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/include/gnuradio/fec/ldpc_gen_mtrx_encoder.h"
    )
endif()

