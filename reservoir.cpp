#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

double get_east_storage(std::string date) {
  
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

  std::string junk;
  getline(fin, junk); // read one line from the file

  std::string TSVdate;
  double eastSt;
  
  while(fin >> TSVdate >> eastSt) {
    if (date == TSVdate) {
      return eastSt;
    }
    
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, ignoring the remaining columns 
  }
  
  fin.close();
  return 0;
}



double get_min_east() {

  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

  std::string junk;
  getline(fin, junk);

  std::string TSVdate;
  double eastSt;
  double min_east = INT_MAX;
  
  while(fin >> TSVdate >> eastSt) {
    fin.ignore(INT_MAX, '\n');
    if(eastSt < min_east) {
      min_east = eastSt;
    }
  }
  
  fin.close();
  return min_east;
}



double get_max_east() {

  std::ifstream fin("Current_Reservoir_Levels.tsv");
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  }

  std::string junk;
  getline(fin, junk);

  std::string TSVdate;
  double eastSt;
  double max_east = 0;
  
  while(fin >> TSVdate >> eastSt) {
    fin.ignore(INT_MAX, '\n');
    if(eastSt > max_east) {
      max_east = eastSt;
    }
  }
  
  fin.close();
  return max_east;
}



std::string compare_basins(std::string date) {

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
  
  while(fin >> TSVdate >> eastSt >> eastEl >> westSt >> westEl) { 
    fin.ignore(INT_MAX, '\n');
    if (date == TSVdate) {
      if (eastEl < westEl) {
        return ("West");
      }
      else if (westEl < eastEl) {
        return ("East");
      }
      else if (eastEl == westEl) {
        return ("Equal");
      }
    }
  }
      
  fin.close();
  return 0;
}
