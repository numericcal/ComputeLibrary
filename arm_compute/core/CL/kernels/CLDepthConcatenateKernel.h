/*
 * Copyright (c) 2017 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __ARM_COMPUTE_CLDEPTHCONCATENATEKERNEL_H__
#define __ARM_COMPUTE_CLDEPTHCONCATENATEKERNEL_H__

#include "arm_compute/core/CL/ICLKernel.h"
#include "arm_compute/core/Types.h"

namespace arm_compute
{
class ICLTensor;

/** Interface for the depth concatenate kernel.
 *  The input tensor will be concatenated into the output tensor.
 */
class CLDepthConcatenateKernel : public ICLKernel
{
public:
    /** Default constructor */
    CLDepthConcatenateKernel();
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    CLDepthConcatenateKernel(const CLDepthConcatenateKernel &) = delete;
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    CLDepthConcatenateKernel &operator=(const CLDepthConcatenateKernel &) = delete;
    /** Allow instances of this class to be moved */
    CLDepthConcatenateKernel(CLDepthConcatenateKernel &&) = default;
    /** Allow instances of this class to be moved */
    CLDepthConcatenateKernel &operator=(CLDepthConcatenateKernel &&) = default;
    /** Default destructor */
    ~CLDepthConcatenateKernel() = default;
    /** Initialise the kernel's inputs and output
     *
     * @param[in]     input        Input tensor. Data types supported: F32.
     * @param[in]     depth_offset The offset on the Z axis.
     * @param[in,out] output       Output tensor. Data types supported: F32.
     *
     * @note: The output tensor's low two dimensions can't be smaller than the input one's.
     * @note: The gaps between the two lowest dimensions of input and output need to be divisible by 2.
     *
     */
    void configure(const ICLTensor *input, unsigned int depth_offset, ICLTensor *output);

    // Inherited methods overridden:
    void run(const Window &window, cl::CommandQueue &queue) override;
    BorderSize border_size() const override;

private:
    const ICLTensor *_input;
    ICLTensor       *_output;
    int              _top_bottom;
    int              _left_right;
};
}
#endif /* __ARM_COMPUTE_CLDEPTHCONCATENATEKERNEL_H__ */
