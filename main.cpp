#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{

  std::cout << "Task A" << std::endl;
  
  std::cout << "The East Basin storage for 01/01/2018 was " << get_east_storage("01/01/2018") << " billion gallons." << std::endl;
  std::cout << "The East Basin storage for 06/23/2018 was " << get_east_storage("06/23/2018") << " billion gallons." << std::endl;
  std::cout << "The East Basin storage for 12/30/2018 was " << get_east_storage("12/30/2018") << " billion gallons." << std::endl;
  std::cout << std::endl;

  
  std::cout << "Task B" << std::endl;
  
  std::cout << "The minimum East Basin storage value for 2018 was " << get_min_east() << " billion gallons." << std::endl;
  std::cout << "The maximum East Basin storage value for 2018 was " << get_max_east() << " billion gallons." << std::endl;
  std::cout << std::endl;

  
  std::cout << "Task C" << std::endl;
  
  std::cout << "07/06/2018  " << compare_basins("07/06/2018") << std::endl;
  std::cout << "07/28/2018  " << compare_basins("07/28/2018") << std::endl;
  std::cout << "07/31/2018  " << compare_basins("07/31/2018") << std::endl;
  std::cout << std::endl;

  
  std::cout << "Task D" << std::endl;
  
  std::cout << "10/11/2018 - 10/14/2018:" << std::endl;
  reverse_order("10/11/2018", "10/14/2018");
  std::cout << std::endl;
  std::cout << "11/24/2018 - 11/30/2018:" << std::endl;
  reverse_order("11/24/2018", "11/30/2018");
  std::cout << std::endl;
  std::cout << "12/01/2018 - 12/07/2018:" << std::endl;
  reverse_order("12/01/2018", "12/07/2018");

  
  return 0;
}
