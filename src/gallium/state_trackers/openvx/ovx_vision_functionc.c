
#include "ovx_vision_functionc.h"
#include "ovx_types.h"

vx_node
ovx_AbsDiffNode(vx_graph graph, vx_image in1, vx_image in2, vx_image out)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_AccumulateImageNode(vx_graph graph, vx_image input, vx_image accum)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_AccumulateImageNode (vx_graph graph, vx_image input, vx_image accum)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_AccumulateSquareImageNode (vx_graph graph, vx_image input, vx_scalar shift, vx_image accum)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_AccumulateWeightedImageNode (vx_graph graph, vx_image input, vx_scalar alpha, vx_image accum)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_AddNode (vx_graph graph, vx_image in1, vx_image in2, vx_enum policy, vx_image out)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_SubtractNode (vx_graph graph, vx_image in1, vx_image in2, vx_enum policy, vx_image out)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_AndNode (vx_graph graph, vx_image in1, vx_image in2, vx_image out)
{
  vx_node n = NULL;

  return n;
}


vx_status
ovx_XorNode (vx_context context, vx_image in1, vx_image in2, vx_image out)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_OrNode (vx_graph graph, vx_image in1, vx_image in2, vx_image out)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_NotNode (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_Box3x3Node (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_CannyEdgeDetectorNode (vx_graph graph, vx_image input, vx_threshold hyst, vx_int32 gradient_size, vx_enum norm_type, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_ChannelCombineNode (vx_graph graph, vx_image plane0, vx_image plane1, vx_image plane2, vx_image plane3, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_ChannelExtractNode (vx_graph graph, vx_image input, vx_enum channel, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_ColorConvertNode (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_ConvertDepthNode (vx_graph graph,
                      vx_image input,
                      vx_image output,
                      vx_enum policy,
                      vx_scalar shift)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_ConvolveNode (vx_graph graph,
                  vx_image input,
                  vx_convolution conv,
                  vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_Dilate3x3Node (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_EqualizeHistNode (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_Erode3x3Node (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_FastCornersNode (vx_graph graph, vx_image input, vx_scalar strength_thresh, vx_bool nonmax_suppression, vx_array corners, vx_scalar num_corners)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_Gaussian3x3Node (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_HarrisCornersNode (vx_graph graph,
                     vx_image input,
                     vx_scalar strength_thresh,
                     vx_scalar min_distance,
                     vx_scalar sensitivity,
                     vx_int32 gradient_size,
                     vx_int32 block_size,
                     vx_array corners,
                     vx_scalar num_corners)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_HistogramNode (vx_graph graph,
                 vx_image input,
                 vx_distribution distribution)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_GaussianPyramidNode (vx_graph graph, vx_image input, vx_pyramid gaussian)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_IntegralImageNode (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_MagnitudeNode (vx_graph graph, vx_image grad_x, vx_image grad_y, vx_image mag)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_MeanStdDevNode (vx_graph graph, vx_image input, vx_scalar mean, vx_scalar stddev)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_Median3x3Node (vx_graph graph, vx_image input, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_MinMaxLocNode (vx_graph graph, vx_image input, vx_scalar minVal, vx_scalar maxVal, vx_array minLoc, vx_array maxLoc, vx_scalar minCount, vx_scalar maxCount)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_OpticalFlowPyrLKNode (vx_graph graph, vx_pyramid old_images, vx_pyramid new_images, vx_array old_points, vx_array new_points_estimates, vx_array new_points, vx_enum termination, vx_scalar epsilon, vx_scalar num_iterations, vx_scalar use_initial_estimate, vx_size window_dimension)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_PhaseNode (vx_graph graph, vx_image grad_x, vx_image grad_y, vx_image orientation)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_MultiplyNode (vx_graph graph, vx_image in1, vx_image in2, vx_scalar scale, vx_enum overflow_policy, vx_enum rounding_policy, vx_image out)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_RemapNode (vx_graph graph, vx_image input, vx_remap table, vx_enum policy, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_HalfScaleGaussianNode (vx_graph graph, vx_image input, vx_image output, vx_int32 kernel_size)
{
  vx_node n = NULL;

  if(kernel_size !=3 && kernel_size !=5)
    /*The input size of the Gaussian filter. Supported values are 3 and 5. */
    return n;

  return n;
}


vx_node
ovx_ScaleImageNode (vx_graph graph, vx_image src, vx_image dst, vx_enum type)
{
  vx_node n = NULL;

  switch (type) {
    case VX_INTERPOLATION_TYPE_NEAREST_NEIGHBOR:
    case VX_INTERPOLATION_TYPE_BILINEAR:
    case VX_INTERPOLATION_TYPE_AREA:
      break;
    default:
      break;
  };

  return n;
}


vx_node
ovx_Sobel3x3Node (vx_graph graph, vx_image input, vx_image output_x, vx_image output_y)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_TableLookupNode (vx_graph graph, vx_image input, vx_lut lut, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_ThresholdNode (vx_graph graph, vx_image input, vx_threshold thresh, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_WarpAffineNode (vx_graph graph, vx_image input, vx_matrix matrix, vx_enum type, vx_image output)
{
  vx_node n = NULL;

  return n;
}


vx_node
ovx_WarpPerspectiveNode (vx_graph graph, vx_image input, vx_matrix matrix, vx_enum type, vx_image output)
{
  vx_node n = NULL;

  return n;
}
