// #include <mimalloc-new-delete.h>

#include <sdf/Root.hh>
#include <tinyxml2.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: ./sdf_custom_schema input_file.sdf" << std::endl;
    return -1;
  }

  sdf::Root root;
  sdf::Errors errors = root.Load(argv[1]);
  if (errors.empty())
  {
    std::cout << "Successfully loaded file\n";
  }
  else
  {
    std::cout << "Error while loading file:\n" << errors << std::endl;
  }
  // auto xmlDoc = tinyxml2::XMLDocument(true, tinyxml2::COLLAPSE_WHITESPACE);
  // if (tinyxml2::XML_SUCCESS == xmlDoc.LoadFile(argv[1]))
  // {
  //   std::cout << "Successfully loaded file\n";
  // }
  // else
  // {
  //   std::cout << "Error while loading file:\n";
  // }
}
