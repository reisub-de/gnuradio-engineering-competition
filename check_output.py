from __future__ import print_function

import numpy as np


def readfile(file):
    return np.fromfile(file, np.complex64)

def compare_vv_matrices(A, B):
    # Trim the larger matrix
    rows = min(np.size(A, 0), np.size(B, 0))
    A = A[1:rows]
    B = B[1:rows]

    # Check Jaggedness
    if np.nonzero(np.logical_xor(np.isnan(A), np.isnan(B)))[0].size > 0:
        raise ValueError("Jaggedness error")

    # Remove NaNs
    np.delete(A, np.isnan(A))
    np.delete(B, np.isnan(B))

    # Normalise
    A = A/np.sqrt(np.mean(np.abs(A)**2))
    B = B/np.sqrt(np.mean(np.abs(B)**2))

    # Compute diff
    diff = A - B
    rmsdiff = np.sqrt(np.mean(np.abs(diff)**2))
    maxdiff = np.max(np.abs(diff))

    return rmsdiff, maxdiff

if __name__ == '__main__':
    import sys
    if len(sys.argv) != 3:
        print("Usage: {} file1 file2".format(sys.argv[0]))
        exit(1)

    A = readfile(sys.argv[1])
    B = readfile(sys.argv[2])

    rmsdiff, maxdiff = compare_vv_matrices(A, B)

    if maxdiff > 1e-4:
        print("root-mean-square deviation: {}, max deviation: {}, exceeds error margin".format(rmsdiff, maxdiff), file=sys.stderr)
        sys.exit(1)

    print("max-error ok: {}".format(maxdiff))
