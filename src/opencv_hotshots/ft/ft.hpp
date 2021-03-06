#ifndef _FT_FT_HPP_
#define _FT_FT_HPP_
#include "opencv_hotshots/ft/ft_data.hpp"
#include "opencv_hotshots/ft/patch_model.hpp"
#include "opencv_hotshots/ft/shape_model.hpp"
#include "opencv_hotshots/ft/face_detector.hpp"
#include "opencv_hotshots/ft/face_tracker.hpp"
//==============================================================================
template <class T> 
T load_ft(const char* fname){
  T x; FileStorage f(fname,FileStorage::READ);
  f["ft object"] >> x; f.release(); return x;
}
//==============================================================================
template<class T>
void save_ft(const char* fname,const T& x){
  FileStorage f(fname,FileStorage::WRITE);
  f << "ft object" << x; f.release();
}
//==============================================================================
template<class T>
void 
write(FileStorage& fs, 
      const string&, 
      const T& x)
{
  x.write(fs);
}
//==============================================================================
template<class T>
void 
read(const FileNode& node, 
     T& x,
     const T& d)
{
  if(node.empty())x = d; else x.read(node);
}
//==============================================================================
#endif
