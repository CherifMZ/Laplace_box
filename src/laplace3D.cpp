#include <iostream>
#include <vector>

int main() {

  // Create a sample 3D image
  std::vector<int> image = {1, 0, 2, 1, 0, 1, 0, 3, 0, 2, 0, 1, 3, 0, 0,
                            1, 0, 1, 1, 0, 2, 0, 2, 1, 0, 1, 3, 0, 0, 1,
                            1, 0, 2, 1, 0, 1, 0, 3, 0, 2, 0, 1, 3, 0, 0,
                            1, 0, 1, 1, 0, 2, 0, 2, 1, 0, 1, 3, 0, 0, 1};
  int height = 3;
  int width = 4;
  int depth = 5;

  // Define the Laplacian filter kernel
  std::vector<int> kernel = {-1, -1, -1, -1, -1, -1, -1, -1, -1,
                             -1, -1, -1, -1, 26, -1, -1, -1, -1,
                             -1, -1, -1, -1, -1, -1, -1, -1, -1};

  // Pad the image with zeros at all faces
  int padding = 1;
  int padded_height = height + 2 * padding;
  int padded_width = width + 2 * padding;
  int padded_depth = depth + 2 * padding;

  std::vector<int> image_padded(padded_height * padded_width * padded_depth);

  for (int k = padding; k < depth + padding; k++) {
    for (int i = padding; i < height + padding; i++) {
      for (int j = padding; j < width + padding; j++) {
        image_padded[(k * padded_height + i) * padded_width + j] =
            image[((k - padding) * height + i - padding) * width +
                  (j - padding)];
      }
    }
  }

  // Apply the Laplacian filter to the image
  std::vector<int> filtered(height * width * depth);

  for (int k = padding; k < depth + padding; k++) {
    for (int i = padding; i < height + padding; i++) {
      for (int j = padding; j < width + padding; j++) {
        int sum = 0;
        for (int m = -padding; m <= padding; m++) {
          for (int n = -padding; n <= padding; n++) {
            for (int p = -padding; p <= padding; p++) {
              sum +=
                  kernel[((m + padding) * (2 * padding + 1) + (n + padding)) *
                             (2 * padding + 1) +
                         (p + padding)] *
                  image_padded[((k + m) * padded_height + i + n) *
                                   padded_width +
                               (j + p)];
            }
          }
        }
        filtered[((k - padding) * height + i - padding) * width +
                 (j - padding)] = sum;
      }
    }
  }

  std::cout << "Original image:\n";
  for (int k = 0; k < depth; k++) {
    std::cout << "Depth slice " << k << ":\n";
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        std::cout << image[(k * height + i) * width + j] << " ";
      }
      std::cout << "\n";
    }
  }

  std::cout << "Padded image:\n";
  for (int k = 0; k < padded_depth; k++) {
    std::cout << "Depth padded slice " << k << ":\n";
    for (int i = 0; i < padded_height; i++) {
      for (int j = 0; j < padded_width; j++) {
        std::cout << image_padded[(k * padded_height + i) * padded_width + j]
                  << " ";
      }
      std::cout << "\n";
    }
  }

  std::cout << "Filtered image:\n";
  for (int k = 0; k < depth; k++) {
    std::cout << "Depth slice " << k << ":\n";
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        std::cout << filtered[(k * height + i) * width + j] << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}