#include <iostream>
#include <vector>

int main() {
  // Create a sample 1D image
  std::vector<int> image = {1, 0, 0, 1, 1};

  // Define the Laplacian filter kernel
  std::vector<int> kernel = {-1, 2, -1};

  // Pad the image with zeros 
  int padding = kernel.size() / 2;
  std::vector<int> image_padded(image.size() + 2 * padding);
  std::copy(image.begin(), image.end(), image_padded.begin() + padding);

  // Apply the Laplacian filter to the image
  std::vector<int> filtered(image.size());
  for (int i = padding; i < image.size() + padding; i++) {
    int sum = 0;
    for (int j = 0; j < kernel.size(); j++) {
      sum += kernel[j] * image_padded[i - padding + j];
    }
    filtered[i - padding] = sum;
  }

  std::cout << "Original image: ";
  for (auto pixel : image) {
    std::cout << pixel << " ";
  }
  std::cout << std::endl;

  std::cout << "Padded image: ";
  for (auto pixel : image_padded) {
    std::cout << pixel << " ";
  }
  std::cout << std::endl;

  std::cout << "Filtered image: ";
  for (auto pixel : filtered) {
    std::cout << pixel << " ";
  }
  std::cout << std::endl;

  return 0;
}