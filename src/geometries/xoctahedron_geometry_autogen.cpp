#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xoctahedron_geometry>;
template xw::xmaterialize<xthree::xoctahedron_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xoctahedron_geometry>>;
template class xw::xgenerator<xthree::xoctahedron_geometry>;
template xw::xgenerator<xthree::xoctahedron_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xoctahedron_geometry>>;