#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcylinder_geometry>;
template xw::xmaterialize<xthree::xcylinder_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcylinder_geometry>>;
template class xw::xgenerator<xthree::xcylinder_geometry>;
template xw::xgenerator<xthree::xcylinder_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcylinder_geometry>>;