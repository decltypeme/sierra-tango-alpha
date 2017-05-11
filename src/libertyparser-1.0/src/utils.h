#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <string>
#include <iostream>

/// namespace to contain the used utilities
namespace utils {

// ****************************************************************************
// Table
/// class to store tabular data
// ****************************************************************************
class Table {
  int                     _numIndices;
  std::vector<double>     _index1;
  std::vector<double>     _index2;
  std::vector<double>     _index3;
  std::vector<double>     _values;

public:
  Table();
  void                    clear();
  
  bool                    setIndex1(const std::vector<double> &v);
  bool                    setIndex2(const std::vector<double> &v);
  bool                    setIndex3(const std::vector<double> &v);
  bool                    setValues(const std::vector<double> &v);
  bool                    check();

/// Return value for a zero dimensional table
  double                  getValue() const;

/// Return interpolated value for single-dimensional table
  double                  getValue(const double &index1) const;


/// Return interpolated value for a two-dimensional table
  double                  getValue(const double &index1, 
                                   const double &index2) const;

/// Return interpolated value for a three-dimensional table
  double                  getValue(const double &index1, const double &index2,
                                   const double &index3) const;

/// \brief Gets the four table indices used to interpolate values and the 
/// corresponding four table values.
  void                    getTableValues(const double &index1,
                                         const double &index2,
                                         double &index11, double &index12,
                                         double &index21, double &index22,
                                         double &v11, double &v12,
                                         double &v21, double &v22);
  
/// Helper function to print a table
  friend std::ostream& operator << (std::ostream &os, const Table &t);
};

std::ostream& operator << (std::ostream &os, const Table &t);

std::vector<double>       splitMultipleValues(const std::string &s); 
  
} // namespace utils
#endif
