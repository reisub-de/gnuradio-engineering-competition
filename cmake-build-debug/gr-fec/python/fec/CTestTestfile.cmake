# CMake generated Testfile for 
# Source directory: /home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec
# Build directory: /home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(qa_ber_bf "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_ber_bf_test.sh")
add_test(qa_depuncture "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_depuncture_test.sh")
add_test(qa_ecc_ccsds_27 "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_ecc_ccsds_27_test.sh")
add_test(qa_fecapi_cc "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_fecapi_cc_test.sh")
add_test(qa_fecapi_dummy "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_fecapi_dummy_test.sh")
add_test(qa_fecapi_ldpc "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_fecapi_ldpc_test.sh")
add_test(qa_fecapi_repetition "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_fecapi_repetition_test.sh")
add_test(qa_polar_decoder_sc "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_polar_decoder_sc_test.sh")
add_test(qa_polar_decoder_sc_list "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_polar_decoder_sc_list_test.sh")
add_test(qa_polar_decoder_sc_systematic "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_polar_decoder_sc_systematic_test.sh")
add_test(qa_polar_encoder "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_polar_encoder_test.sh")
add_test(qa_polar_encoder_systematic "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_polar_encoder_systematic_test.sh")
add_test(qa_puncture "/bin/sh" "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/qa_puncture_test.sh")
subdirs("polar")
