#ifndef IMAGE_TRANSLATOR_HPP
#define IMAGE_TRANSLATOR_HPP
#include <string>

#include <caffe/caffe.hpp>

namespace aws{//um
class ImageTranslator{
  public:
    ImageTranslator(std::string model_path, std::string weights_path);
    std::string describe_image(float* image_data);


  private:
    const std::string model_path;
    const std::string weights_path;
};
}

#endif
