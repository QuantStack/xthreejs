#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xarray_camera>;
template xw::xmaterialize<xthree::xarray_camera>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xarray_camera>>;
template class xw::xgenerator<xthree::xarray_camera>;
template xw::xgenerator<xthree::xarray_camera>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xarray_camera>>;