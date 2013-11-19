
#include "ovx_graph.h"
#include "ovx_vision_functionc.h"
#include "ovxu.h"

vx_status
ovxu_ColorConvert(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_ColorConvertNode (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_ChannelExtract(vx_context context, vx_image input, vx_enum channel,
                    vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_ChannelExtractNode (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_ChannelCombine(vx_context context, vx_image plane0, vx_image plane1,
                    vx_image plane2, vx_image plane3, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_ChannelCombineNode (g, plane0, plane1, plane2, plane3, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Sobel3x3(vx_context context, vx_image input, vx_image output_x,
              vx_image output_y)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_Sobel3x3Node (g, input, output_x, output_y);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Magnitude(vx_context context, vx_image grad_x, vx_image grad_y,
               vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_MagnitudeNode (g, grad_x, grad_y, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Phase(vx_context context, vx_image grad_x, vx_image grad_y,
           vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_PhaseNode (g, grad_x, grad_y, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_ScaleImage(vx_context context, vx_image src, vx_image dst, vx_enum type)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_ScaleImageNode (g, src, dst, type);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_TableLookup(vx_context context, vx_image input, vx_lut lut,
                 vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_TableLookupNode (g, input, lut, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Histogram(vx_context context, vx_image input,
               vx_distribution distribution)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_HistogramNode (g, input, distribution);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_EqualizeHist(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_EqualizeHistNode (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_AbsDiff(vx_context context, vx_image in1, vx_image in2, vx_image out)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_AbsDiffNode (g, in1, in2, out);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_MeanStdDev(vx_context context, vx_image input, vx_float32 *mean,
                vx_float32 *stddev)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;
  
  /* TODO: create scalars when scalar api implemented*/
  vx_scalar mean_scalar;
  vx_scalar stddev_scalar;

  n = ovx_MeanStdDevNode (g, input, mean_scalar, stddev_scalar);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Threshold(vx_context context, vx_image input, vx_threshold thresh,
               vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_ThresholdNode (g, input, thresh, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_IntegralImage(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_IntegralImageNode (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Erode3x3(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_Erode3x3Node (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Dilate3x3(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_Dilate3x3Node (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Median3x3(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_Median3x3Node (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Box3x3(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_Box3x3Node (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Gaussian3x3(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_Gaussian3x3Node (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Convolve(vx_context context, vx_image input, vx_convolution matrix,
              vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_ConvolveNode (g, input, matrix, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_GaussianPyramid(vx_context context, vx_image input, vx_pyramid gaussian)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_GaussianPyramidNode (g, input, gaussian);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_AccumulateImage(vx_context context, vx_image input, vx_image accum)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_AccumulateImageNode (g, input, accum);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_AccumulateWeightedImage(vx_context context, vx_image input,
                             vx_scalar scale, vx_image accum)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_AccumulateWeightedImageNode (g, scale, accum);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_AccumulateSquareImage(vx_context context, vx_image input,
                           vx_scalar shift, vx_image accum)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_AccumulateSquareImageNode (g, input, shift, accum);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_MinMaxLoc(vx_context context, vx_image input,
               vx_scalar minVal, vx_scalar maxVal,
               vx_array minLoc, vx_array maxLoc,
               vx_scalar minCount, vx_scalar maxCount)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_MinMaxLocNode (g, input, minVal, maxVal, minLoc, maxLoc,
                         minCount, maxCount);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}
 
vx_status
ovxu_ConvertDepth(vx_context context, vx_image input, vx_image output,
                  vx_enum policy, vx_int32 shift)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  /*XXX*/
  vx_scalar shift_scalar = NULL;

  n = ovx_ConvertDepthNode (g, input, output, policy, shift_scalar);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_CannyEdgeDetector(vx_context context, vx_image input, vx_threshold hyst,
                       vx_int32 gradient_size, vx_enum norm_type,
                       vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_CannyEdgeDetectorNode (g, input, hyst, gradient_size, norm_type,
                                 output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}
 
vx_status
ovxu_HalfScaleGaussian(vx_context context, vx_image input, vx_image output,
                       vx_int32 kernel_size)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_HalfScaleGaussianNode (g, input, output, kernel_size);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_And(vx_context context, vx_image in1, vx_image in2, vx_image out)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_AndNode (g, in1, in2, out);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_Or(vx_context context, vx_image in1, vx_image in2, vx_image out)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_OrNode (g, in1, in2, out);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_Xor(vx_context context, vx_image in1, vx_image in2, vx_image out)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_XorNode (g, in1, in2, out);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_Not(vx_context context, vx_image input, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_NotNode (g, input, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_Multiply(vx_context context, vx_image in1, vx_image in2, vx_float32 scale,
              vx_enum overflow_policy, vx_enum rounding_policy, vx_image out)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;
  /* XXX */
  vx_scalar scale_scalar = NULL;

  n = ovx_MultiplyNode (g, in1, in2, scale_scalar, overflow_policy,
                        rounding_policy, out);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}

vx_status
ovxu_Add(vx_context context, vx_image in1, vx_image in2, vx_enum policy, vx_image out)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_AddNode (g, in1, in2, policy, out);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_Subtract(vx_context context, vx_image in1, vx_image in2, vx_enum policy, vx_image out)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_SubtractNode (g, in1, in2, policy, out);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_WarpAffine(vx_context context, vx_image input, vx_matrix matrix, vx_enum type, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_WarpAffineNode (g, input, matrix, type, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_WarpPerspective(vx_context context, vx_image input, vx_matrix matrix,
                     vx_enum type, vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_WarpPerspectiveNode (g, input, matrix, type, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_HarrisCorners(vx_context context,
                   vx_image input,
                   vx_scalar strength_thresh,
                   vx_scalar min_distance,
                   vx_scalar sensitivity,
                   vx_int32 gradient_size,
                   vx_int32 block_size,
                   vx_array corners,
                   vx_scalar num_corners)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_HarrisCornersNode (g, input, strength_thresh, min_distance,
                             sensitivity, gradient_size, block_size,
                             corners, num_corners);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
ovxu_FastCorners(vx_context context, vx_image input,
                 vx_scalar strength_thresh, vx_bool nonmax_suppression,
                 vx_array corners, vx_scalar num_corners)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_FastCornersNode (g, input, strength_thresh, nonmax_suppression,
                           corners, num_corners);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}


vx_status
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
                      vx_size window_dimension)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_OpticalFlowPyrLKNode (g, old_images, new_images, old_points,
                                new_points_estimates, new_points,
                                termination, epsilon, num_iterations,
                                use_initial_estimate, window_dimension);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}
 

vx_status
ovxu_Remap(vx_context context,
           vx_image input,
           vx_remap table,
           vx_enum policy,
           vx_image output)
{
  vx_graph g = ovx_CreateGraph (context);
  vx_node n = NULL;

  n = ovx_RemapNode (g, input, table, policy, output);
  if(n)
    ovx_ProcessGraph (g);

  /* wait ? release ? */
  return VX_SUCCESS;
}
