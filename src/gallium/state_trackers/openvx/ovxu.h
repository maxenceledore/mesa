#ifndef _OVXU__H
#define _OVXU__H

#include "VX/vx.h"

extern vx_status
ovxu_ColorConvert(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_ChannelExtract(vx_context context, vx_image input, vx_enum channel, vx_image output);

extern vx_status
ovxu_ChannelCombine(vx_context context, vx_image plane0, vx_image plane1, vx_image plane2, vx_image plane3, vx_image output);

extern vx_status
ovxu_Sobel3x3(vx_context context, vx_image input, vx_image output_x, vx_image output_y);

extern vx_status
ovxu_Magnitude(vx_context context, vx_image grad_x, vx_image grad_y, vx_image output);

extern vx_status
ovxu_Phase(vx_context context, vx_image grad_x, vx_image grad_y, vx_image output);

extern vx_status
ovxu_ScaleImage(vx_context context, vx_image src, vx_image dst, vx_enum type);

extern vx_status
ovxu_TableLookup(vx_context context, vx_image input, vx_lut lut, vx_image output);

extern vx_status
ovxu_Histogram(vx_context context, vx_image input, vx_distribution distribution);

extern vx_status
ovxu_EqualizeHist(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_AbsDiff(vx_context context, vx_image in1, vx_image in2, vx_image out);

extern vx_status
ovxu_MeanStdDev(vx_context context, vx_image input, vx_float32 *mean, vx_float32 *stddev);

extern vx_status
ovxu_Threshold(vx_context context, vx_image input, vx_threshold thresh, vx_image output);

extern vx_status
ovxu_IntegralImage(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_Erode3x3(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_Dilate3x3(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_Median3x3(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_Box3x3(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_Gaussian3x3(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_Convolve(vx_context context, vx_image input, vx_convolution matrix, vx_image output);

extern vx_status
ovxu_GaussianPyramid(vx_context context, vx_image input, vx_pyramid gaussian);

extern vx_status
ovxu_AccumulateImage(vx_context context, vx_image input, vx_image accum);

extern vx_status
ovxu_AccumulateWeightedImage(vx_context context, vx_image input, vx_scalar scale, vx_image accum);

extern vx_status
ovxu_AccumulateSquareImage(vx_context context, vx_image input, vx_scalar shift, vx_image accum);

extern vx_status
ovxu_MinMaxLoc(vx_context context, vx_image input,
               vx_scalar minVal, vx_scalar maxVal,
               vx_array minLoc, vx_array maxLoc,
               vx_scalar minCount, vx_scalar maxCount);
 
extern vx_status
ovxu_ConvertDepth(vx_context context, vx_image input, vx_image output, vx_enum policy, vx_int32 shift);

extern vx_status
ovxu_CannyEdgeDetector(vx_context context, vx_image input, vx_threshold hyst,
                       vx_int32 gradient_size, vx_enum norm_type,
                       vx_image output);
 
extern vx_status
ovxu_HalfScaleGaussian(vx_context context, vx_image input, vx_image output, vx_int32 kernel_size);

extern vx_status
ovxu_And(vx_context context, vx_image in1, vx_image in2, vx_image out);

extern vx_status
ovxu_Or(vx_context context, vx_image in1, vx_image in2, vx_image out);

extern vx_status
ovxu_Xor(vx_context context, vx_image in1, vx_image in2, vx_image out);

extern vx_status
ovxu_Not(vx_context context, vx_image input, vx_image output);

extern vx_status
ovxu_Multiply(vx_context context, vx_image in1, vx_image in2, vx_float32 scale, vx_enum overflow_policy, vx_enum rounding_policy, vx_image out);

extern vx_status
ovxu_Add(vx_context context, vx_image in1, vx_image in2, vx_enum policy, vx_image out);

extern vx_status
ovxu_Subtract(vx_context context, vx_image in1, vx_image in2, vx_enum policy, vx_image out);

extern vx_status
ovxu_WarpAffine(vx_context context, vx_image input, vx_matrix matrix, vx_enum type, vx_image output);

extern vx_status
ovxu_WarpPerspective(vx_context context, vx_image input, vx_matrix matrix, vx_enum type, vx_image output);

extern vx_status
ovxu_HarrisCorners(vx_context context,
                   vx_image input,
                   vx_scalar strength_thresh,
                   vx_scalar min_distance,
                   vx_scalar sensitivity,
                   vx_int32 gradient_size,
                   vx_int32 block_size,
                   vx_array corners,
                   vx_scalar num_corners);

extern vx_status
ovxu_FastCorners(vx_context context, vx_image input, vx_scalar strength_thresh, vx_bool nonmax_suppression, vx_array corners, vx_scalar num_corners);

extern vx_status
ovxu_OpticalFlowPyrLK(vx_context context,
                      vx_pyramid old_images,
                      vx_pyramid new_images,
                      vx_array old_points,
                      vx_array new_points_estimates,
                      vx_array new_points,
                      vx_enum termination,
                      vx_scalar epsilon,
                      vx_scalar num_iterations,
                      vx_scalar use_initial_estimate,
                      vx_size window_dimension);
 
extern vx_status
ovxu_Remap(vx_context context,
           vx_image input,
           vx_remap table,
           vx_enum policy,
           vx_image output);

#endif /* _OVXU__H */