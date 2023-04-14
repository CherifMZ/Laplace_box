#include <iostream>
#include <vector>

int main() {
  // Create a sample 2D image
  std::vector<int> image = {1, 0, 2, 1, 0, 1, 3, 1, 0, 2, 1, 1};
  int height = 3;
  int width = 4;

  // Define the Laplacian filter kernel
  std::vector<int> kernel = {-1, -1, -1, -1, 8, -1, -1, -1, -1};

  // Pad the image with zeros at all faces
  int padding = 1;
  int padded_height = height + 2 * padding;
  int padded_width = width + 2 * padding;
  std::vector<int> image_padded(padded_height * padded_width);
  for (int i = padding; i < height + padding; i++) {
    for (int j = padding; j < width + padding; j++) {
      image_padded[i * padded_width + j] =
          image[(i - padding) * width + (j - padding)];
    }
  }

  // Apply the Laplacian filter to the image
  std::vector<int> filtered(height * width);
  for (int i = padding; i < height + padding; i++) {
    for (int j = padding; j < width + padding; j++) {
      int sum = 0;
      for (int k = -padding; k <= padding; k++) {
        for (int l = -padding; l <= padding; l++) {
          sum += kernel[(k + padding) * (2 * padding + 1) + l + padding] *
                 image_padded[(i + k) * padded_width + (j + l)];
        }
      }
      filtered[(i - padding) * width + (j - padding)] = sum;
    }
  }

  std::cout << "Padded image:\n";
  for (int i = 0; i < padded_height; i++) {
    for (int j = 0; j < padded_width; j++) {
      std::cout << image_padded[i * padded_width + j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "Original image:\n";
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << image[i * width + j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "Filtered image:\n";
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << filtered[i * width + j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}