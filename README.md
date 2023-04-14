# Laplace_box

A repository with a simple src folder that contains 3 different and independent files (1D, 2D and 3D). 
The goal is to re-create a simple CPU version of the Laplacian box filter (see definition below). 
In our examples, the input is extended by filling all values beyond the edge with the same value "0" (there are many other modes).

## Definition

The Laplacian box, also known as the Laplacian operator or Laplacian filter, is a mathematical operator used in image processing and computer vision. 
It is a second-order derivative operator, which means it is used to calculate the rate of change of an image in two dimensions.

The Laplacian operator is often used for edge detection, as it highlights areas of rapid change in intensity in an image. The Laplacian box filter is a discrete approximation 
of the Laplacian operator that can be applied to an image to obtain an edge map.

The Laplacian box filter works by computing the second-order derivative of each pixel in an image. This is done by convolving the image with the Laplacian kernel, which is a 
small matrix of coefficients that define the second-order derivative. The Laplacian box filter can be applied to grayscale or color images, and it is commonly used in 
applications such as image sharpening, feature extraction, and object recognition.