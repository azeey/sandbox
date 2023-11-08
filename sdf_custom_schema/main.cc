#include <cassert>
#include <memory>
#include <sdf/Root.hh>
#include <sdf/parser.hh>

void loadExtension(sdf::SDFPtr sdfDesc)
{
  // Customize the schema/description to add a required element in `<model>`
  // from model_ext.sdf
  auto elem = sdfDesc->Root()->GetElementDescription("model");
  assert(elem != nullptr);

  // Read model_ext.sdf
  sdf::initFile("model_ext.sdf", elem);
  std::cout << "Loaded ext:\n";
  elem->PrintDescription("");
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: ./sdf_custom_schema input_file.sdf" << std::endl;
    return -1;
  }

  auto sdfRoot = std::make_shared<sdf::SDF>();
  sdf::init(sdfRoot);
  loadExtension(sdfRoot);

  sdf::readFile(argv[1], sdfRoot);
  sdf::Root root;
  sdf::Errors errors = root.Load(sdfRoot);
  if (errors.empty())
  {
    std::cout << "Successfully loaded file\n"
              << root.Element()->ToString("") << std::endl;
  }
  else
  {
    std::cout << "Error while loading file:\n" << errors << std::endl;
  }
}
