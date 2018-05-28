#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpolyhedron_geometry>;
template xw::xmaterialize<xthree::xpolyhedron_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpolyhedron_geometry>>;
template class xw::xgenerator<xthree::xpolyhedron_geometry>;
template xw::xgenerator<xthree::xpolyhedron_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpolyhedron_geometry>>;