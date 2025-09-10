#include <chrono>
#include <sdf/Root.hh>
#include <thread>
#include <tinyxml2.h>

#include <new>
#include <atomic>

std::atomic<long long> allocated_memory_bytes = 0;

void* operator new(std::size_t size) {
    allocated_memory_bytes += size;
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    // You'd need to track allocated sizes to accurately decrement here
    // For simplicity, this example just frees
    free(ptr);
}
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: ./sdf_custom_schema input_file.sdf" << std::endl;
    return -1;
  }

// ... later, to get usage ...
  auto init_memory = allocated_memory_bytes.load();
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
  auto final_memory = allocated_memory_bytes.load();
  std::cout << static_cast<double>(final_memory - init_memory)/1e6 << "MB"<< std::endl;
}
