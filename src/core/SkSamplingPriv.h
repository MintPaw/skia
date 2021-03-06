/*
 * Copyright 2020 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkSamplingPriv_DEFINED
#define SkSamplingPriv_DEFINED

#include "include/core/SkSamplingOptions.h"

class SkSamplingPriv {
public:
    // Returns true if the sampling can be ignored when the CTM is identity.
    static bool NoChangeWithIdentityMatrix(const SkSamplingOptions& sampling) {
    #ifdef SK_SUPPORT_LEGACY_SPRITE_IGNORE_HQ
        // Legacy behavior is to ignore sampling if there is identity matrix, even with cubic
        // reampling.
        return true;
    #else
        // If B == 0, the cubic resampler should have no effect for identity matrices
        // https://entropymine.com/imageworsener/bicubic/
        return !sampling.useCubic || sampling.cubic.B == 0;
    #endif
    }
};

#endif
