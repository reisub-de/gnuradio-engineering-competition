#!/usr/bin/python2

import sys, os, re
sys.path.append('/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python')
os.environ['srcdir'] = '/home/zhiwei/WorkSpace/gnuradio/gr-filter/lib'
os.chdir('/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/lib')

if __name__ == '__main__':
    import build_utils
    root, inp = sys.argv[1:3]
    for sig in sys.argv[3:]:
        name = re.sub ('X+', sig, root)
        d = build_utils.standard_impl_dict2(name, sig, 'filter')
        build_utils.expand_template(d, inp)
