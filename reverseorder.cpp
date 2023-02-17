#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

void reverse_order(std::string date1, std::string date2) {
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

  std::string junk;
  getline(fin, junk);

  std::string TSVdate;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;
  double westEl_arr[365]; 
  std::string dates_arr[365]; 
  int index = 0; 

  while (fin >> TSVdate >> eastSt >> eastEl >> westSt >> westEl) { 
    fin.ignore(INT_MAX, '\n');
    if(TSVdate >= date1 && TSVdate <= date2) {
      dates_arr[index] = TSVdate;
      westEl_arr[index] = westEl;
      index++;
    }
  }

  for (int i = index-1; i >= 0; i--) {
    std::cout << dates_arr[i] << "  " << westEl_arr[i] << std::endl;
  }

  fin.close();
}
