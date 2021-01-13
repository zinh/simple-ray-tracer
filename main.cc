#include <iostream>
#include <fstream>
#include "color.h"

using namespace std;

int main(int argc, char** argv) {
  const int image_width = 256;
  const int image_height = 256;

  string filename = "output.ppm";
  if (argc == 2) {
    filename = argv[1];
  }

  ofstream ostrm(filename, ios::out);

  ostrm << "P3" << endl;
  ostrm << image_width << " " << image_height << endl;
  ostrm << 255 << endl;

  for (int row = image_height - 1; row >= 0; row--) {
    cerr << "\rProgress: " << row << ' ' << std::flush;
    for (int col = 0; col < image_width; col++) {
      auto r = double(col) / (image_width - 1);
      auto g = double(row) / (image_height - 1);
      auto b = 0.25;
      color pixel(r, g, b);
      write_color(ostrm, pixel);
    }
  }

  return 0;
}
